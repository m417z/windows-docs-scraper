## Description

**PFN_IDDCXSWAPCHAININSYSTEMMEMORY** is a pointer to an OS callback function through which to determine whether swapchain buffers are allocated in system memory.

## Parameters

### `DriverGlobals` [in]

Pointer to an [**IDD_DRIVER_GLOBALS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idd_driver_globals) structure containing system-defined per-driver data.

### `SwapChainObject` [in]

The [IDDCX_SWAPCHAIN](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object passed to the [**EVT_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_assign_swapchain) call.

### `pInSystemMemory` [out]

Output arguments of the functions.

## Return value

**PFN_IDDCXSWAPCHAININSYSTEMMEMORY** returns S_OK; otherwise it returns an appropriate error code.

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call [**IddCxSwapChainInSystemMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-pfn_iddcxswapchaininsystemmemory).

## See also

[**IddCxSwapChainInSystemMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-pfn_iddcxswapchaininsystemmemory)