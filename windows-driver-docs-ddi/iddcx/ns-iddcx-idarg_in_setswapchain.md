# IDARG_IN_SETSWAPCHAIN structure

## Description

The **IDARG_IN_SETSWAPCHAIN** structure provides information used to set the indirect swapchain.

## Members

### `hSwapChain` [in]

Handle to an opaque, OS-created IDDCX_SWAPCHAIN object that will be used to pass the desktop image to the driver for processing, transmission and display.

### `hNextSurfaceAvailable` [in]

Handle to the auto reset event that is signaled when the new image to encode is ready.

### `RenderAdapterLuid` [In]

LUID of the adapter where the desktop image was rendered.

## See also

[**EVT_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_assign_swapchain)