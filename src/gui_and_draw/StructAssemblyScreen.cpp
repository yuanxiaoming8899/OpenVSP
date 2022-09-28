//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//

// StructAssemblyScreen.cpp: implementation of the StructAssemblyScreen class.
//
//////////////////////////////////////////////////////////////////////

#include "StructAssemblyScreen.h"
#include "FeaMeshMgr.h"
#include "StructureMgr.h"
#include "ManageViewScreen.h"
#include "GraphicEngine.h"
#include "Display.h"
#include "Camera.h"
#include "ParmMgr.h"
#include "StlHelper.h"

using namespace vsp;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StructAssemblyScreen::StructAssemblyScreen( ScreenMgr* mgr ) : TabScreen( mgr, 430, 650 + 30, "FEA Assembly", 196 )
{
    m_FLTK_Window->callback( staticCloseCB, this );

    int border = 5;

    Fl_Group* assyTab = AddTab( "Assembly" );
    Fl_Group* assyTabGroup = AddSubGroup( assyTab, border );
    Fl_Group* structTab = AddTab( "Structures" );
    Fl_Group* structTabGroup = AddSubGroup( structTab, border );
    Fl_Group* conTab = AddTab( "Connections" );
    Fl_Group* conTabGroup = AddSubGroup( conTab, border );
    Fl_Group* outputTab = AddTab( "Output" );
    Fl_Group* outputTabGroup = AddSubGroup( outputTab, border );
    Fl_Group* displayTab = AddTab( "Display" );
    Fl_Group* displayTabGroup = AddSubGroup( displayTab, border );

    //=== Create Console Area ===//
    m_ConsoleLayout.SetGroupAndScreen( m_FLTK_Window, this );

    int textheight = 100;

    m_ConsoleLayout.AddY( m_ConsoleLayout.GetRemainY()
                        - textheight                            // 100
                        - 4 * m_ConsoleLayout.GetStdHeight()    // 4 * 20
                        - m_ConsoleLayout.GetGapHeight()        // 6
                        - border );                             // 5

    // 196 passed to TabScreen constructor above is this sum plus an additional border.
    // textheight + 3 * m_ConsoleLayout.GetStdHeight() + m_ConsoleLayout.GetGapHeight() + 2 * border
    // This is for the contents of m_BorderConsoleLayout.

    m_ConsoleLayout.AddX( border );

    m_ConsoleLayout.AddSubGroupLayout( m_BorderConsoleLayout, m_ConsoleLayout.GetRemainX() - border,
                                       m_ConsoleLayout.GetRemainY() - border );

    m_ConsoleDisplay = m_BorderConsoleLayout.AddFlTextDisplay( textheight );
    m_ConsoleBuffer = new Fl_Text_Buffer;
    m_ConsoleDisplay->buffer( m_ConsoleBuffer );
    m_FLTK_Window->resizable( m_ConsoleDisplay );

    m_BorderConsoleLayout.AddYGap();

    m_BorderConsoleLayout.SetButtonWidth( m_BorderConsoleLayout.GetW() );
    m_BorderConsoleLayout.SetInputWidth( m_BorderConsoleLayout.GetW() );

    m_BorderConsoleLayout.AddButton( m_FeaReMeshAllButton, "Re-Mesh All" );
    m_BorderConsoleLayout.AddButton( m_FeaMeshUnmeshedButton, "Mesh Unmeshed" );
    m_BorderConsoleLayout.AddButton( m_FeaExportMeshButton, "Export Mesh" );

    //=== Assembly Tab ===//
    assyTab->show();

    m_AssemblyTabLayout.SetGroupAndScreen( assyTabGroup, this );

    m_AssemblyTabLayout.AddDividerBox( "Assembly Selection" );

    // Pointer for the widths of each column in the browser to support resizing
    // Last column width must be 0
    static int assy_col_widths[] = { 400, 0 }; // widths for each column

    int browser_h = 150;
    m_AssemblySelectBrowser = m_AssemblyTabLayout.AddColResizeBrowser( assy_col_widths, 1, browser_h );
    m_AssemblySelectBrowser->callback( staticScreenCB, this );

    int buttonwidth = m_AssemblyTabLayout.GetButtonWidth();

    m_AssemblyTabLayout.SetChoiceButtonWidth( buttonwidth );
    m_AssemblyTabLayout.SetSliderWidth( ( m_AssemblyTabLayout.GetW() - ( 2 * m_AssemblyTabLayout.GetButtonWidth() ) ) / 2 );

    m_AssemblyTabLayout.SetSameLineFlag( true );
    m_AssemblyTabLayout.SetFitWidthFlag( false );

    m_AssemblyTabLayout.SetButtonWidth( m_AssemblyTabLayout.GetRemainX() / 2 );

    m_AssemblyTabLayout.AddButton( m_AddAssemblyButton, "Add Assembly" );
    m_AssemblyTabLayout.AddButton( m_DelAssemblyButton, "Delete Assembly" );

    m_AssemblyTabLayout.ForceNewLine();
    m_AssemblyTabLayout.AddYGap();

    m_AssemblyTabLayout.SetSameLineFlag( false );
    m_AssemblyTabLayout.SetFitWidthFlag( true );

    m_AssemblyTabLayout.AddInput( m_AssemblyNameInput, "Assembly Name" );


    //=== Structure Tab ===//

    m_StructureTabLayout.SetGroupAndScreen( structTabGroup, this );

    m_StructureTabLayout.AddDividerBox( "Structure Selection" );

    static int struct_col_widths[] = { 172, 151, 86, 0 }; // widths for each column

    m_StructureSelectBrowser = m_StructureTabLayout.AddColResizeBrowser( struct_col_widths, 3, browser_h );
    m_StructureSelectBrowser->callback( staticScreenCB, this );

    m_StructureTabLayout.AddChoice( m_FeaStructureChoice, "Structure" );

    m_StructureTabLayout.SetButtonWidth( m_StructureTabLayout.GetRemainX() / 2 );

    m_StructureTabLayout.SetSameLineFlag( true );
    m_StructureTabLayout.SetFitWidthFlag( false );

    m_StructureTabLayout.AddButton( m_AddFeaStructureButton, "Add Structure" );
    m_StructureTabLayout.AddButton( m_DelFeaStructureButton, "Delete Structure" );

    //=== Connection Tab ===//

    m_ConnectionsTabLayout.SetGroupAndScreen( conTabGroup, this );

    m_ConnectionsTabLayout.AddDividerBox( "Connection Selection" );

    static int con_col_widths[] = { 100, 100, 100, 100, 0 }; // widths for each column

    m_ConnectionSelectBrowser = m_ConnectionsTabLayout.AddColResizeBrowser( con_col_widths, 4, browser_h );
    m_ConnectionSelectBrowser->callback( staticScreenCB, this );

    m_ConnectionsTabLayout.AddChoice( m_ConnectionStartChoice, "Start" );
    m_ConnectionsTabLayout.AddChoice( m_ConnectionEndChoice, "End" );

    m_ConnectionsTabLayout.SetSameLineFlag( true );
    m_ConnectionsTabLayout.SetFitWidthFlag( false );

    m_ConnectionsTabLayout.SetButtonWidth( m_ConnectionsTabLayout.GetRemainX() / 2 );

    m_ConnectionsTabLayout.AddButton( m_AddConnectionButton, "Add Connection" );
    m_ConnectionsTabLayout.AddButton( m_DelConnectionButton, "Delete Connection" );

    //=== Output Tab ===//
    m_OutputTabLayout.SetGroupAndScreen( outputTabGroup, this );

    m_OutputTabLayout.AddDividerBox( "File Export" );

    m_OutputTabLayout.SetFitWidthFlag( false );
    m_OutputTabLayout.SetSameLineFlag( true );

    m_OutputTabLayout.SetInputWidth( m_OutputTabLayout.GetW() - 75 - 55 );

    m_OutputTabLayout.SetButtonWidth( 75 );
    m_OutputTabLayout.AddButton( m_StlFile, ".stl" );
    m_OutputTabLayout.AddOutput( m_StlOutput );
    m_OutputTabLayout.SetButtonWidth( m_OutputTabLayout.GetRemainX() );
    m_OutputTabLayout.AddButton( m_SelectStlFile, "..." );
    m_OutputTabLayout.ForceNewLine();

    m_OutputTabLayout.SetButtonWidth( 75 );
    m_OutputTabLayout.AddButton( m_GmshFile, ".msh" );
    m_OutputTabLayout.AddOutput( m_GmshOutput );
    m_OutputTabLayout.SetButtonWidth( m_OutputTabLayout.GetRemainX() );
    m_OutputTabLayout.AddButton( m_SelectGmshFile, "..." );
    m_OutputTabLayout.ForceNewLine();

    m_OutputTabLayout.AddYGap();

    m_OutputTabLayout.SetButtonWidth( 75 );
    m_OutputTabLayout.AddButton( m_MassFile, "Mass" );
    m_OutputTabLayout.AddOutput( m_MassOutput );
    m_OutputTabLayout.SetButtonWidth( m_OutputTabLayout.GetRemainX() );
    m_OutputTabLayout.AddButton( m_SelectMassFile, "..." );
    m_OutputTabLayout.ForceNewLine();

    m_OutputTabLayout.AddYGap();

    m_OutputTabLayout.SetButtonWidth( 75 );
    m_OutputTabLayout.AddButton( m_NastFile, "Nastran" );
    m_OutputTabLayout.AddOutput( m_NastOutput );
    m_OutputTabLayout.SetButtonWidth( m_OutputTabLayout.GetRemainX() );
    m_OutputTabLayout.AddButton( m_SelectNastFile, "..." );
    m_OutputTabLayout.ForceNewLine();

    m_OutputTabLayout.SetButtonWidth( 75 );
    m_OutputTabLayout.AddButton( m_NkeyFile, "Nkey" );
    m_OutputTabLayout.AddOutput( m_NkeyOutput );
    m_OutputTabLayout.SetButtonWidth( m_OutputTabLayout.GetRemainX() );
    m_OutputTabLayout.AddButton( m_SelectNkeyFile, "..." );
    m_OutputTabLayout.ForceNewLine();

    m_OutputTabLayout.AddYGap();

    m_OutputTabLayout.SetButtonWidth( 75 );
    m_OutputTabLayout.AddButton( m_CalcFile, "Calculix" );
    m_OutputTabLayout.AddOutput( m_CalcOutput );
    m_OutputTabLayout.SetButtonWidth( m_OutputTabLayout.GetRemainX() );
    m_OutputTabLayout.AddButton( m_SelectCalcFile, "..." );
    m_OutputTabLayout.ForceNewLine();

    //=== Display Tab ===//
    m_DisplayTabLayout.SetGroupAndScreen( displayTabGroup, this );

    m_DisplayTabLayout.AddDividerBox( "Display" );

    m_DisplayTabLayout.AddYGap();
    m_DisplayTabLayout.AddButton( m_DrawMeshButton, "Draw Mesh" );
    m_DisplayTabLayout.AddButton( m_ColorElementsButton, "Color Elements" );
    m_DisplayTabLayout.AddButton( m_DrawNodesToggle, "Draw Nodes" );
    m_DisplayTabLayout.AddButton( m_DrawElementOrientVecToggle, "Draw Element Orientation Vectors" );

    m_DisplayTabLayout.AddYGap();

    m_DisplayTabLayout.AddDividerBox( "Intersection Curve Display" );

    m_DisplayTabLayout.SetFitWidthFlag( false );
    m_DisplayTabLayout.SetSameLineFlag( true );

    m_DisplayTabLayout.SetButtonWidth( m_DisplayTabLayout.GetW() / 2 );

    m_DisplayTabLayout.AddYGap();
    m_DisplayTabLayout.AddButton( m_DrawIsect, "Show Intersection Curves");
    m_DisplayTabLayout.AddButton( m_DrawBorder, "Show Border Curves");
    m_DisplayTabLayout.ForceNewLine();
    m_DisplayTabLayout.AddYGap();
    m_DisplayTabLayout.AddButton( m_ShowCurve, "Show Curves");
    m_DisplayTabLayout.AddButton( m_ShowPts, "Show Points");
    m_DisplayTabLayout.ForceNewLine();
    m_DisplayTabLayout.AddYGap();
    m_DisplayTabLayout.AddButton( m_ShowRaw, "Show Raw Curve");
    m_DisplayTabLayout.AddButton( m_ShowBinAdapt, "Show Binary Adapted");
    m_DisplayTabLayout.ForceNewLine();

    m_DisplayTabLayout.SetFitWidthFlag( true );
    m_DisplayTabLayout.SetSameLineFlag( false );
    m_DisplayTabLayout.AddYGap();

    m_DisplayTabLayout.AddDividerBox( "Display Element Sets" );

    m_DrawPartSelectBrowser = m_DisplayTabLayout.AddCheckBrowser( browser_h );
    m_DrawPartSelectBrowser->callback( staticScreenCB, this );

    m_DisplayTabLayout.AddY( 125 );
    m_DisplayTabLayout.AddYGap();

    m_DisplayTabLayout.SetSameLineFlag( true );
    m_DisplayTabLayout.SetFitWidthFlag( false );

    m_DisplayTabLayout.SetButtonWidth( m_DisplayTabLayout.GetW() / 2 );

    m_DisplayTabLayout.AddButton( m_DrawAllButton, "Draw All Elements" );
    m_DisplayTabLayout.AddButton( m_HideAllButton, "Hide All Elements" );
    m_DisplayTabLayout.ForceNewLine();


    m_StructureBrowserIndex = 0;
    m_ConnectionBrowserIndex = 0;

    m_StructureChoiceIndex = 0;

    m_ConnectionStartIndex = 0;
    m_ConnectionEndIndex = 0;

}

