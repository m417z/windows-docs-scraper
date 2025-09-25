# PFN_IDDCXSWAPCHAINSETDEVICE callback function

## Description

**PFN_IDDCXSWAPCHAINSETDEVICE** is a pointer to an OS callback function that sets up the swap-chain with a particular DXGI device.

## Parameters

### `DriverGlobals` [in]

Contains system-defined per-driver data.

### `SwapChainObject` [in]

The swap-chain object passed to the EVT_IDD_CX_MONITOR_SET_SWAPCHAIN call.

### `pInArgs` [in]

Input arguments to the function.

## Return value

If the routine succeeds it returns S_OK. Otherwise, it returns an appropriate error code.

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call[**IddCxSwapChainSetDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainsetdevice).

## See also

[**IddCxSwapChainSetDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainsetdevice)