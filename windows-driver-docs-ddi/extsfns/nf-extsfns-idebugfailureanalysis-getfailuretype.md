# IDebugFailureAnalysis2::GetFailureType

## Description

The **GetFailureType** method gets the failure type of a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object. The failure type indicates whether the code being analyzed was running in kernel mode or user mode.

## Return value

This method returns a value in the [DEBUG_FAILURE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ne-extsfns-_debug_failure_type) enumeration.

## See also

**GetFailureClass**

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)