StructAssemblyScreen::~StructAssemblyScreen()
{
    m_ConsoleDisplay->buffer( NULL );
    delete m_ConsoleBuffer;
}

void StructAssemblyScreen::CloseCallBack( Fl_Widget *w )
{
    Hide();

    m_ScreenMgr->SetUpdateFlag( true );
}

void StructAssemblyScreen::Show()
{
    m_FLTK_Window->show();

    m_ScreenMgr->SetUpdateFlag( true );
}

bool StructAssemblyScreen::Update()
{
    UpdateAssemblyTab();
    UpdateStructTab();
    UpdateConnectionTab();



    return true;
}

void StructAssemblyScreen::UpdateAssemblyTab()
{
    int scroll_pos = m_AssemblySelectBrowser->position();
    int h_pos = m_AssemblySelectBrowser->hposition();

    m_AssemblySelectBrowser->clear();
    m_AssemblyIDs.clear();

    m_AssemblySelectBrowser->column_char( ':' );
    m_AssemblySelectBrowser->add( "@b@.NAME" );


    vector< FeaAssembly* > assy_vec = StructureMgr.GetFeaAssemblyVec();
    if ( assy_vec.size() > 0 )
    {
        for ( int i = 0; i < (int)assy_vec.size(); i++ )
        {
            string assy_name = assy_vec[i]->GetName();

            char str[256];
            sprintf( str, "%s", assy_name.c_str() );
            m_AssemblySelectBrowser->add( str );

            m_AssemblyIDs.push_back( assy_vec[i]->GetID() );
        }

        if ( StructureMgr.ValidFeaAssemblyInd( StructureMgr.GetCurrAssemblyIndex() ) )
        {
            m_AssemblySelectBrowser->select( StructureMgr.GetCurrAssemblyIndex() + 2 );
        }
    }

    m_AssemblySelectBrowser->position( scroll_pos );
    m_AssemblySelectBrowser->hposition( h_pos );


    if ( StructureMgr.ValidFeaAssemblyInd( StructureMgr.GetCurrAssemblyIndex() ) )
    {
        vector < FeaAssembly * > assyVec = StructureMgr.GetFeaAssemblyVec();
        FeaAssembly *curr_assy = assyVec[ StructureMgr.GetCurrAssemblyIndex() ];

        m_AssemblyNameInput.Update( curr_assy->GetName() );

    }
}

