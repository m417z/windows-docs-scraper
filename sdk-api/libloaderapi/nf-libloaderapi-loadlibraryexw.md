# LoadLibraryExW function

## Description

Loads the specified module into the address space of the calling process. The specified
module may cause other modules to be loaded.

## Parameters

### `lpLibFileName` [in]

A string that specifies the file name of the module to load. This name is not related to the name stored in a
library module itself, as specified by the **LIBRARY** keyword in the module-definition
(.def) file.

The module can be a library module (a .dll file) or an executable module (an .exe file). If the
specified module is an executable module, static imports are not loaded; instead, the module is loaded as if
**DONT_RESOLVE_DLL_REFERENCES** was specified. See the *dwFlags*
parameter for more information.

If the string specifies a module name without a path and the file name extension is omitted, and the module name does
not contain any point character (.), then the function appends the default library extension ".DLL" to the module name.
To prevent the function from appending ".DLL" to the module name, include a trailing point character (.) in the module
name string.

If the string specifies a fully qualified path, the function searches only that path for the module. When
specifying a path, be sure to use backslashes (\\), not forward slashes (/). For more information about paths,
see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

If the string specifies a module name without a path and more than one loaded module has the same base name
and extension, the function returns a handle to the module that was loaded first.

If the string specifies a module name without a path and a module of the same name is not already loaded, or
if the string specifies a module name with a relative path, the function searches for the specified module. The
function also searches for modules if loading the specified module causes the system to load other associated
modules (that is, if the module has dependencies). The directories that are searched and the order in which
they are searched depend on the specified path and the *dwFlags* parameter. For more
information, see Remarks.

If the function cannot find the module or one of its dependencies, the function fails.

### `hFile`

This parameter is reserved for future use. It must be **NULL**.

### `dwFlags` [in]

