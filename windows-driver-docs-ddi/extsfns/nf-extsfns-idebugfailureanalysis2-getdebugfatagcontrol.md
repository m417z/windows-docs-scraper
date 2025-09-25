# IDebugFailureAnalysis2::GetDebugFATagControl

## Description

The **GetDebugFATagControl** method gets a pointer to an [IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) interface, which provides access to the tags in a DebugFailureAnalysisTags object. For information about the relationship between a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object and a [DebugFailureAnalysisTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) object, see [Failure Analysis Entries, Tags, and Data Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze).

## Parameters

### `FATagControl` [out]

A pointer to a variable that receives a pointer to the [IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) interface.

## Return value

This method does not return a value.

## See also

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)