# IDebugFAEntryTags::SetType

## Description

The **SetType** method sets the data type that is associated with a tag in a [DebugFailureAnalysisTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) object.

## Parameters

### `Tag` [in]

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

### `EntryType` [in]

A value in the [FA_ENTRY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

## Return value

If this method successfully sets the data type of *Tag* to *EntryType*, it returns **S_OK**. Otherwise, it returns **E_INVALIDARG**.

## Remarks

This method checks to see whether the data type for *Tag* has already been set. If the data type has not already been set, this method sets the data type to *EntryType*.

If the data type for *Tag* has already been set, this method checks to see whether *EntryType* is compatible with the data type that has already been set. If the data types are compatible, this method sets (overwrites) the data type for *Tag* to *EntryType*. If the data types are not compatible, this method returns **E_INVALIDARG** and does not set the data type.

The data types **DEBUG_FA_ENTRY_ULONG64**, **DEBUG_FA_ENTRY_INSTRUCTION_OFFSET**, and **DEBUG_FA_ENTRY_POINTER** are compatible.

The data types **DEBUG_FA_ENTRY_ANSI_STRING** and **DEBUG_FA_ENTRY_EXTENSION_CMD** are compatible.

## See also

[GetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfaentrytags-gettype)

[IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)