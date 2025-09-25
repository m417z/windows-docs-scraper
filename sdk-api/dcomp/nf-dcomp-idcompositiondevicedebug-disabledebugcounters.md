# IDCompositionDeviceDebug::DisableDebugCounters

## Description

Disables display of performance debugging counters.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

Microsoft DirectComposition keeps a count of how many DirectComposition devices have performance counters enabled, for the entire desktop session. If the count is non-zero, the performance counters are displayed. Therefore, disabling the counters may not make them go away if another device is also requesting display of the counters.

## See also

[IDCompositionDeviceDebug](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevicedebug)

[IDCompositionDeviceDebug::EnableDebugCounters](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevicedebug-enabledebugcounters)