# IDebugFailureAnalysis::GetString method

## Description

The **GetString** method searches a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object for the first [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) that has a specified tag. If it finds an FA entry with the specified tag, it gets the ANSI string value from the entry's data block.

## Parameters

### `Tag` [in]

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

### `Str` [out]

A pointer to a buffer that receives the string value from the entry's data block.

### `MaxSize` [in]

The size, in bytes, of the buffer pointed to by *Str*.

## Return value

If this method finds an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) with the specified tag, and if it succeeds in getting the data block, it returns a pointer to the [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. Otherwise, it returns **NULL**.

## Remarks

This method copies a null-terminated string from the entry's data block to the buffer pointed to by *Str*. This method copies at most *MaxSize* characters including the NULL terminator.

Each tag that has already been used in a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object is associated with one of the data types in the [FA_ENTRY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ne-extsfns-_fa_entry_type) enumeration. To determine the data type associated with a tag, call the [GetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfaentrytags-gettype) method of the [IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) interface. To get a pointer to an IDebugFAEntryTags interface, call the [GetDebugFATagControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-getdebugfatagcontrol) method of the **IDebugFailureAnalysis2** interface.

The appropriate use of this method is get the data block from an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) that has a data type of **DEBUG_FA_ENTRY_ANSI_STRING**.

## See also

[AddString](https://learn.microsoft.com/windows-hardware/drivers/print/iprinterbidischemaresponses-addstring)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[SetString](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-setstring)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)