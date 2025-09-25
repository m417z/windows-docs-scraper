# FltSupportsStreamHandleContexts function

## Description

**FltSupportsStreamHandleContexts** determines whether stream handle contexts are supported on a given file object.

## Parameters

### `FileObject` [in]

Pointer to the file object to test.

## Return value

**FltSupportsStreamHandleContexts** returns **TRUE** if the file system supports stream handle contexts for the file object; **FALSE** otherwise.

## Remarks

Paging files do not currently support file, stream, or stream handle contexts.

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamhandlecontext)

[**FltGetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamhandlecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamhandlecontext)

[**FltSupportsStreamContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsstreamcontexts)