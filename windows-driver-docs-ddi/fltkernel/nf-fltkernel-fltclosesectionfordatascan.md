# FltCloseSectionForDataScan function

## Description

The **FltCloseSectionForDataScan** routine closes a section object associated with a file stream.

## Parameters

### `SectionContext` [in]

A pointer to the section context to close.

## Return value

**FltCloseSectionForDataScan** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The section context was not properly created. An allocated section context must first be passed to [FltCreateSectionForDataScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan). This is an error code. |
| **STATUS_NOT_FOUND** | The section context is already closed. |

## Remarks

Minifilters use the **FltCloseSectionForDataScan** routine to deallocate and remove a section context from a file object. All previously allocated section contexts passed to [FltCreateSectionForDataScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan) must be passed to **FltCloseSectionForDataScan**. Otherwise, minifilters can call [FltReleaseContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) if the section context was allocated with [FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext) but no section was created with **FltCreateSectionForDataScan**.

After **FltCloseSectionForDataScan** returns, operations that conflict with the section described by *SectionContext* will not be synchronized by the filter manager.

## See also

[FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[FltCreateSectionForDataScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan)

[FltDeleteContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)