# _FA_EXTENSION_PLUGIN_PHASE enumeration

## Description

A value in the **FA_EXTENSION_PLUGIN_PHASE** enumeration is passed to the [_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin) function to specify which phase of the analysis is currently in progress.

## Constants

### `FA_PLUGIN_INITIALIZATION`

The analysis is in the initialization phase. This is after the primary data such as exception record (for user mode) or bugcheck code (for kernel mode) is initialized.

### `FA_PLUGIN_STACK_ANALYSIS`

The analysis is in the stack analysis phase. This is after the stack is analyzed, and the analysis engine has the information, if it was available on the stack, about the faulting symbol and module.

### `FA_PLUGIN_PRE_BUCKETING`

The analysis is in the prebucketing phase. This is just before the analysis engine generates a bucket.

### `FA_PLUGIN_POST_BUCKETING`

The analysis is in the post bucketing phase. This is just after the analysis engine generates a bucket.

## See also

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)