void StructAssemblyScreen::UpdateStructTab()
{
    m_FeaStructureChoice.ClearItems();
    m_StructIDs.clear();

    vector < string > names;

    vector< FeaStructure* > structVec = StructureMgr.GetAllFeaStructs();
    for ( int i = 0; i < (int)structVec.size(); i++ )
    {
        string struct_name = structVec[i]->GetName();

        m_FeaStructureChoice.AddItem( struct_name, i );
        m_StructIDs.push_back( structVec[i]->GetID() );
        names.push_back( struct_name );
    }
    m_FeaStructureChoice.UpdateItems();

    m_FeaStructureChoice.SetVal( m_StructureChoiceIndex );


    //==== Structure Browser ====//
    int scroll_pos = m_StructureSelectBrowser->position();
    int h_pos = m_StructureSelectBrowser->hposition();
    m_StructureSelectBrowser->clear();

    FeaAssembly* curr_assy = StructureMgr.GetFeaAssembly( StructureMgr.GetCurrAssemblyIndex() );

    if ( !curr_assy )
    {
        return;
    }

    m_StructureSelectBrowser->column_char( ':' );
    m_StructureSelectBrowser->add( "@b@.NAME" );

    vector < string > idvec = curr_assy->m_StructIDVec;
    for ( int i = 0; i < idvec.size(); i++ )
    {
        int indx = vector_find_val( m_StructIDs, idvec[i] );

        char str[256];
        sprintf( str, "%s", names[indx].c_str() );

        m_StructureSelectBrowser->add( str );
    }

    m_StructureSelectBrowser->select( m_StructureBrowserIndex + 2 );

    m_StructureSelectBrowser->position( scroll_pos );
    m_StructureSelectBrowser->hposition( h_pos );
}

