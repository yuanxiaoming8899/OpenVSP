<div class="Box-sc-g0xbh4-0 bJMeLZ js-snippet-clipboard-copy-unpositioned" data-hpc="true"><article class="markdown-body entry-content container-lg" itemprop="text"><div class="markdown-heading" dir="auto"><h1 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">OpenVSP 的构建和安装说明</font></font></h1><a id="user-content-build-and-installation-instructions-for-openvsp" class="anchor" aria-label="永久链接：OpenVSP 的构建和安装说明" href="#build-and-installation-instructions-for-openvsp"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="markdown-heading" dir="auto"><h3 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">介绍</font></font></h3><a id="user-content-introduction" class="anchor" aria-label="永久链接：简介" href="#introduction"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">OpenVSP 是一个参数化飞机几何工具。 OpenVSP 允许用户创建由通用工程参数定义的飞机 3D 模型。该模型可以处理成适合工程分析的格式。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">OpenVSP 的前身是 JR Gloudemans 和其他人自 1990 年代初期以来为 NASA 开发的。 2012 年 1 月，OpenVSP 作为开源项目在 NOSA 1.3 许可证下发布。第一个开源版本是2.0.0。</font></font></p>
<div class="markdown-heading" dir="auto"><h3 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">执照</font></font></h3><a id="user-content-license" class="anchor" aria-label="永久链接：许可证" href="#license"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">OpenVSP 根据 NASA 开源协议 (NOSA) 1.3 版的条款提供。许可证的完整条款在 LICENSE 文件中指定。</font></font></p>
<div class="markdown-heading" dir="auto"><h3 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">依赖关系</font></font></h3><a id="user-content-dependencies" class="anchor" aria-label="永久链接：依赖关系" href="#dependencies"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">OpenVSP 依赖于其他作者提供的各种库和代码。如果您是VSP用户，您可能不需要担心这一点。将此部分视为信息，在适当的时候提供信用。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">如果您希望编译 VSP 或使用 VSP API，那么您将需要了解更多信息。这些依赖项分为四类： 假定由操作系统提供的依赖项；必须由开发者下载并安装的；与 OpenVSP 捆绑在一起，但开发人员可能希望使用系统上安装的不同版本；以及那些与 OpenVSP 捆绑在一起的。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">大多数用户都熟悉 OpenVSP GUI。其他程序还可以通过 API 或在无需用户交互的情况下以批处理模式访问 OpenVSP。这些“无头”目标可以在不安装任何图形库的情况下进行编译。尽管大多数开发人员希望构建图形版本，但那些仅由 GUI 程序和支持图形的 API 需要的依赖项被标记为 GRAPHICS_ONLY。</font></font></p>
<div class="markdown-heading" dir="auto"><h5 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">假设由操作系统提供。</font></font></h5><a id="user-content-assumed-provided-by-the-operating-system" class="anchor" aria-label="永久链接：假设由操作系统提供。" href="#assumed-provided-by-the-operating-system"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<ul dir="auto">
<li><a href="http://www.opengl.org" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">OpenGL</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 3D 图形库。 OpenGL 应该可以在任何能够显示 3D 图形的平台上使用。仅图形</font></font></li>
</ul>
<div class="markdown-heading" dir="auto"><h5 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">由开发商安装。</font></font></h5><a id="user-content-installed-by-the-developer" class="anchor" aria-label="永久链接：由开发人员安装。" href="#installed-by-the-developer"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<ul dir="auto">
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">C++ 编译器 - OpenVSP 需要支持某些 C++11 功能的现代 C++ 编译器。我们尝试在主要平台上支持流行的免费编译器。对于 Windows，我们需要 Visual Studio 2010 Express 或更高版本。对于 Mac OSX 或 Linux/BSD，我们支持 LLVM 和 GCC。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://www.cmake.org" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">CMake 3.1</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 跨平台构建系统。 CMake 生成控制 OpenVSP 编译的平台本机构建文件。 CMake 在大多数 Linux 系统上作为标准包提供，二进制安装程序可用于许多其他平台，包括 Windows 和 Mac OS X。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://www.swig.org" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">SWIG</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 简化的包装器和接口生成器。用于构建 Python 和其他脚本语言 API 接口的可选依赖项。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://www.python.org" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Python</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 脚本语言。如果构建 Python API 模块，则需要可选的依赖项。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://www.doxygen.org" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Doxygen</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 文档生成器。用于从源生成文档的可选依赖项。还可以利用 graphviz dot 在文档中生成改进的图形。 （</font></font><a href="http://www.graphviz.org" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">http://www.graphviz.org</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">）</font></font></p>
</li>
</ul>
<div class="markdown-heading" dir="auto"><h5 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">与 OpenVSP 捆绑在一起，但系统库可以替代。</font></font></h5><a id="user-content-bundled-with-openvsp-but-system-libraries-may-substitute" class="anchor" aria-label="永久链接：与 OpenVSP 捆绑在一起，但系统库可以替代。" href="#bundled-with-openvsp-but-system-libraries-may-substitute"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<ul dir="auto">
<li>
<p dir="auto"><a href="http://github.com/ddmarshall/Code-Eli"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Code-Eli</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 曲线和曲面库。 Code-Eli 是 David Marshall 为满足 OpenVSP 的需求而开发的。它是一个仅包含头文件的库，必须可用于构建。它不太可能被打包在任何系统上。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://eigen.tuxfamily.org" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Eigen3</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 线性代数模板库。 Code-Eli 需要这个仅包含头文件的库。 Eigen3 很可能作为 Linux 上的标准包提供。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://cpptest.sourceforge.net" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">CppTest</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - C++ 单元测试框架。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://www.xmlsoft.org" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Libxml2</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - XML 解析器和工具包。 Libxml2 很可能预装在大多数 Linux 发行版和 Mac OS X 系统中。 Windows 用户必须下载源代码并按照 Libxml2 说明构建此库。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://www.angusj.com/clipper2/Docs/Overview.htm" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Clipper2</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 用于剪切和偏移 2D 直线和多边形的开源库。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://devernay.free.fr/hacks/cminpack/" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">CMinpack</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 标准 Fortran Levenberg-Marquardt 实现的 C/C++ 端口。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://www.fltk.org" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">FLTK</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 跨平台窗口库。 FLTK 应作为大多数 Linux 系统上的标准包提供，并且可以根据 FLTK 说明从 Windows 和 Mac OS X 上的源代码安装。仅图形</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://glm.g-truc.net" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">GLM</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - OpenGL 数学库。仅图形</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://glew.sourceforge.net" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">GLEW</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - OpenGL 扩展牧马人库。该库用于访问任何现代 OpenGL 功能。仅图形</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://github.com/cbernardo/libIGES"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">libIGES</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 用于处理 IGES 文件的库。这不太可能被打包在任何系统上。 OpenVSP 使用</font></font><a href="https://github.com/ramcdona/libIGES"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Rob McDonald</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
或</font></font><a href="https://github.com/justingravett/libIGES.git"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Justin Gravett</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">修改的版本</font><font style="vertical-align: inherit;">来实现 CMake 2.8 兼容性</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://stepcode.github.io/" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">STEPcode</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 用于处理 STEP 标准文件的库。基于 NIST 开发的旧库。这是一个相对较新的库，正在不断发展。不可能在任何系统上打包。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://github.com/amgary/exprparse"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">exprparse</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 一个简单的 C++ 库，用于从存储为字符串的简单数学表达式计算值。</font></font></p>
</li>
<li>
<p dir="auto"><a href="https://github.com/msokalski/delabella"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">delabella</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - C++ Delaunay 三角测量库。</font></font></p>
</li>
<li>
<p dir="auto"><a href="https://gitlab.com/educelab/OpenABF" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">OpenABF</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 基于 C++ 角度的展平网格参数化库。</font></font></p>
</li>
</ul>
<div class="markdown-heading" dir="auto"><h5 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">与 OpenVSP 捆绑在一起。</font></font></h5><a id="user-content-bundled-with-openvsp" class="anchor" aria-label="永久链接：与 OpenVSP 捆绑在一起。" href="#bundled-with-openvsp"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<ul dir="auto">
<li>
<p dir="auto"><a href="http://www.angelcode.com/angelscript" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">AngelScript</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - C++ 的嵌入式脚本语言。用于用户定义的组件。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://code.google.com/p/nanoflann" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">nanoflann</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 快速最近邻库。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Sixseries - NASA 6 系列翼型一代 Fortran 代码从 NASA TM X 3069 1974 年 9 月发布到公共领域。使用 F2C 转换为 C。</font></font></p>
</li>
<li>
<p dir="auto"><a href="http://www.cs.cmu.edu/~quake/triangle.html" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Jonathan Shewchuk 设计的三角形</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
2D Delaunay 三角仪。</font></font></p>
<ul dir="auto">
<li><a href="https://github.com/wo80/Triangle"><font style="vertical-align: inherit;"></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">OpenVSP 使用的</font><a href="https://github.com/wo80/Triangle"><font style="vertical-align: inherit;">CMake 库版本</font></a></font></li>
</ul>
</li>
<li>
<p dir="auto"><a href="https://github.com/erich666/jgt-code/tree/master/Volume_08/Number_1/Guigue2003"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">tri_tri_intersect，作者：Philippe Guigue 和 Olivier Devillers</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 使用方向谓词进行快速且稳健的三角-三角重叠测试。早期版本 OpenVSP 中包含的 Tomas Möller 快速三角形-三角形相交例程的升级版本。虽然该代码主要基于 Möller 的算法，但在数值上更加稳健和高效。</font></font></p>
<ul dir="auto">
<li>
<p dir="auto"><a href="https://web.archive.org/web/20120118225810/http://jgt.akpeters.com/papers/GuigueDevillers03/" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">旧网址</font></font></a></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Philippe Guigue、Olivier Devillers，“使用方向谓词进行快速且稳健的三角-三角重叠测试”，图形工具杂志，卷。 8、伊萨。 2003 年 1 月。</font></font></p>
</li>
</ul>
</li>
<li>
<p dir="auto"><a href="http://web.archive.org/web/*/https://students.cs.byu.edu/~bfish/glfont2.php" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">glFont2 by Brad Fish（原：students.cs.byu.edu/~bfish/glfont2.php）</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 2D OpenGL 字体工具。 glFont2 已包含在此源代码发行版中。仅图形</font></font></p>
</li>
<li>
<p dir="auto"><a href="https://sourceforge.net/p/rfltk/code/HEAD/tree/cartesian/" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">cartesian</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - FLTK 的简单 2D 绘图库.仅图形</font></font></p>
</li>
<li>
<p dir="auto"><a href="https://github.com/elrond79/Pinocchio"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Pinocchio</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 皮诺奇自动装备/称重工具。</font></font></p>
</li>
<li>
<p dir="auto"><a href="https://github.com/nothings/stb"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">stb</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> - 用于 C/C++ 的单文件库，用于读取和写入图像文件。仅图形</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">wavedragEL - 用于获取零升力 Wavedrag D/Q 的 Eminton-Lord 程序的独立版本，由 Sriram Rallabhandi 编写</font></font></p>
</li>
</ul>
<div class="markdown-heading" dir="auto"><h3 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">构建指令</font></font></h3><a id="user-content-build-instructions" class="anchor" aria-label="永久链接：构建指令" href="#build-instructions"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">如果您想在基于 Debian 的 Linux 计算机（Debian、Ubuntu、Mint 等）上构建 OpenVSP，OpenVSP Wiki 中包含分步说明：</font></font><a href="http://www.openvsp.org/wiki/doku.php?id=ubuntu_instructions" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">基于 Debian 的构建</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">如果您想在基于 RPM 的 Linux 发行版上构建 OpenVSP，OpenVSP Wiki 中包含分步说明：</font></font><a href="http://www.openvsp.org/wiki/doku.php?id=rpm_instructions" rel="nofollow"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">基于 RPM 的构建</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">必须正确安装上述依赖项类别 1 和 2 中描述的所有支持库和代码。第3类和第4类可以由OpenVSP本身来满足。开发人员喜欢使用系统库的任何来自类别 3 的依赖项都必须正确安装。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">我们只期望两种常见情况，即开发人员更愿意使用系统库而不是捆绑库。首先，在 Linux 上，系统库很容易获得，并且发行版强烈喜欢使用它们。其次，当开发人员同时处理 OpenVSP 和相关依赖项时。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">OpenVSP 打包编译为三个 CMake 项目：包含所有 OpenVSP 源代码和类别 4 依赖项的主 OpenVSP 项目；具有所有 3 类依赖项的库项目；一个可以统一构建其他两个项目的超级项目。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">刚刚接触 OpenVSP 的临时开发人员会想要使用 SuperProject；构建它应该照顾到一切。更多参与的开发人员将希望直接使用 OpenVSP 和 Libraries 项目； OpenVSP 项目比 SuperProject 与大多数 IDE 的集成更好。只想使用 3 类依赖项的系统库的开发人员不需要 Libraries 项目；他们只能处理主项目。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">CMake 用于构建项目的构建文件。 CMake 支持树外构建，使源树不包含生成的文件。创建一个构建目录来包含生成的文件，例如</font></font><code>openvsp/build</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">.然后，切换到构建目录并运行 CMake - 将相对路径传递给
</font></font><code>openvsp/src</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">，例如</font></font><code>cmake ../src</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">CMake 为您最喜欢的构建系统生成文件后，将它们加载到 IDE 中并从命令行编译或启动构建。</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">可以通过定义一些变量来配置 OpenVSP CMake 系统。这些变量可能与部分或全部项目相关。</font></font></p>
<div class="markdown-heading" dir="auto"><h5 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">所有项目变量：</font></font></h5><a id="user-content-all-project-variables" class="anchor" aria-label="永久链接：所有项目变量：" href="#all-project-variables"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<ul dir="auto">
<li>
<p dir="auto"><code>VSP_NO_GRAPHICS</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">-- 设置此变量以禁用与图形有关的所有内容。构建系统不会搜索或构建任何图形库。它只会构建无头批处理模式 VSP、API 和绑定。这非常适合在访问受限的 HPC 计算机上构建 VSP。</font></font></p>
</li>
<li>
<p dir="auto"><code>VSP_NO_VSPAERO</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">-- 设置此变量以禁用与 VSPAERO 相关的所有内容。构建系统不会构建 VSPAERO 或其任何相关实用程序。</font></font></p>
</li>
<li>
<p dir="auto"><code>XXX_OMP_COMPILER</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">-- 设置这些变量以指向在主编译器不支持 OpenMP 时使用的辅助编译器。这将允许将 VSPAERO 求解器构建为多线程程序。该变量的预期版本是：</font></font></p>
<ul dir="auto">
<li><code>C_OMP_COMPILER</code></li>
<li><code>CXX_OMP_COMPILER</code></li>
</ul>
</li>
<li>
<p dir="auto"><code>VSP_INSTALL_API_TEST</code><font style="vertical-align: inherit;"></font><code>apitest</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">-- 设置为在安装包中</font><font style="vertical-align: inherit;">包含可执行文件。</font></font></p>
</li>
</ul>
<div class="markdown-heading" dir="auto"><h5 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">OpenVSP 项目变量：</font></font></h5><a id="user-content-openvsp-project-variables" class="anchor" aria-label="永久链接：OpenVSP 项目变量：" href="#openvsp-project-variables"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<ul dir="auto">
<li>
<p dir="auto"><code>VSP_LIBRARY_PATH</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">-- 设置此变量以指向构建库项目的目录。 SuperProject 自动设置此路径。库项目将包含大量设置的文件写入</font></font><code>VSP_Libraries_Config.cmake</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
此路径。</font></font></p>
</li>
<li>
<p dir="auto"><code>XXXX_INSTALL_DIR</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">-- 设置此变量指向已安装库的目录。这为相应的提供了建议</font></font><code>FIND_PACKAGE( XXXX )</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">。不要将这些变量与 一起使用</font></font><code>VSP_LIBRARY_PATH</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">，它会覆盖它们。该变量的可接受版本是：</font></font></p>
<ul dir="auto">
<li><code>Adept2_INSTALL_DIR</code></li>
<li><code>CLIPPER2_INSTALL_DIR</code></li>
<li><code>CMINPACK_INSTALL_DIR</code></li>
<li><code>CODEELI_INSTALL_DIR</code></li>
<li><code>CPPTEST_INSTALL_DIR</code></li>
<li><code>DELABELLA_INSTALL_DIR</code></li>
<li><code>EIGEN_INSTALL_DIR</code></li>
<li><code>EXPRPARSE_INSTALL_DIR</code></li>
<li><code>FLTK_INSTALL_DIR</code></li>
<li><code>GLEW_INSTALL_DIR</code></li>
<li><code>GLM_INSTALL_DIR</code></li>
<li><code>LIBIGES_INSTALL_DIR</code></li>
<li><code>LIBXML2_INSTALL_DIR</code></li>
<li><code>OPENABF_INSTALL_DIR</code></li>
<li><code>PINOCCHIO_INSTALL_DIR</code></li>
<li><code>STEPCODE_INSTALL_DIR</code></li>
<li><code>TRIANGLE_INSTALL_DIR</code></li>
</ul>
</li>
<li>
<p dir="auto"><code>VSP_ENABLE_MATLAB_API</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">-- 将此变量设置为 ON 以编译 OpenVSP MATLAB API。要成功，</font></font><code>SWIG_EXECUTABLE</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">必须设置为从 SWIG 的未发布 MATLAB 分支编译而来的 swig 可执行文件。</font></font></p>
</li>
</ul>
<div class="markdown-heading" dir="auto"><h5 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">库和 SuperProject 项目变量：</font></font></h5><a id="user-content-libraries--superproject-project-variables" class="anchor" aria-label="永久链接：库和 SuperProject 项目变量：" href="#libraries--superproject-project-variables"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<ul dir="auto">
<li>
<p dir="auto"><code>VSP_USE_SYSTEM_XXXX</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">-- 设置此变量以搜索特定库而不是使用捆绑版本。该变量的可接受版本是：</font></font></p>
<ul dir="auto">
<li><code>VSP_USE_SYSTEM_ADEPT2</code></li>
<li><code>VSP_USE_SYSTEM_CLIPPER2</code></li>
<li><code>VSP_USE_SYSTEM_CMINPACK</code></li>
<li><code>VSP_USE_SYSTEM_CODEELI</code></li>
<li><code>VSP_USE_SYSTEM_CPPTEST</code></li>
<li><code>VSP_USE_SYSTEM_DELABELLA</code></li>
<li><code>VSP_USE_SYSTEM_EIGEN</code></li>
<li><code>VSP_USE_SYSTEM_EXPRPARSE</code></li>
<li><code>VSP_USE_SYSTEM_FLTK</code></li>
<li><code>VSP_USE_SYSTEM_GLEW</code></li>
<li><code>VSP_USE_SYSTEM_GLM</code></li>
<li><code>VSP_USE_SYSTEM_LIBIGES</code></li>
<li><code>VSP_USE_SYSTEM_LIBXML2</code></li>
<li><code>VSP_USE_SYSTEM_OPENABF</code></li>
<li><code>VSP_USE_SYSTEM_PINOCCHIO</code></li>
<li><code>VSP_USE_SYSTEM_STEPCODE</code></li>
<li><code>VSP_USE_SYSTEM_TRIANGLE</code></li>
</ul>
</li>
</ul>
<div class="markdown-heading" dir="auto"><h3 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Windows 10 和 Visual Studio Express 2017 的构建说明</font></font></h3><a id="user-content-build-instructions-for-windows-10-and-visual-studio-express-2017" class="anchor" aria-label="永久链接：Windows 10 和 Visual Studio Express 2017 的构建说明" href="#build-instructions-for-windows-10-and-visual-studio-express-2017"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">这些说明用于分别构建库和 OpenVSP。假设用户已成功安装 CMake、Python、SWIG 和 Doxygen，并且可以从命令行调用这些实用程序。</font></font></p>
<div class="markdown-heading" dir="auto"><h4 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">建设图书馆</font></font></h4><a id="user-content-building-libraries" class="anchor" aria-label="永久链接：建设图书馆" href="#building-libraries"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<ol dir="auto">
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">在本地克隆的 OpenVSP 存储库外部创建一个名为 build 的新目录</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">在新的构建目录中，创建新目录“Libraries”和“vsp”</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">使用 CMake gui (cmake-gui.exe)，单击“浏览源代码”并浏览到 .../OpenVSP/Libraries，其中 OpenVSP 是源代码克隆存储库的顶层。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">单击“浏览构建”并浏览到新创建的“库”目录 (.../build/Libraries) 以获取新二进制文件的构建位置。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">单击“配置”并选择“Visual Studio 2017”作为项目生成器，选择“x64”作为可选平台生成器。单击“完成”。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">单击“添加条目”按钮。对于名称，输入“CMAKE_BUILD_TYPE”。对于“类型”，选择“字符串”，然后选择“值”类型“发布”。单击“确定”。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">单击“生成”。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">打开 Visual Studio Express 2017 并选择“文件”&gt;“打开项目”并浏览到 .../build/Libraries/VSP_LIBARIES.sln。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">在“解决方案配置”下拉列表中，从“调试”更改为“发布”。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">在解决方案资源管理器中右键单击“ALL_BUILD”并选择“构建”。完成后，重复此步骤以验证没有错误。</font></font></p>
</li>
</ol>
<div class="markdown-heading" dir="auto"><h4 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">构建 OpenVSP</font></font></h4><a id="user-content-building-openvsp" class="anchor" aria-label="永久链接：构建 OpenVSP" href="#building-openvsp"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<ol dir="auto">
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">打开 CMake Gui (cmake-gui.exe) 并浏览到 .../OpenVSP 以获取源代码，并浏览到 .../build/vsp 以获取二进制文件的构建位置。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">单击“添加条目”并在“名称”中输入“CMAKE_BUILD_TYPE”，在“类型”中选择“字符串”，并在“值”中输入“Release”。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">再次单击“Add Entry”并输入“VSP_LIBRARY_PATH”作为名称，选择 PATH 作为类型并浏览到 .../build/Libraries</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">单击“配置”并选择“Visual Studio 2017”作为项目生成器，选择“x64”作为生成器的可选平台。单击“完成”。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">单击“生成”。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">打开 Visual Studio Express 2017 并选择“文件”&gt;“打开项目”并浏览到 .../build/vsp/VSP_TOP.sln。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">在“解决方案配置”下拉列表中，从“调试”更改为“发布”。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">在解决方案资源管理器中右键单击 ALL_BUILD，然后选择“生成”。完成后，重复此步骤以验证没有错误。</font></font></p>
</li>
<li>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">右键单击“解决方案资源管理器”中的“PACKAGE”，然后选择“生成”。这会将所有目录和可执行文件打包在一个 zip 文件中。该 zip 文件将放置在 .../build/vsp/ 中。</font></font></p>
</li>
</ol>
</article></div>
