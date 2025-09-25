# DXGKDDI_MIRACAST_DESTROY_CONTEXT callback function

## Description

Destroys an instance of a Miracast device.

## Parameters

### `DriverContext` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `MiracastContext` [in]

The Miracast device context, supplied by the operating system. This context was previously provided by the driver in a call to the [DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context) function.

## Remarks

When this function is called, the display miniport driver should release all kernel-mode resources that it allocated when it processed the [DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context) function, and it should immediately send a monitor departure hot-plug detection (HPD) awareness value to the operating system.

The operating system guarantees that, after it calls this function, it will not make any more calls to the [DxgkDdiMiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_handle_io_control) function.

If a Miracast device is disconnected before the [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function completes, while a present operation is still occurring on this Miracast target, the display miniport driver should not send any data to the user-mode Miracast driver.

If the user-mode [StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session) function takes too long to complete, the operating system calls *DxgkDdiMiracastDestroyContext* while the user-mode Miracast driver is still running. In this case, the operating system blocks any further calls to the user-mode [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control) function.

### Synchronization

The operating system groups the [DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context), *DxgkDdiMiracastDestroyContext*, and [DxgkDdiMiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_handle_io_control) functions as a *Miracast* class. The operating system guarantees that these functions follow the second-level synchronization mode as defined in [Threading and Synchronization Second Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level). These functions can be called when other level 0, 1, or other classes of level 2 functions are being called on another thread context. However, only one of these level 2 Miracast-class functions can be called at a time.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn)

[DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context)

[DxgkDdiMiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_handle_io_control)

[MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control)

[StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session)