void StructAssemblyScreen::UpdateConnectionTab()
{
    int scroll_pos = m_ConnectionSelectBrowser->position();
    int h_pos = m_ConnectionSelectBrowser->hposition();

    m_ConnectionSelectBrowser->clear();
    m_ConnectionStartChoice.ClearItems();
    m_ConnectionEndChoice.ClearItems();
    m_FixPtIDs.clear();
    m_FixPtStructIDs.clear();

    FeaAssembly* curr_assy = StructureMgr.GetFeaAssembly( StructureMgr.GetCurrAssemblyIndex() );

    if ( !curr_assy )
    {
        return;
    }

    vector < FeaPart* > allfp;
    vector < string > fpstructids;

    curr_assy->GetAllFixPts( allfp, fpstructids );

    for ( int i = 0; i < allfp.size(); i++ )
    {
        string st_name;

        FeaStructure * fea_struct = StructureMgr.GetFeaStruct( fpstructids[i] );
        if ( fea_struct )
        {
            st_name = fea_struct->GetName();
            st_name += "_";
        }

        FeaPart* fp = allfp[i];
        if ( fp )
        {
            st_name += fp->GetName();

            m_FixPtIDs.push_back( fp->GetID() );
            m_FixPtStructIDs.push_back( fea_struct->GetID() );

            m_ConnectionStartChoice.AddItem( st_name, i );
            m_ConnectionEndChoice.AddItem( st_name, i );
        }
    }
    m_ConnectionStartChoice.UpdateItems();
    m_ConnectionEndChoice.UpdateItems();

    m_ConnectionStartChoice.SetVal( m_ConnectionStartIndex );
    m_ConnectionEndChoice.SetVal( m_ConnectionEndIndex );


    m_ConnectionSelectBrowser->column_char( ':' );
    m_ConnectionSelectBrowser->add( "@b@.START STRUCT:@b@.PT:@b@.END STRUCT:@b@.PT:" );

    vector < FeaConnection* > convec = curr_assy->m_ConnectionVec;
    for ( int i = 0; i < convec.size(); i++ )
    {
        m_ConnectionSelectBrowser->add( convec[i]->MakeLabel().c_str() );
    }

    m_ConnectionSelectBrowser->select( m_ConnectionBrowserIndex + 2 );

    m_ConnectionSelectBrowser->position( scroll_pos );
    m_ConnectionSelectBrowser->hposition( h_pos );
}

