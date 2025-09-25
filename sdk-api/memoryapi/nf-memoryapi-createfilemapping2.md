# CreateFileMapping2 function

## Description

Creates or opens a named or unnamed file mapping object for a specified file. You can specify a preferred NUMA node for the physical memory as an extended parameter; see the *ExtendedParameters* parameter.

## Parameters

### `File`

Type: \_In\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to the file from which to create a file mapping object.

The file must be opened with access rights that are compatible with the protection flags that the *flProtect* parameter specifies. It is not required, but it is recommended that files you intend to map be opened for exclusive access. For more information, see [File security and access rights](https://learn.microsoft.com/windows/win32/FileIO/file-security-and-access-rights).

If *hFile* is **INVALID_HANDLE_VALUE**, the calling process must also specify a size for the file mapping object in the *dwMaximumSizeHigh* and *dwMaximumSizeLow* parameters. In this scenario, **CreateFileMapping** creates a file mapping object of a specified size that is backed by the system paging file instead of by a file in the file system.

### `SecurityAttributes`

Type: \_In_opt\_ **[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)\***

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that determines whether a returned handle can be inherited by child processes. The **lpSecurityDescriptor** member of the **SECURITY_ATTRIBUTES** structure specifies a security descriptor for a new file mapping object.

If *lpAttributes* is **NULL**, the handle cannot be inherited and the file mapping object gets a default security descriptor. The access control lists (ACL) in the default security descriptor for a file mapping object come from the primary or impersonation token of the creator. For more information, see [File Mapping Security and Access Rights](https://learn.microsoft.com/windows/win32/Memory/file-mapping-security-and-access-rights).

### `DesiredAccess`

Type: \_In\_ **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The desired access mask for the returned file mapping handle. For a list of access rights, see [File-mapping security and access rights](https://learn.microsoft.com/windows/win32/memory/file-mapping-security-and-access-rights).

### `PageProtection`

Type: \_In\_ **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the page protection of the file mapping object. All mapped views of the object must be compatible with this protection.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PAGE_EXECUTE_READ**<br><br>0x20 | Allows views to be mapped for read-only, copy-on-write, or execute access.<br><br>The file handle specified by the *hFile* parameter must be created with the **GENERIC_READ** and **GENERIC_EXECUTE** access rights.<br><br>**Windows Server 2003 and Windows XP:** This value is not available until Windows XP with SP2 and Windows Server 2003 with SP1. |
| **PAGE_EXECUTE_READWRITE**<br><br>0x40 | Allows views to be mapped for read-only, copy-on-write, read/write, or execute access.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ**, **GENERIC_WRITE**, and **GENERIC_EXECUTE** access rights.<br><br>**Windows Server 2003 and Windows XP:** This value is not available until Windows XP with SP2 and Windows Server 2003 with SP1. |
| **PAGE_EXECUTE_WRITECOPY**<br><br>0x80 | Allows views to be mapped for read-only, copy-on-write, or execute access. This value is equivalent to **PAGE_EXECUTE_READ**.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** and **GENERIC_EXECUTE** access rights.<br><br>**Windows Vista:** This value is not available until Windows Vista with SP1.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **PAGE_READONLY**<br><br>0x02 | Allows views to be mapped for read-only or copy-on-write access. An attempt to write to a specific region results in an access violation.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** access right. |
| **PAGE_READWRITE**<br><br>0x04 | Allows views to be mapped for read-only, copy-on-write, or read/write access.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** and **GENERIC_WRITE** access rights. |
| **PAGE_WRITECOPY**<br><br>0x08 | Allows views to be mapped for read-only or copy-on-write access. This value is equivalent to **PAGE_READONLY**.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** access right. |

### `AllocationAttributes`

Type: \_In\_ **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

You can specify one or more of the following attributes for the file mapping object. Also see the *PageProtection* parameter.

| Value | Meaning |
| --- | --- |
| **SEC_COMMIT**<br><br>0x8000000 | If the file mapping object is backed by the operating system paging file (the *hfile* parameter is **INVALID_HANDLE_VALUE**), specifies that when a view of the file is mapped into a process address space, the entire range of pages is committed rather than reserved. The system must have enough committable pages to hold the entire mapping. Otherwise, **CreateFileMapping** fails.<br><br>This attribute has no effect for file mapping objects that are backed by executable image files or data files (the *hfile* parameter is a handle to a file).<br><br>**SEC_COMMIT** cannot be combined with **SEC_RESERVE**.<br><br>If no attribute is specified, **SEC_COMMIT** is assumed. |
| **SEC_IMAGE**<br><br>0x1000000 | Specifies that the file that the *hFile* parameter specifies is an executable image file.<br><br>The **SEC_IMAGE** attribute must be combined with a page protection value such as **PAGE_READONLY**. However, this page protection value has no effect on views of the executable image file. Page protection for views of an executable image file is determined by the executable file itself.<br><br>No other attributes are valid with **SEC_IMAGE**. |
| **SEC_IMAGE_NO_EXECUTE**<br><br>0x11000000 | Specifies that the file that the *hFile* parameter specifies is an executable image file that will not be executed and the loaded image file will have no forced integrity checks run. Additionally, mapping a view of a file mapping object created with the **SEC_IMAGE_NO_EXECUTE** attribute will not invoke driver callbacks registered using the [PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/nf-ntddk-pssetloadimagenotifyroutine) kernel API.<br><br>The **SEC_IMAGE_NO_EXECUTE** attribute must be combined with the **PAGE_READONLY** page protection value. No other attributes are valid with **SEC_IMAGE_NO_EXECUTE**.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows Server 2012 and Windows 8. |
| **SEC_LARGE_PAGES**<br><br>0x80000000 | Enables large pages to be used for file mapping objects that are backed by the operating system paging file (the *hfile* parameter is **INVALID_HANDLE_VALUE**). This attribute is not supported for file mapping objects that are backed by executable image files or data files (the *hFile* parameter is a handle to an executable image or data file).<br><br>The maximum size of the file mapping object must be a multiple of the minimum size of a large page returned by the [GetLargePageMinimum](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-getlargepageminimum) function. If it is not, **CreateFileMapping** fails. When mapping a view of a file mapping object created with **SEC_LARGE_PAGES**, the base address and view size must also be multiples of the minimum large page size.<br><br>**SEC_LARGE_PAGES** requires the [SeLockMemoryPrivilege](https://learn.microsoft.com/windows/win32/SecAuthZ/authorization-constants) privilege to be enabled in the caller's token.<br><br>If **SEC_LARGE_PAGES** is specified, **SEC_COMMIT** must also be specified.<br><br>**Windows Server 2003:** This value is not supported until Windows Server 2003 with SP1.<br><br>**Windows XP:** This value is not supported. |
| **SEC_NOCACHE**<br><br>0x10000000 | Sets all pages to be non-cacheable.<br><br>Applications should not use this attribute except when explicitly required for a device. Using the interlocked functions with memory that is mapped with **SEC_NOCACHE** can result in an **EXCEPTION_ILLEGAL_INSTRUCTION** exception.<br><br>**SEC_NOCACHE** requires either the **SEC_RESERVE** or **SEC_COMMIT** attribute to be set. |
| **SEC_RESERVE**<br><br>0x4000000 | If the file mapping object is backed by the operating system paging file (the *hfile* parameter is **INVALID_HANDLE_VALUE**), specifies that when a view of the file is mapped into a process address space, the entire range of pages is reserved for later use by the process rather than committed.<br><br>Reserved pages can be committed in subsequent calls to the [VirtualAlloc](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc) function. After the pages are committed, they cannot be freed or decommitted with the [VirtualFree](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfree) function.<br><br>This attribute has no effect for file mapping objects that are backed by executable image files or data files (the *hfile* parameter is a handle to a file).<br><br>**SEC_RESERVE** cannot be combined with **SEC_COMMIT**. |
| **SEC_WRITECOMBINE**<br><br>0x40000000 | Sets all pages to be write-combined.<br><br>Applications should not use this attribute except when explicitly required for a device. Using the interlocked functions with memory that is mapped with **SEC_WRITECOMBINE** can result in an **EXCEPTION_ILLEGAL_INSTRUCTION** exception.<br><br>**SEC_WRITECOMBINE** requires either the **SEC_RESERVE** or **SEC_COMMIT** attribute to be set.<br><br>**Windows Server 2003 and Windows XP:** This flag is not supported until Windows Vista. |

### `MaximumSize`

Type: \_In\_ **[ULONG64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum size of the file mapping object.

If this parameter is 0 (zero), then the maximum size of the file mapping object is equal to the current size of the file that *hFile* identifies.

An attempt to map a file with a length of 0 (zero) fails with an error code of **ERROR_FILE_INVALID**. You should test for files with a length of 0 (zero), and reject those files.

### `Name`

Type: \_In_opt\_ **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The name of the file mapping object.

If this parameter matches the name of an existing mapping object, then the function requests access to the object with the protection that *flProtect* specifies.

If this parameter is **NULL**, then the file mapping object is created without a name.

If *lpName* matches the name of an existing event, semaphore, mutex, waitable timer, or job object, the function fails, and the [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_INVALID_HANDLE**. This occurs because these objects share the same namespace.

The name can have a "Global\" or "Local\" prefix to explicitly create the object in the global or session namespace. The remainder of the name can contain any character except the backslash character (\\). Creating a file mapping object in the global namespace from a session other than session zero requires the [SeCreateGlobalPrivilege](https://learn.microsoft.com/windows/win32/SecAuthZ/authorization-constants) privilege. For more information, see [Kernel Object Namespaces](https://learn.microsoft.com/windows/win32/TermServ/kernel-object-namespaces).

Fast user switching is implemented by using Terminal Services sessions. The first user to log on uses session 0 (zero), the next user to log on uses session 1 (one), and so on. Kernel object names must follow the guidelines that are outlined for Terminal Services so that applications can support multiple users.

### `ExtendedParameters`

Type: \_Inout\_updates\_opt\_(ParameterCount) **[MEM_EXTENDED_PARAMETER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_extended_parameter)\***

An optional pointer to one or more extended parameters of type [MEM_EXTENDED_PARAMETER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-mem_extended_parameter). Each of those extended parameter values can itself have a *Type* field of either **MemExtendedParameterAddressRequirements** or **MemExtendedParameterNumaNode**. If no **MemExtendedParameterNumaNode** extended parameter is provided, then the behavior is the same as for the [VirtualAlloc](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc)/[MapViewOfFile](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile) functions (that is, the preferred NUMA node for the physical pages is determined based on the ideal processor of the thread that first accesses the memory).

### `ParameterCount`

_In_ ULONG ParameterCount

The number of extended parameters pointed to by *ExtendedParameters*.

## Return value

If the function succeeds, the return value is a handle to the newly created file mapping object.

If the object exists before the function call, the function returns a handle to the existing object (with its current size, not the specified size), and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_ALREADY_EXISTS**.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

See the **Remarks** for [CreateFileMapping](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-createfilemappingw#remarks).

## Examples

For an example, see [Creating named shared memory](https://learn.microsoft.com/windows/win32/memory/creating-named-shared-memory), or [Creating a file mapping using large pages](https://learn.microsoft.com/windows/win32/Memory/creating-a-file-mapping-using-large-pages).

## See also

[CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle)

[CreateFileMappingNuma](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createfilemappingnumaa)

[Creating a file mapping object](https://learn.microsoft.com/windows/win32/Memory/creating-a-file-mapping-object)

[DuplicateHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-duplicatehandle)

[MapViewOfFile](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile)

[MapViewOfFileEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex)

[Memory management functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[OpenFileMapping](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-openfilemappinga)

[ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[UnmapViewOfFile](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile)

[VirtualAlloc](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc)

[WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile)