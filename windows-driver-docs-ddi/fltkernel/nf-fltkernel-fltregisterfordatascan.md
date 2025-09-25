# FltRegisterForDataScan function

## Description

The **FltRegisterForDataScan** routine enables data scanning for the volume attached to the minifilter instance.

## Parameters

### `Instance` [in]

An opaque instance pointer for the minifilter driver instance to register for data scanning.

## Return value

**FltRegisterForDataScan** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following.

| Return code | Description |
| ----------- | ----------- |
| STATUS_NOT_SUPPORTED | The filter manager does not support data scans for the volume attached to this instance. |

## Remarks

A minifilter that does data scanning must register its volume for scanning by calling **FltRegisterForDataScan** prior to calling [**FltCreateSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan). Minifilters do data scans for various reasons, such as virus detection, encryption, or compression.

> [!NOTE]
>
> If **FltRegisterForDataScan** returns STATUS_NOT_SUPPORTED, a minifilter can still create sections for data scanning by calling [**FsRtlCreateSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlcreatesectionfordatascan). However, access to the section created by **FsRtlCreateSectionForDataScan** is not synchronized, and it is the calling minifilter's responsibility to handle any conflict resolution that arises. Such a minifilter must implement and register a [**PFLT_SECTION_CONFLICT_NOTIFICATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_section_conflict_notification_callback) callback routine that can be called when section conflict occurs.

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltCloseSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosesectionfordatascan)

[**FltCreateSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan)

[**FsRtlCreateSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlcreatesectionfordatascan)

[**PFLT_SECTION_CONFLICT_NOTIFICATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_section_conflict_notification_callback)