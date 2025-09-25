# IDebugFailureAnalysis2::SetBuffer

## Description

The **SetBuffer** method searches a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object for the first [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) that has a specified tag. If it finds an FA entry with the specified tag, it overwrites the data block of the FA entry with the bytes in a specified buffer. If this method does not find an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) that has the specified tag, it creates a new FA entry with that tag and overwrites the data block of the new FA entry with the data in the specified buffer.

## Parameters

### `Tag`

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

### `EntryType` [in]

A value in the [FA_ENTRY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration. This parameter specifies the data type of the data in *Buf*.

### `Buf` [in]

A pointer to a buffer that contains the bytes to be written to the data block of the new or existing [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries).

### `Size` [in]

The size, in bytes, of the buffer pointed to by *Buf*.

## Return value

If this method succeeds, it returns a pointer to the new or existing [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. Otherwise, it returns **NULL**.

## Remarks

If this method finds an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) with the specified tag, it checks to see whether the data type associated with that tag is compatible with the data type specified by *EntryType*. For example, **DEBUG_FA_ENTRY_ULONG64**, **DEBUG_FA_ENTRY_INSTRUCTION_OFFSET**, and **DEBUG_FA_ENTRY_POINTER** are all compatible with each other. Likewise, **DEBUG_FA_ENTRY_ANSI_STRING** and **DEBUG_FA_ENTRY_EXTENSION_CMD** are compatible with each other. If the data types are not compatible, this method returns **NULL** and does not overwrite the entry's data block.

If this method does not find an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) with the specified tag, it creates a new FA entry with that tag, and it associates the tag with the data type specified by *EntryType*.

## See also

[AddBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-addbuffer)

[GetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getbuffer)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)