The action to be taken when loading the module. If no flags are specified, the behavior of this function is
identical to that of the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function. This
parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DONT_RESOLVE_DLL_REFERENCES**<br><br>0x00000001 | If this value is used, and the executable module is a DLL, the system does not call [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) for process and thread initialization and termination. Also, the system does not load additional executable modules that are referenced by the specified module.<br><br>**Note** Do not use this value; it is provided only for backward compatibility. If you are planning to access only data or resources in the DLL, use **LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE** or **LOAD_LIBRARY_AS_IMAGE_RESOURCE** or both. Otherwise, load the library as a DLL or executable module using the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function. |
| **LOAD_IGNORE_CODE_AUTHZ_LEVEL**<br><br>0x00000010 | If this value is used, the system does not check [AppLocker](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd723678(v=ws.10)) rules or apply [Software Restriction Policies](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc779607(v=ws.10)) for the DLL. This action applies only to the DLL being loaded and not to its dependencies. This value is recommended for use in setup programs that must run extracted DLLs during installation.<br><br>**Windows Server 2008 R2 and Windows 7:** On systems with KB2532445 installed, the caller must be running as "LocalSystem" or "TrustedInstaller"; otherwise the system ignores this flag. For more information, see "You can circumvent AppLocker rules by using an Office macro on a computer that is running Windows 7 or Windows Server 2008 R2" in the Help and Support Knowledge Base at <https://support.microsoft.com/kb/2532445>.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** AppLocker was introduced in Windows 7 and Windows Server 2008 R2. |
| **LOAD_LIBRARY_AS_DATAFILE**<br><br>0x00000002 | If this value is used, the system maps the file into the calling process's virtual address space as if it were a data file. Nothing is done to execute or prepare to execute the mapped file. Therefore, you cannot call functions like [GetModuleFileName](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulefilenamea), [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea) or [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) with this DLL. Using this value causes writes to read-only memory to raise an access violation. Use this flag when you want to load a DLL only to extract messages or resources from it.<br><br>This value can be used with **LOAD_LIBRARY_AS_IMAGE_RESOURCE**. For more information, see Remarks. |
| **LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE**<br><br>0x00000040 | Similar to **LOAD_LIBRARY_AS_DATAFILE**, except that the DLL file is opened with exclusive write access for the calling process. Other processes cannot open the DLL file for write access while it is in use. However, the DLL can still be opened by other processes.<br><br>This value can be used with **LOAD_LIBRARY_AS_IMAGE_RESOURCE**. For more information, see Remarks.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported until Windows Vista. |
| **LOAD_LIBRARY_AS_IMAGE_RESOURCE**<br><br>0x00000020 | If this value is used, the system maps the file into the process's virtual address space as an image file. However, the loader does not load the static imports or perform the other usual initialization steps. Use this flag when you want to load a DLL only to extract messages or resources from it.<br><br>Unless the application depends on the file having the in-memory layout of an image, this value should be used with either **LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE** or **LOAD_LIBRARY_AS_DATAFILE**. For more information, see the Remarks section.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported until Windows Vista. |
| **LOAD_LIBRARY_SEARCH_APPLICATION_DIR**<br><br>0x00000200 | If this value is used, the application's installation directory is searched for the DLL and its dependencies. Directories in the standard search path are not searched. This value cannot be combined with **LOAD_WITH_ALTERED_SEARCH_PATH**.<br><br>**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** This value requires [KB2533623](https://support.microsoft.com/kb/2533623) to be installed.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **LOAD_LIBRARY_SEARCH_DEFAULT_DIRS**<br><br>0x00001000 | This value is a combination of **LOAD_LIBRARY_SEARCH_APPLICATION_DIR**, **LOAD_LIBRARY_SEARCH_SYSTEM32**, and **LOAD_LIBRARY_SEARCH_USER_DIRS**. Directories in the standard search path are not searched. This value cannot be combined with **LOAD_WITH_ALTERED_SEARCH_PATH**.<br><br>This value represents the recommended maximum number of directories an application should include in its DLL search path.<br><br>**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** This value requires [KB2533623](https://support.microsoft.com/kb/2533623) to be installed.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR**<br><br>0x00000100 | If this value is used, the directory that contains the DLL is temporarily added to the beginning of the list of directories that are searched for the DLL's dependencies. Directories in the standard search path are not searched.<br><br>The *lpFileName* parameter must specify a fully qualified path. This value cannot be combined with **LOAD_WITH_ALTERED_SEARCH_PATH**.<br><br>For example, if Lib2.dll is a dependency of C:\Dir1\Lib1.dll, loading Lib1.dll with this value causes the system to search for Lib2.dll only in C:\Dir1. To search for Lib2.dll in C:\Dir1 and all of the directories in the DLL search path, combine this value with **LOAD_LIBRARY_DEFAULT_DIRS**.<br><br>**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** This value requires [KB2533623](https://support.microsoft.com/kb/2533623) to be installed.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **LOAD_LIBRARY_SEARCH_SYSTEM32**<br><br>0x00000800 | If this value is used, %windows%\system32 is searched for the DLL and its dependencies. Directories in the standard search path are not searched. This value cannot be combined with **LOAD_WITH_ALTERED_SEARCH_PATH**.<br><br>**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** This value requires [KB2533623](https://support.microsoft.com/kb/2533623) to be installed.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **LOAD_LIBRARY_SEARCH_USER_DIRS**<br><br>0x00000400 | If this value is used, directories added using the [AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory) or the [SetDllDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setdlldirectorya) function are searched for the DLL and its dependencies. If more than one directory has been added, the order in which the directories are searched is unspecified. Directories in the standard search path are not searched. This value cannot be combined with **LOAD_WITH_ALTERED_SEARCH_PATH**.<br><br>**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** This value requires [KB2533623](https://support.microsoft.com/kb/2533623) to be installed.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **LOAD_WITH_ALTERED_SEARCH_PATH**<br><br>0x00000008 | If this value is used and *lpFileName* specifies an absolute path, the system uses the alternate file search strategy discussed in the Remarks section to find associated executable modules that the specified module causes to be loaded. If this value is used and *lpFileName* specifies a relative path, the behavior is undefined.<br><br>If this value is not used, or if *lpFileName* does not specify a path, the system uses the standard search strategy discussed in the Remarks section to find associated executable modules that the specified module causes to be loaded.<br><br>This value cannot be combined with any **LOAD_LIBRARY_SEARCH** flag. |
| **LOAD_LIBRARY_REQUIRE_SIGNED_TARGET**<br><br>0x00000080 | Specifies that the digital signature of the binary image must be checked at load time.<br><br>This value requires Windows 8.1, Windows 10 or later. |
| **LOAD_LIBRARY_SAFE_CURRENT_DIRS**<br><br>0x00002000 | If this value is used, loading a DLL for execution from the current directory is only allowed if it is under a directory in the Safe load list. |

## Return value

If the function succeeds, the return value is a handle to the loaded module.

If the function fails, the return value is **NULL**. To get extended error information,
call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **LoadLibraryEx** function is very similar to the
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function. The differences consist of a set of
optional behaviors that **LoadLibraryEx** provides:

* **LoadLibraryEx** can load a DLL module without
  calling the [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function of the DLL.
* **LoadLibraryEx** can load a module in a way that is
  optimized for the case where the module will never be executed, loading the module as if it were a data
  file.
* **LoadLibraryEx** can find modules and their
  associated modules by using either of two search strategies or it can search a process-specific set of
  directories.

You select these optional behaviors by setting the *dwFlags* parameter; if
*dwFlags* is zero,
**LoadLibraryEx** behaves identically to
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya).

The calling process can use the handle returned by
**LoadLibraryEx** to identify the module in calls to the
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress),
[FindResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourcea), and
[LoadResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadresource) functions.

