# DXGKDDI_MIRACAST_QUERY_CAPS callback function

## Description

Queries the Miracast capabilities of the current display adapter. The operating system calls this function only when the display adapter is first started and then stores the capabilities that are returned.

**Note** The capabilities of the display adapter must not change while it is connected.

## Parameters

### `DriverContext` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `MiracastCapsSize` [in]

The size, supplied by the operating system, of the [DXGK_MIRACAST_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_caps) structure pointed to by the *MiracastCaps* parameter.

The driver should check this value before it fills the structure.

### `MiracastCaps` [out]

A pointer to an operating system-provided buffer that holds a [DXGK_MIRACAST_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_caps) structure that the driver fills with Miracast device capabilities.

## Return value

Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes that are defined in Ntstatus.h.

## Remarks

### Synchronization

The operating system guarantees that this function follows the third-level synchronization mode as defined in [Threading and Synchronization Third Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-third-level).

## See also

[DXGK_MIRACAST_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_caps)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)