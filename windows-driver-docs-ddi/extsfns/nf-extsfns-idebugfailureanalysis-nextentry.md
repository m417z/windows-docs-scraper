# IDebugFailureAnalysis::NextEntry

## Description

The **NextEntry** method gets the next [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries), after a given FA entry, in a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis) object.

## Parameters

### `Entry`

A pointer to an [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. This method returns the next entry after this entry. If this parameter is **NULL**, this method returns the first **FA_ENTRY** in the [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis) object.

## Return value

This method returns a pointer to the next (or first) [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. If there are no more [FA entries](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) in the [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis) object, this method returns *NULL*.

## See also

[Get](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-get)

[GetNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getnext)

[IDebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)