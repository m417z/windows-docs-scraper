# FsRtlCreateSectionForDataScan function

## Description

The **FsRtlCreateSectionForDataScan** routine creates a section object. Use this routine with extreme caution. (See the following *Remarks* section.)

## Parameters

### `SectionHandle` [out]

Pointer to a caller-allocated variable that receives an opaque handle to the section object.

### `SectionObject` [out]

Pointer to a caller-allocated variable that receives an opaque pointer to the section object.

### `SectionFileSize` [out, optional]

Pointer to a caller-allocated variable that receives the size, in bytes, of the file at the time the section object was created. This parameter is optional and can be **NULL**.

### `FileObject` [in]

File object for an open file. The section object will be backed by the specified file. This parameter is required and cannot be **NULL**.

### `DesiredAccess` [in]

Specifies the desired access for the section object as one or more of the following [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) flags.

| *DesiredAccess* flag | Allows caller to |
| --- | --- |
| SECTION_MAP_READ | Read views of the section. |
| SECTION_MAP_WRITE | Write views of the section. |
| SECTION_QUERY | Query the section object for information about the section. Drivers should set this flag. |
| SECTION_ALL_ACCESS | All actions defined by the previous flags as well as that defined by STANDARD_RIGHTS_REQUIRED. (For more information about STANDARD_RIGHTS_REQUIRED, see [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask).) |

### `ObjectAttributes` [in, optional]

Pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) macro to initialize this structure. Because **FsRtlCreateSectionForDataScan** inserts this object into the process handle table, the caller must specify the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**.

### `MaximumSize` [in, optional]

This parameter is reserved for future use.

### `SectionPageProtection` [in]

Specifies the protection to place on each page in the section. Specify one of the following values. This parameter is required and cannot be zero.

| Flag | Meaning |
| --- | --- |
| PAGE_READONLY | Enables read-only access to the committed region of pages. An attempt to write to the committed region results in an access violation. If the system differentiates between read-only access and execute access, an attempt to execute code in the committed region results in an access violation. |
| PAGE_READWRITE | Enables both read and write access to the committed region of pages. |

### `AllocationAttributes` [in]

Bitmasks of the SEC_*XXX* flags determine the allocation attributes of the section. Specify one or more of the following values. This parameter is required and cannot be zero.

| Flag | Meaning |
| --- | --- |
| SEC_COMMIT | Allocates physical storage in memory or in the paging file on disk for all pages of a section. This is the default setting. Note that this flag is required and cannot be omitted. |
| SEC_FILE | The file specified by the *FileObject* parameter is a mapped file. |

### `Flags` [in]

This parameter is reserved for future use.

## Return value

**FsRtlCreateSectionForDataScan** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_END_OF_FILE** | The size of the file specified by the FileObject parameter is zero. This is an error code. |
| **STATUS_FILE_LOCK_CONFLICT** | The file specified by the FileObject parameter is locked. This is an error code. |
| **STATUS_INSUFFICIENT_RESOURCES** | FsRtlCreateSectionForDataScan encountered a pool allocation failure. This is an error code. |
| **STATUS_INVALID_FILE_FOR_SECTION** | The file specified by the FileObject parameter does not support sections. This is an error code. |
| **STATUS_INVALID_PARAMETER_8** | The value specified for the SectionPageProtection parameter is invalid. This is an error code. |
| **STATUS_INVALID_PARAMETER_9** | The caller specified an invalid value for the AllocationAttributes parameter. This is an error code. |
| **STATUS_PRIVILEGE_NOT_HELD** | The caller did not have the required privilege to create a section object with the access specified in the DesiredAccess parameter. This is an error code. |

## Remarks

**Important** The **FsRtlCreateSectionForDataScan** routine should only be used in cases where a handle to the file object specified in the *FileObject* parameter has not yet been created (typically while processing a post-create operation). If the driver has a handle to the file object or can obtain a handle to the file object, the driver should use the [ZwCreateSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection) routine instead.

Once the section object created by this routine is no longer necessary, be sure to close the section object's handle (*SectionHandle*) by calling the [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) routine and dereference the section object itself (*SectionObject*) by calling the [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) routine.

For more information on creating mapped sections and views of memory, see [Section Objects and Views](https://learn.microsoft.com/windows-hardware/drivers/kernel/section-objects-and-views). Also see the documentation for the **CreateFileMapping** routine in the Microsoft Windows SDK.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[CcPurgeCacheSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)

[MmFlushImageSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-mmflushimagesection)

[MmForceSectionClosed](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-mmforcesectionclosed)

[ZwCreateSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection)