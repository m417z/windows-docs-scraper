# IDCompositionDeviceDebug::EnableDebugCounters

## Description

Enables display of performance debugging counters.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

Performance counters are displayed on the top-right corner of the screen. From left to right, Microsoft DirectComposition displays the following information:

* The composition engine frame rate, in frames per second, averaged over the last 60 composition frames
* The overall CPU usage of the composition thread, in milliseconds

The DirectComposition composition engine operates on the entire desktop all at once, so the performance counters measure the total cost of desktop composition, not just the cost of any one particular application. If the application occupies the entire screen, however, it is reasonable to assume that all of the composition cost is due to that one application.

## See also

[IDCompositionDeviceDebug](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevicedebug)

[IDCompositionDeviceDebug::DisableDebugCounters](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevicedebug-disabledebugcounters)

[IDCompositionVisualDebug](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisualdebug)