# _FA_ENTRY structure

## Description

A [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object has a collection of [failure analysis entries](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) (FA entries). Each FA entry is represented by an **FA_ENTRY** structure. For more information, see [Failure Analysis Entries, Tags, and Data Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze).

## Members

### `Tag`

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

### `FullSize`

The size of the of [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries), which includes the size of the **FA_ENTRY** structure and the size of the FA entry's data block.

### `DataSize`

The size of the [FA entry's](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) data block.

## See also

[Failure Analysis Entries](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)