To enable or disable error messages displayed by the loader during DLL loads, use the
[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode) function.

It is not safe to call **LoadLibraryEx** from
[DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain). For more information, see the Remarks section in
**DllMain**.

**Visual C++:** The Visual C++ compiler supports a syntax that enables you to declare thread-local variables:
**_declspec(thread)**. If you use this syntax in a DLL, you will not be able to load the
DLL explicitly using **LoadLibraryEx** on versions of
Windows prior to Windows Vista. If your DLL will be loaded explicitly, you must use the thread
local storage functions instead of **_declspec(thread)**. For an example, see
[Using Thread Local Storage in a Dynamic Link Library](https://learn.microsoft.com/windows/desktop/Dlls/using-thread-local-storage-in-a-dynamic-link-library).

### Loading a DLL as a Data File or Image Resource

The **LOAD_LIBRARY_AS_DATAFILE**,
**LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE**, and
**LOAD_LIBRARY_AS_IMAGE_RESOURCE** values affect the per-process reference count and the
loading of the specified module. If any of these values is specified for the *dwFlags*
parameter, the loader checks whether the module was already loaded by the process as an executable DLL. If so,
this means that the module is already mapped into the virtual address space of the calling process. In this
case, **LoadLibraryEx** returns a handle to the DLL and
increments the DLL reference count. If the DLL module was not already loaded as a DLL, the system maps the
module as a data or image file and not as an executable DLL. In this case,
**LoadLibraryEx** returns a handle to the loaded data or
image file but does not increment the reference count for the module and does not make the module visible to functions such as [CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) or [EnumProcessModules](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocessmodules).

If **LoadLibraryEx** is called twice for the same file
with **LOAD_LIBRARY_AS_DATAFILE**,
**LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE**, or
**LOAD_LIBRARY_AS_IMAGE_RESOURCE**, two separate mappings are created for the file.

When the **LOAD_LIBRARY_AS_IMAGE_RESOURCE** value is used, the module is loaded as an
image using portable executable (PE) section alignment expansion. Relative virtual addresses (RVA) do not have
to be mapped to disk addresses, so resources can be more quickly retrieved from the module. Specifying
**LOAD_LIBRARY_AS_IMAGE_RESOURCE** prevents other processes from modifying the module
while it is loaded.

Unless an application depends on specific image mapping characteristics, the
**LOAD_LIBRARY_AS_IMAGE_RESOURCE** value should be used with either
**LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE** or
**LOAD_LIBRARY_AS_DATAFILE**. This allows the loader to choose whether to load the module
as an image resource or a data file, selecting whichever option enables the system to share pages more
effectively. Resource functions such as
[FindResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourcea) can use either mapping.

To determine how a module was loaded, use one of the following macros to test the handle returned by
**LoadLibraryEx**.

```cpp
#define LDR_IS_DATAFILE(handle)      (((ULONG_PTR)(handle)) &  (ULONG_PTR)1)
#define LDR_IS_IMAGEMAPPING(handle)  (((ULONG_PTR)(handle)) & (ULONG_PTR)2)
#define LDR_IS_RESOURCE(handle)      (LDR_IS_IMAGEMAPPING(handle) || LDR_IS_DATAFILE(handle))

```

The following table describes these macros.

| Macro | Description |
| --- | --- |
| **LDR_IS_DATAFILE**(*handle*) | If this macro returns **TRUE**, the module was loaded as a data file (**LOAD_LIBRARY_AS_DATAFILE** or **LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE**). |
| **LDR_IS_IMAGEMAPPING**(*handle*) | If this macro returns **TRUE**, the module was loaded as an image file (**LOAD_LIBRARY_AS_IMAGE_RESOURCE**). |
| **LDR_IS_RESOURCE**(*handle*) | If this macro returns **TRUE**, the module was loaded as either a data file or an image file. |

Use the [FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary) function to free a loaded module,
whether or not loading the module caused its reference count to be incremented. If the module was loaded as a
data or image file, the mapping is destroyed but the reference count is not decremented. Otherwise, the DLL
reference count is decremented. Therefore, it is safe to call
**FreeLibrary** with any handle returned by
**LoadLibraryEx**.

### Searching for DLLs and Dependencies

The search path is the set of directories that are searched for a DLL. The
**LoadLibraryEx** function can search for a DLL using a
standard search path or an altered search path, or it can use a process-specific search path established with
the [SetDefaultDllDirectories](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-setdefaultdlldirectories) and
[AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory) functions. For a list of directories
and the order in which they are searched, see
[Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order).

The **LoadLibraryEx** function uses the standard search
path in the following cases:

* The file name is specified without a path and the base file name does not match the base file name of a
  loaded module, and none of the **LOAD_LIBRARY_SEARCH** flags are used.
* A path is specified but **LOAD_WITH_ALTERED_SEARCH_PATH** is not used.
* The application has not specified a default DLL search path for the process using
  [SetDefaultDllDirectories](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-setdefaultdlldirectories).

If *lpFileName* specifies a relative path, the entire relative path is appended to
every token in the DLL search path. To load a module from a relative path without searching any other path, use
[GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea) to get a nonrelative path and call
**LoadLibraryEx** with the nonrelative path. If the module
is being loaded as a datafile and the relative path starts with ".\" or
"..\", the relative path is treated as an absolute path.

If *lpFileName* specifies an absolute path and *dwFlags* is
set to **LOAD_WITH_ALTERED_SEARCH_PATH**,
**LoadLibraryEx** uses the altered search path.
The behavior is undefined when **LOAD_WITH_ALTERED_SEARCH_PATH** flag is set, and *lpFileName* specifies a relative path.

The [SetDllDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setdlldirectorya) function can be used to modify
the search path. This solution is better than using
[SetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcurrentdirectory) or hard-coding the full path
to the DLL. However, be aware that using
**SetDllDirectory** effectively disables safe DLL search
mode while the specified directory is in the search path and it is not thread safe. If possible, it is best to
use [AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory) to modify a default process
search path. For more information, see
[Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order).

An application can specify the directories to search for a single
**LoadLibraryEx** call by using the
**LOAD_LIBRARY_SEARCH_*** flags. If more than one
**LOAD_LIBRARY_SEARCH** flag is specified, the directories are searched in the following
order:

* The directory that contains the DLL (**LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR**). This
  directory is searched only for dependencies of the DLL to be loaded.
* The application directory (**LOAD_LIBRARY_SEARCH_APPLICATION_DIR**).
* Paths explicitly added to the application search path with the
  [AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory) function
  (**LOAD_LIBRARY_SEARCH_USER_DIRS**) or the
  [SetDllDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setdlldirectorya) function. If more than one path
  has been added, the order in which the paths are searched is unspecified.
* The System32 directory (**LOAD_LIBRARY_SEARCH_SYSTEM32**).

**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** The **LOAD_LIBRARY_SEARCH_*** flags are available on systems that have
[KB2533623](https://support.microsoft.com/kb/2533623)
installed. To determine whether the flags are available, use
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to get the address of the
[AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory),
[RemoveDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-removedlldirectory), or
[SetDefaultDllDirectories](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-setdefaultdlldirectories) function. If
**GetProcAddress** succeeds, the
**LOAD_LIBRARY_SEARCH_*** flags can be used with
**LoadLibraryEx**.

If the application has used the
[SetDefaultDllDirectories](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-setdefaultdlldirectories) function to
establish a DLL search path for the process and none of the **LOAD_LIBRARY_SEARCH_***
flags are used, the **LoadLibraryEx** function uses the
process DLL search path instead of the standard search path.

If a path is specified and there is a redirection file associated with the application, the
**LoadLibraryEx** function searches for the module in the
application directory. If the module exists in the application directory,
**LoadLibraryEx** ignores the path specification and
loads the module from the application directory. If the module does not exist in the application directory, the
function loads the module from the specified directory. For more information, see
[Dynamic Link Library Redirection](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-redirection).

If you call **LoadLibraryEx** with the name of an
assembly without a path specification and the assembly is listed in the system compatible manifest, the call is
automatically redirected to the side-by-side assembly.

### Security Remarks

**LOAD_LIBRARY_AS_DATAFILE** does not prevent other processes from modifying the module
while it is loaded. Because this can make your application less secure, you should use
**LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE** instead of
**LOAD_LIBRARY_AS_DATAFILE** when loading a module as a data file, unless you
specifically need to use **LOAD_LIBRARY_AS_DATAFILE**. Specifying
**LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE** prevents other processes from modifying the module
while it is loaded. Do not specify **LOAD_LIBRARY_AS_DATAFILE** and
**LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE** in the same call.

Do not use the [SearchPath](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-searchpathw) function to retrieve a path to
a DLL for a subsequent **LoadLibraryEx** call. The
**SearchPath** function uses a different search order than
**LoadLibraryEx** and it does not use safe process search
mode unless this is explicitly enabled by calling
[SetSearchPathMode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setsearchpathmode) with
**BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE**. Therefore,
**SearchPath** is likely to first search the user's current
working directory for the specified DLL. If an attacker has copied a malicious version of a DLL into the
current working directory, the path retrieved by
**SearchPath** will point to the malicious DLL, which
**LoadLibraryEx** will then load.

Do not make assumptions about the operating system version based on a
**LoadLibraryEx** call that searches for a DLL. If the
application is running in an environment where the DLL is legitimately not present but a malicious version of
the DLL is in the search path, the malicious version of the DLL may be loaded. Instead, use the recommended
techniques described in
[Getting the System Version](https://learn.microsoft.com/windows/desktop/SysInfo/getting-the-system-version).

For a general discussion of DLL security issues, see
[Dynamic-Link Library Security](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-security).

#### Examples

For an example, see
[Looking Up Text for Error Code Numbers](https://learn.microsoft.com/windows/desktop/NetMgmt/looking-up-text-for-error-code-numbers).

> [!NOTE]
> The libloaderapi.h header defines LoadLibraryEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain)

[Dynamic-Link Library Functions](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-functions)

[Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order)

[Dynamic-Link Library Security](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-security)

[FindResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourcea)

[FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya)

[GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[LoadResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadresource)

[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile)

[Run-Time Dynamic Linking](https://learn.microsoft.com/windows/desktop/Dlls/run-time-dynamic-linking)

[SearchPath](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-searchpathw)

[SetDllDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setdlldirectorya)

[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode)