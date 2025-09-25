## Description

**PFN_IDDCXSWAPCHAINRELEASEANDACQUIRESYSTEMBUFFER** is a pointer to an OS callback function through which to release and acquire buffers from a swapchain.

## Parameters

### `DriverGlobals` [in]

Pointer to an [**IDD_DRIVER_GLOBALS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idd_driver_globals) structure containing system-defined per-driver data.

### `SwapChainObject` [in]

The [IDDCX_SWAPCHAIN](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object passed to the [**EVT_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_assign_swapchain) call.

### `pOutArgs` [out]

Output arguments of the functions.

## Return value

**PFN_IDDCXSWAPCHAINRELEASEANDACQUIRESYSTEMBUFFER** returns S_OK; otherwise it returns an appropriate error code.

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call [**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-pfn_iddcxswapchainreleaseandacquiresystembuffer).

## See also

[**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-pfn_iddcxswapchainreleaseandacquiresystembuffer)