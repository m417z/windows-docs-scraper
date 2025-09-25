# IDebugFailureAnalysis2::AddBuffer

## Description

The **AddBuffer** method adds a new [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) to a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object, and writes the bytes from a specified buffer to the data block of the new FA entry.

## Parameters

### `Tag`

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

### `EntryType` [in]

A value in the [FA_ENTRY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration. This parameter specifies the data type of the data in *Buf*.

### `Buf` [in]

A pointer to a buffer that contains the bytes to be written to the data block of the new [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries).

### `Size` [in]

The size, in bytes, of the buffer pointed to by *Buf*.

## Return value

If this method succeeds, it returns a pointer to the new [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. Otherwise, it returns **NULL**.

## Remarks

This method creates a new [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) with the tag specified by *Tag*, and it associates the tag with the data type specified by *EntryType*.

## See also

[GetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getbuffer)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[SetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-setbuffer)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)