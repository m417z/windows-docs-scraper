# DXGKDDI_MIRACAST_CREATE_CONTEXT callback function

## Description

Creates a kernel-mode context for a Miracast device.

## Parameters

### `DriverContext` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `MiracastCallbacks` [in]

A pointer to an operating system-provided buffer that holds a [DXGK_MIRACAST_DISPLAY_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_display_callbacks) structure that has pointers to callback functions that the driver can call.

### `MiracastContext` [out]

A pointer to an operating system-provided buffer that holds the address of the context that the driver allocated for this Miracast device instance.

### `TargetId` [out]

A pointer to an operating system-provided buffer that holds the ID of the VidPN target that the Miracast device is connected to. The driver should report this target as type **D3DKMDT_VOT_MIRACAST** when the operating system calls the [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function during device initialization.

## Return value

Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes that are defined in Ntstatus.h, including:

|Return code|Description|
|--- |--- |
|STATUS_RESOURCE_IN_USE|The hardware resources needed to support a Miracast connected session aren't currently available.|

## Remarks

When this function is called, the display miniport driver should prepare all kernel-mode resources that it needs to support a Miracast connected session.

### Synchronization

The operating system groups the *DxgkDdiMiracastCreateContext*, [DxgkDdiMiracastDestroyContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_destroy_context), and [DxgkDdiMiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_handle_io_control) functions as a *Miracast* class. The operating system guarantees that these functions follow the second-level synchronization mode as defined in [Threading and Synchronization Second Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level). These functions can be called when other level 0, 1, or other classes of level 2 functions are being called on another thread context. However, only one of these level 2 Miracast-class functions can be called at a time.

## See also

[DXGK_MIRACAST_DISPLAY_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_display_callbacks)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)