void StructAssemblyScreen::AddOutputText( const string &text )
{
    Fl::lock();
    m_ConsoleBuffer->append( text.c_str() );
    m_ConsoleDisplay->insert_position( m_ConsoleDisplay->buffer()->length() );
    m_ConsoleDisplay->show_insert_position();
    Fl::unlock();
}

void StructAssemblyScreen::CallBack( Fl_Widget* w )
{
    assert( m_ScreenMgr );

    Vehicle*  veh = m_ScreenMgr->GetVehiclePtr();

    if ( veh )
    {
    }

    if ( w == m_AssemblySelectBrowser )
    {
        StructureMgr.SetCurrAssemblyIndex( m_AssemblySelectBrowser->value() - 2 );
    }
    else if ( w == m_StructureSelectBrowser )
    {
        m_StructureBrowserIndex = m_StructureSelectBrowser->value() - 2;
    }
    else if ( w == m_ConnectionSelectBrowser )
    {
        m_ConnectionBrowserIndex = m_ConnectionSelectBrowser->value() - 2;
    }

    m_ScreenMgr->SetUpdateFlag( true );
}

#ifdef WIN32
DWORD WINAPI feaassy_thread_fun( LPVOID data )
#else
void * feaassy_thread_fun( void *data )
#endif
{
    FeaMeshMgr.GenerateFeaMesh();

    StructAssemblyScreen *cs = (StructAssemblyScreen *)data;
    if ( cs )
    {
        cs->GetScreenMgr()->SetUpdateFlag( true ); // FeaParts will not be updated when mesh is in progress
    }

    return 0;
}

