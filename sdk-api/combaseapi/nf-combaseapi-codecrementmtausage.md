# CoDecrementMTAUsage function

## Description

Releases the increment made by a previous call to the [CoIncrementMTAUsage](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coincrementmtausage) function.

## Parameters

### `Cookie` [in]

A **PVOID** variable that was set by a previous call to the [CoIncrementMTAUsage](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coincrementmtausage) function.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*Cookie* must be a valid value returned by a successful previous call to the [CoIncrementMTAUsage](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coincrementmtausage) function. If the overall count of MTA usage reaches 0, including both through this API and through the [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) and [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) functions, the system frees resources related to MTA support.

You can call [CoIncrementMTAUsage](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coincrementmtausage) from one thread and **CoDecrementMTAUsage** from another as long as a cookie previously returned by **CoIncrementMTAUsage** is passed to **CoDecrementMTAUsage**.

Don't call **CoDecrementMTAUsage** during process shutdown or inside dllmain. You can call **CoDecrementMTAUsage** before the call to start the shutdown process.

## See also

[CoIncrementMTAUsage](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coincrementmtausage)