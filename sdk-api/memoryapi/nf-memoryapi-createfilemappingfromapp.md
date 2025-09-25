# CreateFileMappingFromApp function

## Description

Creates or opens a named or unnamed file mapping object for a specified file from a
Windows Store app.

## Parameters

### `hFile` [in]

A handle to the file from which to create a file mapping object.

The file must be opened with access rights that are compatible with the protection flags that the
*flProtect* parameter specifies. It is not required, but it is recommended that files
you intend to map be opened for exclusive access. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

If *hFile* is **INVALID_HANDLE_VALUE**, the calling process
must also specify a size for the file mapping object in the *dwMaximumSizeHigh* and
*dwMaximumSizeLow* parameters. In this scenario,
**CreateFileMappingFromApp** creates a file
mapping object of a specified size that is backed by the system paging file instead of by a file in the file
system.

### `SecurityAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)
structure that determines whether a returned handle can be inherited by child processes. The
**lpSecurityDescriptor** member of the
**SECURITY_ATTRIBUTES** structure specifies a
security descriptor for a new file mapping object.

If *SecurityAttributes* is **NULL**, the handle cannot be
inherited and the file mapping object gets a default security descriptor. The access control lists (ACL) in the
default security descriptor for a file mapping object come from the primary or impersonation token of the
creator. For more information, see
[File Mapping Security and Access Rights](https://learn.microsoft.com/windows/desktop/Memory/file-mapping-security-and-access-rights).

### `PageProtection` [in]

Specifies the page protection of the file mapping object. All mapped views of the object must be compatible
with this protection.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PAGE_READONLY**<br><br>0x02 | Allows views to be mapped for read-only or copy-on-write access. An attempt to write to a specific region results in an access violation.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** access right. |
| **PAGE_READWRITE**<br><br>0x04 | Allows views to be mapped for read-only, copy-on-write, or read/write access.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** and **GENERIC_WRITE** access rights. |
| **PAGE_WRITECOPY**<br><br>0x08 | Allows views to be mapped for read-only or copy-on-write access. This value is equivalent to **PAGE_READONLY**.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** access right. |

An application can specify one or more of the following attributes for the file mapping object by combining
them with one of the preceding page protection values.

| Value | Meaning |
| --- | --- |
| **SEC_COMMIT**<br><br>0x8000000 | If the file mapping object is backed by the operating system paging file (the *hfile* parameter is **INVALID_HANDLE_VALUE**), specifies that when a view of the file is mapped into a process address space, the entire range of pages is committed rather than reserved. The system must have enough committable pages to hold the entire mapping. Otherwise, **CreateFileMappingFromApp** fails.<br><br>This attribute has no effect for file mapping objects that are backed by executable image files or data files (the *hfile* parameter is a handle to a file).<br><br>**SEC_COMMIT** cannot be combined with **SEC_RESERVE**.<br><br>If no attribute is specified, **SEC_COMMIT** is assumed. |
| **SEC_IMAGE_NO_EXECUTE**<br><br>0x11000000 | Specifies that the file that the *hFile* parameter specifies is an executable image file that will not be executed and the loaded image file will have no forced integrity checks run. Additionally, mapping a view of a file mapping object created with the **SEC_IMAGE_NO_EXECUTE** attribute will not invoke driver callbacks registered using the [PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/nf-ntddk-pssetloadimagenotifyroutine) kernel API.<br><br>The **SEC_IMAGE_NO_EXECUTE** attribute must be combined with the **PAGE_READONLY** page protection value. No other attributes are valid with **SEC_IMAGE_NO_EXECUTE**. |
| **SEC_LARGE_PAGES**<br><br>0x80000000 | Enables large pages to be used for file mapping objects that are backed by the operating system paging file (the *hfile* parameter is **INVALID_HANDLE_VALUE**). This attribute is not supported for file mapping objects that are backed by executable image files or data files (the *hFile* parameter is a handle to an executable image or data file).<br><br>The maximum size of the file mapping object must be a multiple of the minimum size of a large page returned by the [GetLargePageMinimum](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getlargepageminimum) function. If it is not, **CreateFileMappingFromApp** fails. When mapping a view of a file mapping object created with **SEC_LARGE_PAGES**, the base address and view size must also be multiples of the minimum large page size.<br><br>**SEC_LARGE_PAGES** requires the [SeLockMemoryPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants) privilege to be enabled in the caller's token.<br><br>If **SEC_LARGE_PAGES** is specified, **SEC_COMMIT** must also be specified. |
| **SEC_NOCACHE**<br><br>0x10000000 | Sets all pages to be non-cacheable.<br><br>Applications should not use this attribute except when explicitly required for a device. Using the interlocked functions with memory that is mapped with **SEC_NOCACHE** can result in an **EXCEPTION_ILLEGAL_INSTRUCTION** exception.<br><br>**SEC_NOCACHE** requires either the **SEC_RESERVE** or **SEC_COMMIT** attribute to be set. |
| **SEC_RESERVE**<br><br>0x4000000 | If the file mapping object is backed by the operating system paging file (the *hfile* parameter is **INVALID_HANDLE_VALUE**), specifies that when a view of the file is mapped into a process address space, the entire range of pages is reserved for later use by the process rather than committed.<br><br>Reserved pages can be committed in subsequent calls to the [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function. After the pages are committed, they cannot be freed or decommitted with the [VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree) function.<br><br>This attribute has no effect for file mapping objects that are backed by executable image files or data files (the *hfile* parameter is a handle to a file).<br><br>**SEC_RESERVE** cannot be combined with **SEC_COMMIT**. |
| **SEC_WRITECOMBINE**<br><br>0x40000000 | Sets all pages to be write-combined.<br><br>Applications should not use this attribute except when explicitly required for a device. Using the interlocked functions with memory that is mapped with **SEC_WRITECOMBINE** can result in an **EXCEPTION_ILLEGAL_INSTRUCTION** exception.<br><br>**SEC_WRITECOMBINE** requires either the **SEC_RESERVE** or **SEC_COMMIT** attribute to be set. |

### `MaximumSize` [in]

The maximum size of the file mapping object.

An attempt to map a file with a length of 0 (zero) fails with an error code of
**ERROR_FILE_INVALID**. Applications should test for files with a length of 0 (zero) and
reject those files.

### `Name` [in, optional]

The name of the file mapping object.

If this parameter matches the name of an existing mapping object, the function requests access to the
object with the protection that *flProtect* specifies.

If this parameter is **NULL**, the file mapping object is created without a name.

If *lpName* matches the name of an existing event, semaphore, mutex, waitable timer,
or job object, the function fails, and the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns
**ERROR_INVALID_HANDLE**. This occurs because these objects share the same namespace.

The name can have a "Global\" or "Local\" prefix to explicitly create the object in the global or session
namespace. The remainder of the name can contain any character except the backslash character (\\). Creating a
file mapping object in the global namespace from a session other than session zero requires the
[SeCreateGlobalPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants)
privilege. For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces).

Fast user switching is implemented by using Terminal Services sessions. The first user to log on uses session
0 (zero), the next user to log on uses session 1 (one), and so on. Kernel object names must follow the
guidelines that are outlined for Terminal Services so that applications can support multiple users.

## Return value

If the function succeeds, the return value is a handle to the newly created file mapping object.

If the object exists before the function call, the function returns a handle to the existing object (with its
current size, not the specified size), and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
returns **ERROR_ALREADY_EXISTS**.

If the function fails, the return value is **NULL**. To get extended error information,
call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After a file mapping object is created, the size of the file must not exceed the size of the file mapping
object; if it does, not all of the file contents are available for sharing.

If an application specifies a size for the file mapping object that is larger than the size of the actual
named file on disk and if the page protection allows write access (that is, the
*flProtect* parameter specifies **PAGE_READWRITE**), then the file
on disk is increased to match the specified size of the file mapping object. If the file is extended, the contents
of the file between the old end of the file and the new end of the file are not guaranteed to be zero; the
behavior is defined by the file system. If the file on disk cannot be increased,
**CreateFileMappingFromApp** fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_DISK_FULL**.

The initial contents of the pages in a file mapping object backed by the operating system paging file are 0
(zero).

The handle that **CreateFileMappingFromApp**
returns has full access to a new file mapping object, and can be used with any function that requires a handle to
a file mapping object.

Multiple processes can share a view of the same file by either using a single shared file mapping object or
creating separate file mapping objects backed by the same file. A single file mapping object can be shared by
multiple processes through inheriting the handle at process creation, duplicating the handle, or opening the file
mapping object by name. For more information, see the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa),
[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) and
[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga) functions.

