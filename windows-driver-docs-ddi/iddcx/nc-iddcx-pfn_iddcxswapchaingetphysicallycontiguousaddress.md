## Description

**PFN_IDDCXSWAPCHAINGETPHYSICALLYCONTIGUOUSADDRESS** is a pointer to an OS callback function through which to retrieve the physical address of the specified swapchain's currently acquired surface.

## Parameters

### `DriverGlobals` [in]

Pointer to an [**IDD_DRIVER_GLOBALS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idd_driver_globals) structure containing system-defined per-driver data.

### `SwapChainObject` [in]

The [IDDCX_SWAPCHAIN](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object passed to the [**EVT_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_assign_swapchain) call.

### `pSurfaceAddresss` [out]

Output arguments. On success, **pSurfaceAddress** is filled with the physical address of the surface.

## Return value

If the routine succeeds it return S_OK. If the surface was not allocated in physically contiguous memory this routine will return E_NOINTERFACE.

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call [**IddCxSwapChainGetPhysicallyContiguousAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchaingetphysicallycontiguousaddress).

## See also

[**IddCxSwapChainGetPhysicallyContiguousAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchaingetphysicallycontiguousaddress)