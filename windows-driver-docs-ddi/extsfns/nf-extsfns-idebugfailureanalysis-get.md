# IDebugFailureAnalysis::Get

## Description

 The **Get** method searches a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis) object for the first [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) that has a specified tag.

## Parameters

### `Tag` [in]

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

## Return value

If the [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureAnalysis) object has any [FA entries](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) that have the specified tag, this method returns a pointer to the first [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure that has the specified tag. If the **DebugFailureAnalysis** object does not have any FA entries that have the specified tag, this method returns **NULL**.

## See also

[GetNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getnext)

[IDebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis)

[NextEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-nextentry)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)