Creating a file mapping object does not actually map the view into a process address space. The
[MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex) function map a view of a file into a
process address space.

With one important exception, file views derived from any file mapping object that is backed by the same file
are coherent or identical at a specific time. Coherency is guaranteed for views within a process and for views
that are mapped by different processes.

The exception is related to remote files. Although
**CreateFileMappingFromApp** works with remote
files, it does not keep them coherent. For example, if two computers both map a file as writable, and both change
the same page, each computer only sees its own writes to the page. When the data gets updated on the disk, it is
not merged.

A mapped file and a file that is accessed by using the input and output (I/O) functions
([ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) and
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)) are not necessarily coherent.

Mapped views of a file mapping object maintain internal references to the object, and a file mapping object
does not close until all references to it are released. Therefore, to fully close a file mapping object, an
application must unmap all mapped views of the file mapping object by calling
[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile) and close the file mapping object
handle by calling [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle). These functions can be
called in any order.

When modifying a file through a mapped view, the last modification timestamp may not be updated automatically.
If required, the caller should use [SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime) to set the
timestamp.

Use structured exception handling to protect any code that writes to or reads from a file view. For more
information, see
[Reading and Writing From a File View](https://learn.microsoft.com/windows/desktop/Memory/reading-and-writing-from-a-file-view).

 You can only successfully request executable protection if your app has the **codeGeneration** capability.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga)

[Creating a File Mapping Object](https://learn.microsoft.com/windows/desktop/Memory/creating-a-file-mapping-object)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

File Mapping Functions

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)

[MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile)

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)