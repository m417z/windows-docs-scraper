# _DEBUG_FAILURE_TYPE enumeration

## Description

The values in the **DEBUG_FAILURE_TYPE** enumeration indicate the type of a failure.

## Constants

### `DEBUG_FLR_UNKNOWN`

The failure type is not known.

### `DEBUG_FLR_KERNEL`

The failing code was running in kernel mode.

### `DEBUG_FLR_USER`

The failing code was running in user mode.

## See also

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)