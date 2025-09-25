## Description

The **ZwCreateSection** routine creates a [section object](https://learn.microsoft.com/windows-hardware/drivers/kernel/section-objects-and-views).

## Parameters

### `SectionHandle` [out]

Pointer to a HANDLE variable that receives a handle to the section object.

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that determines the requested access to the object. In addition to the access rights that are defined for all types of objects (see [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)), the caller can specify any of the following access rights, which are specific to section objects:

| *DesiredAccess* flag | Allows caller to do this |
|---|---|
| SECTION_EXTEND_SIZE | Dynamically extend the size of the section. |
| SECTION_MAP_EXECUTE | Execute views of the section. |
| SECTION_MAP_READ | Read views of the section. |
| SECTION_MAP_WRITE | Write views of the section. |
| SECTION_QUERY | Query the section object for information about the section. Drivers should set this flag. |
| SECTION_ALL_ACCESS | All of the previous flags combined with STANDARD_RIGHTS_REQUIRED. |

### `ObjectAttributes` [in, optional]

Pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**.

### `MaximumSize` [in, optional]

Specifies the maximum size, in bytes, of the section. **ZwCreateSection** rounds this value up to the nearest multiple of PAGE_SIZE. If the section is backed by the paging file, *MaximumSize* specifies the actual size of the section. If the section is backed by an ordinary file, *MaximumSize* specifies the maximum size that the file can be extended or mapped to.

### `SectionPageProtection` [in]

Specifies the protection to place on each page in the section. Use one of the following four values: PAGE_READONLY, PAGE_READWRITE, PAGE_EXECUTE, or PAGE_WRITECOPY. For a description of these values, see [CreateFileMapping](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createfilemappinga).

### `AllocationAttributes` [in]

Specifies a bitmask of SEC_*XXX* flags that determines the allocation attributes of the section. For a description of these flags, see [CreateFileMapping](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createfilemappinga).

### `FileHandle` [in, optional]

Optionally specifies a handle for an open file object. If the value of *FileHandle* is **NULL**, the section is backed by the paging file. Otherwise, the section is backed by the specified file.

## Return value

**ZwCreateSection** returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure. Possible error status codes include the following:

| Return code | Description |
|---|---|
| **STATUS_FILE_LOCK_CONFLICT** | The file specified by the *FileHandle* parameter is locked. |
| **STATUS_INVALID_FILE_FOR_SECTION** | The file specified by *FileHandle* does not support sections. |
| **STATUS_INVALID_PAGE_PROTECTION** | The value specified for the *SectionPageProtection* parameter is invalid. |
| **STATUS_MAPPED_FILE_SIZE_ZERO** | The size of the file specified by *FileHandle* is zero, and *MaximumSize* is zero. |
| **STATUS_SECTION_TOO_BIG** | The value of *MaximumSize* is too big. This occurs when either *MaximumSize* is greater than the system-defined maximum for sections, or if *MaximumSize* is greater than the specified file and the section is not writable. |

## Remarks

Once the handle pointed to by *SectionHandle* is no longer in use, the driver must call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close it.

If the caller is not running in a system thread context, it must ensure that any handles it creates are private handles. Otherwise, the handle can be accessed by the process in whose context the driver is running. For more information, see [Object Handles](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-handles).

For more information about setting up mapped sections and views of memory, see [Sections and Views](https://learn.microsoft.com/windows-hardware/drivers/kernel/section-objects-and-views).

If the call to this function occurs in user mode, you should use the name "**NtCreateSection**" instead of "**ZwCreateSection**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[CreateFileMapping](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createfilemappinga)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwMapViewOfSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwmapviewofsection)

[ZwOpenSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopensection)

[ZwUnmapViewOfSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwunmapviewofsection)