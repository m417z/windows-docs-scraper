# FltSupportsStreamContexts function

## Description

**FltSupportsStreamContexts** determines whether stream contexts are supported on a given file object.

## Parameters

### `FileObject` [in]

Pointer to the file object to test.

## Return value

**FltSupportsStreamContexts** returns **TRUE** if the file system supports stream contexts for the file object; **FALSE** otherwise.

## Remarks

Paging files do not currently support file, stream, or stream handle contexts.

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamcontext)

[**FltGetStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamcontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamcontext)

[**FltSupportsStreamHandleContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsstreamhandlecontexts)