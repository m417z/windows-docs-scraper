# FltCreateSectionForDataScan function

## Description

The **FltCreateSectionForDataScan** routine creates a section object for a file. The filter manager can optionally synchronize I/O with the section created.

## Parameters

### `Instance` [in]

The opaque instance pointer for the minifilter driver instance whose context is to be retrieved.

### `FileObject` [in]

The file object for an open file. The section object will be backed by the specified file. This parameter is required and cannot be NULL.

### `SectionContext` [in]

A pointer to a previously allocated section context.

### `DesiredAccess` [in]

The type of access for the section object as one or more of the following [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) flags.

| Flag | Allows caller to |
| ---- | ---------------- |
| SECTION_MAP_READ | Read views of the section. |
| SECTION_MAP_WRITE | Write views of the section. |
| SECTION_QUERY | Query the section object for information about the section. Drivers should set this flag. |
| SECTION_ALL_ACCESS | All actions defined by the previous flags as well as that defined by STANDARD_RIGHTS_REQUIRED. For more information about STANDARD_RIGHTS_REQUIRED, see [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask). |

### `ObjectAttributes` [in, optional]

A pointer to an optional [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use the [**InitializeObjectAttributes**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) macro to initialize this structure.

### `MaximumSize` [in, optional]

This parameter is reserved for future use.

### `SectionPageProtection` [in]

The protection to place on each page in the section. Specify one of the following values. This parameter is required and cannot be zero.

| Flag | Meaning |
| ---- | ------- |
| PAGE_READONLY | Enables read-only access to the committed region of pages. An attempt to write to the committed region results in an access violation. If the system differentiates between read-only access and execute access, an attempt to execute code in the committed region results in an access violation. |
| PAGE_READWRITE | Enables both read and write access to the committed region of pages. |

### `AllocationAttributes` [in]

Bitmasks of the SEC_*XXX* flags determine the allocation attributes of the section. Specify one or more of the following values. This parameter is required and cannot be zero.

| Flag | Meaning |
| ---- | ------- |
| SEC_COMMIT | Allocates physical storage in memory or in the paging file on disk for all pages of a section. This is the default setting. Note that this flag is required and cannot be omitted. |
| SEC_FILE | The file specified by the **FileObject** parameter is a mapped file. |

### `Flags` [in]

This parameter is reserved for future use.

### `SectionHandle` [out]

A pointer to a caller-allocated variable that receives an opaque handle to the section. By default, the section handle is a user handle. If the caller needs a kernel handle, they must pass in a pointer to an initialized [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure in the **ObjectAttributes** parameter with the OBJ_KERNEL_HANDLE flag set.

### `SectionObject` [out]

A pointer to a caller-allocated variable that receives an opaque pointer to the section object.

### `SectionFileSize` [out, optional]

A pointer to a caller-allocated variable that receives the size, in bytes, of the file at the time the section object was created. This parameter is optional and can be NULL.

## Return value

**FltCreateSectionForDataScan** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following.

| Return code | Description |
| ----------- | ----------- |
| STATUS_END_OF_FILE | The size of the file specified by the **FileObject** parameter is zero. |
| STATUS_FILE_LOCK_CONFLICT | The file specified by the **FileObject** parameter is locked. |
| STATUS_INSUFFICIENT_RESOURCES | **FltCreateSectionForDataScan** encountered a pool allocation failure. |
| STATUS_INVALID_FILE_FOR_SECTION | The file specified by the **FileObject** parameter does not support sections. |
| STATUS_INVALID_PARAMETER | The minifilter is not registered. |
| STATUS_INVALID_PARAMETER_8 | The value specified for the **SectionPageProtection** parameter is invalid. |
| STATUS_INVALID_PARAMETER_9 | The caller specified an invalid value for the **AllocationAttributes** parameter. |
| STATUS_NOT_SUPPORTED | The volume attached to this instance does not support section contexts. |
| STATUS_PRIVILEGE_NOT_HELD | The caller did not have the required privileges to create a section object with the access specified in the **DesiredAccess** parameter. |
| STATUS_FILE_IS_A_DIRECTORY | The file specified by the **FileObject** parameter is a directory. |
| STATUS_FLT_CONTEXT_ALREADY_DEFINED | The filter instance specified by **Instance** already has an open section for the stream. Only one section per stream, and therefore, per instance is supported. |

## Remarks

Prior to calling **FltCreateSectionForDataScan**, a minifilter must first register its volume for data scanning by calling [**FltRegisterForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfordatascan). As with other filter context elements, **SectionContext** is first allocated with [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

**FltCreateSectionForDataScan** inserts the handle to the object (**SectionHandle**) into the process handle table for the thread that **FltCreateSectionForDataScan** is called on.

Handles can be either user handles or kernel handles. A handle created with OBJ_KERNEL_HANDLE set in the [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that **ObjectAttributes** points to is a kernel handle, and can only be accessed from kernel mode. A handle created without the OBJ_KERNEL_HANDLE flag is a user handle, which can be accessed from user or kernel mode. A filter can create a user handle and then pass it to a user-mode application for processing. For example, a virus scanning engine can live in a user-mode application and be fed user handles from a file system filter.

Certain situations can occur where holding a section open is incompatible with current file I/O. In particular, file I/O that triggers a cache purge can cause cache incoherency if the cache purge is prevented because of an open section. A minifilter can provide an optional callback routine for notifications of these events. The minifilter driver implements a [**PFLT_SECTION_CONFLICT_NOTIFICATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_section_conflict_notification_callback) to receive these notifications. Conflict notifications are enabled if the **SectionNotificationCallback** member of [**FLT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) is set to this callback routine when the minifilter is registered. When a notification is received, the section can be closed to allow the conflicting I/O operation to continue.

> [!NOTE]
> A section notification callback might occur before **FltCreateSectionForDataScan** returns. A minifilter must be able to receive the callback and handle the case where **SectionHandle** and **SectionObject** are not yet valid.

When the section object created by this routine is no longer necessary, be sure to close the section object's handle (**SectionHandle**) by calling the [**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) routine and dereference the section object itself (**SectionObject**) by calling the [**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) routine.

For overview information on creating mapped sections and views of memory, see [Section Objects and Views](https://learn.microsoft.com/windows-hardware/drivers/kernel/section-objects-and-views). Also, see the documentation for the **CreateFileMapping** routine in the Microsoft Windows SDK.

> [!IMPORTANT]
> Minifilters must not explicitly delete a section context passed to **FltCreateSectionForDataScan**. Do not call [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext) after a section context is passed to **FltCreateSectionForDataScan**. A section context is deallocated and removed from a stream by calling [**FltCloseSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosesectionfordatascan) in this case.
>
> In general, sections should be created as read-only. In particular, if a read-only file is in a transaction and a minifilter does not create a read-only section, a write to the section is discarded and is not included as part of the transaction.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[**CcPurgeCacheSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)

[**FLT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltCloseSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosesectionfordatascan)

[**FltRegisterForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfordatascan)

[**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[**PFLT_SECTION_CONFLICT_NOTIFICATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_section_conflict_notification_callback)

[**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[**ZwCreateSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection)