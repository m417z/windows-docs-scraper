# OpenFileMappingFromApp function

## Description

Opens a named file mapping object.

## Parameters

### `DesiredAccess` [in]

The access to the file mapping object. This access is checked against any security descriptor on the target
file mapping object. For a list of values, see
[File Mapping Security and Access Rights](https://learn.microsoft.com/windows/desktop/Memory/file-mapping-security-and-access-rights). You can only open the file mapping object for **FILE_MAP_EXECUTE** access if your app has the **codeGeneration** capability.

### `InheritHandle` [in]

If this parameter is **TRUE**, a process created by the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function can inherit the handle;
otherwise, the handle cannot be inherited.

### `Name` [in]

The name of the file mapping object to be opened. If there is an open handle to a file mapping object by
this name and the security descriptor on the mapping object does not conflict with the
*DesiredAccess* parameter, the open operation succeeds. The name can have a
"Global\" or "Local\" prefix to explicitly open an object in the global or
session namespace. The remainder of the name can contain any character except the backslash character (\\). For
more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces). Fast user
switching is implemented using Terminal Services sessions. The first user to log on uses session 0, the next
user to log on uses session 1, and so on. Kernel object names must follow the guidelines outlined for Terminal
Services so that applications can support multiple users.

## Return value

If the function succeeds, the return value is an open handle to the specified file mapping object.

If the function fails, the return value is **NULL**. To get extended error information,
call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can call **OpenFileMappingFromApp** from Windows Store apps with just-in-time (JIT) capabilities to use JIT functionality. The app must include the **codeGeneration** capability in the app manifest file to use JIT capabilities. **OpenFileMappingFromApp** lets Windows Store apps use the [MemoryMappedFile](https://learn.microsoft.com/dotnet/api/system.io.memorymappedfiles.memorymappedfile) class in the .NET Framework.

The handle that **OpenFileMappingFromApp** returns can be used
with any function that requires a handle to a file mapping object.

When modifying a file through a mapped view, the last modification timestamp may not be updated automatically.
If required, the caller should use [SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime) to set the
timestamp.

When it is no longer needed, the caller should call release the handle returned by
**OpenFileMappingFromApp** with a call to
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

## See also

[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga)

[File Mapping Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

Memory Management Functions

[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga)

[Sharing Files and Memory](https://learn.microsoft.com/windows/desktop/Memory/sharing-files-and-memory)