void StructAssemblyScreen::LaunchFEAMesh()
{
    // Set m_FeaMeshInProgress to ensure m_MonitorProcess does not terminate prematurely
    FeaMeshMgr.SetFeaMeshInProgress( true );

    // Identify which structure to mesh
    FeaMeshMgr.SetFeaMeshStructID( m_AssemblyIDs[ StructureMgr.m_CurrStructIndex() ] );

    m_FeaMeshProcess.StartThread( feaassy_thread_fun, ( void* ) this );

    if ( StructureMgr.ValidTotalFeaStructInd( StructureMgr.m_CurrStructIndex() ) )
    {
        vector < FeaStructure* > structvec = StructureMgr.GetAllFeaStructs();

        structvec[StructureMgr.m_CurrStructIndex()]->GetStructSettingsPtr()->m_DrawMeshFlag = true;
        structvec[StructureMgr.m_CurrStructIndex()]->SetDrawFlag( false );
    }
}

void StructAssemblyScreen::GuiDeviceCallBack( GuiDevice* device )
{
    assert( m_ScreenMgr );

    Vehicle*  veh = m_ScreenMgr->GetVehiclePtr();

    if ( !veh )
    {
        return;
    }

    if ( device == &m_FeaReMeshAllButton )
    {
        LaunchFEAMesh();
    }
    else if ( device == &m_AddAssemblyButton )
    {
        StructureMgr.AddFeaAssembly();
        StructureMgr.SetCurrAssemblyIndex( StructureMgr.NumFeaAssembly() - 1 );

    }
    else if ( device == &m_DelAssemblyButton )
    {
        if ( StructureMgr.ValidFeaAssemblyInd( StructureMgr.GetCurrAssemblyIndex() ) )
        {
            StructureMgr.DeleteFeaAssembly( StructureMgr.GetCurrAssemblyIndex() );

            StructureMgr.SetCurrAssemblyIndex( StructureMgr.GetCurrAssemblyIndex() - 1 );
        }
        else
        {
            StructureMgr.SetCurrAssemblyIndex( -1 );
        }
    }
    else if ( device == &m_AssemblyNameInput )
    {
        if ( StructureMgr.ValidFeaAssemblyInd( StructureMgr.GetCurrAssemblyIndex() ) )
        {
            vector < FeaAssembly* > assy_vec = StructureMgr.GetFeaAssemblyVec();
            FeaAssembly* fea_assy = assy_vec[StructureMgr.GetCurrAssemblyIndex()];

            if ( fea_assy )
            {
                fea_assy->SetName( m_AssemblyNameInput.GetString() );
            }
        }
    }
    else if ( device == &m_FeaStructureChoice )
    {
        m_StructureChoiceIndex = m_FeaStructureChoice.GetVal();
    }
    else if ( device == &m_AddFeaStructureButton )
    {
        if ( StructureMgr.ValidFeaAssemblyInd( StructureMgr.GetCurrAssemblyIndex() ) )
        {
            vector < FeaAssembly* > assy_vec = StructureMgr.GetFeaAssemblyVec();
            FeaAssembly* fea_assy = assy_vec[StructureMgr.GetCurrAssemblyIndex()];

            if ( fea_assy )
            {
                fea_assy->AddStructure( m_StructIDs[m_StructureChoiceIndex] );
            }
        }
    }
    else if ( device == &m_DelFeaStructureButton )
    {
        if ( StructureMgr.ValidFeaAssemblyInd( StructureMgr.GetCurrAssemblyIndex() ) )
        {
            vector < FeaAssembly* > assy_vec = StructureMgr.GetFeaAssemblyVec();
            FeaAssembly* fea_assy = assy_vec[StructureMgr.GetCurrAssemblyIndex()];

            if ( fea_assy )
            {
                fea_assy->DelStructure( fea_assy->m_StructIDVec[ m_StructureBrowserIndex ] );
            }
        }
    }
    else if ( device == &m_ConnectionStartChoice )
    {
        m_ConnectionStartIndex = m_ConnectionStartChoice.GetVal();
    }
    else if ( device == &m_ConnectionEndChoice )
    {
        m_ConnectionEndIndex = m_ConnectionEndChoice.GetVal();
    }
    else if ( device == &m_AddConnectionButton )
    {
        if ( StructureMgr.ValidFeaAssemblyInd( StructureMgr.GetCurrAssemblyIndex() ) )
        {
            vector < FeaAssembly* > assy_vec = StructureMgr.GetFeaAssemblyVec();
            FeaAssembly* fea_assy = assy_vec[StructureMgr.GetCurrAssemblyIndex()];

            if ( fea_assy )
            {
                fea_assy->AddConnection( m_FixPtIDs[m_ConnectionStartIndex], m_FixPtStructIDs[m_ConnectionStartIndex],
                                         m_FixPtIDs[m_ConnectionEndIndex], m_FixPtStructIDs[m_ConnectionEndIndex] );
            }
        }
    }
    else if ( device == &m_DelConnectionButton )
    {
        if ( StructureMgr.ValidFeaAssemblyInd( StructureMgr.GetCurrAssemblyIndex() ) )
        {
            vector < FeaAssembly* > assy_vec = StructureMgr.GetFeaAssemblyVec();
            FeaAssembly* fea_assy = assy_vec[StructureMgr.GetCurrAssemblyIndex()];

            if ( fea_assy )
            {
                fea_assy->DelConnection( m_ConnectionBrowserIndex );
            }
        }
    }
    else if ( device == &m_SelectStlFile )
    {
        if ( StructureMgr.ValidTotalFeaStructInd( StructureMgr.m_CurrStructIndex() ) )
        {
            vector < FeaStructure* > structvec = StructureMgr.GetAllFeaStructs();

            string newfile = m_ScreenMgr->GetSelectFileScreen()->FileChooser( "Select .stl file.", "*.stl" );
            if ( newfile.compare( "" ) != 0 )
            {
                structvec[StructureMgr.m_CurrStructIndex()]->GetStructSettingsPtr()->SetExportFileName( newfile, vsp::FEA_STL_FILE_NAME );
            }
        }
    }
    else if ( device == &m_SelectMassFile )
    {
        if ( StructureMgr.ValidTotalFeaStructInd( StructureMgr.m_CurrStructIndex() ) )
        {
            vector < FeaStructure* > structvec = StructureMgr.GetAllFeaStructs();

            string newfile = m_ScreenMgr->GetSelectFileScreen()->FileChooser( "Select mass .txt file.", "*.txt" );
            if ( newfile.compare( "" ) != 0 )
            {
                structvec[StructureMgr.m_CurrStructIndex()]->GetStructSettingsPtr()->SetExportFileName( newfile, vsp::FEA_MASS_FILE_NAME );
            }
        }
    }
    else if ( device == &m_SelectNastFile )
    {
        if ( StructureMgr.ValidTotalFeaStructInd( StructureMgr.m_CurrStructIndex() ) )
        {
            vector < FeaStructure* > structvec = StructureMgr.GetAllFeaStructs();

            string newfile = m_ScreenMgr->GetSelectFileScreen()->FileChooser( "Select NASTRAN .dat file.", "*.dat" );
            if ( newfile.compare( "" ) != 0 )
            {
                structvec[StructureMgr.m_CurrStructIndex()]->GetStructSettingsPtr()->SetExportFileName( newfile, vsp::FEA_NASTRAN_FILE_NAME );
            }
        }
    }
    else if ( device == &m_SelectNkeyFile )
    {
        if ( StructureMgr.ValidTotalFeaStructInd( StructureMgr.m_CurrStructIndex() ) )
        {
            vector < FeaStructure* > structvec = StructureMgr.GetAllFeaStructs();

            string newfile = m_ScreenMgr->GetSelectFileScreen()->FileChooser( "Select NASTRAN key file.", "*.nkey" );
            if ( newfile.compare( "" ) != 0 )
            {
                structvec[StructureMgr.m_CurrStructIndex()]->GetStructSettingsPtr()->SetExportFileName( newfile, vsp::FEA_NKEY_FILE_NAME );
            }
        }
    }
    else if ( device == &m_SelectCalcFile  )
    {
        if ( StructureMgr.ValidTotalFeaStructInd( StructureMgr.m_CurrStructIndex() ) )
        {
            vector < FeaStructure* > structvec = StructureMgr.GetAllFeaStructs();

            string newfile = m_ScreenMgr->GetSelectFileScreen()->FileChooser( "Select Calculix .dat file.", "*.dat" );
            if ( newfile.compare( "" ) != 0 )
            {
                structvec[StructureMgr.m_CurrStructIndex()]->GetStructSettingsPtr()->SetExportFileName( newfile, vsp::FEA_CALCULIX_FILE_NAME );
            }
        }
    }
    else if ( device == &m_SelectGmshFile )
    {
        if ( StructureMgr.ValidTotalFeaStructInd( StructureMgr.m_CurrStructIndex() ) )
        {
            vector < FeaStructure* > structvec = StructureMgr.GetAllFeaStructs();

            string newfile = m_ScreenMgr->GetSelectFileScreen()->FileChooser( "Select .msh file.", "*.msh" );
            if ( newfile.compare( "" ) != 0 )
            {
                structvec[StructureMgr.m_CurrStructIndex()]->GetStructSettingsPtr()->SetExportFileName( newfile, vsp::FEA_GMSH_FILE_NAME );
            }
        }
    }

    m_ScreenMgr->SetUpdateFlag( true );
}

void StructAssemblyScreen::LoadDrawObjs( vector< DrawObj* > &draw_obj_vec )
{
    Vehicle* veh = m_ScreenMgr->GetVehiclePtr();

    if ( !veh )
    {
        return;
    }

    if ( IsShown() )
    {

        // Load Draw Objects for FeaMesh
        FeaMeshMgr.LoadDrawObjs( draw_obj_vec );
    }
}
