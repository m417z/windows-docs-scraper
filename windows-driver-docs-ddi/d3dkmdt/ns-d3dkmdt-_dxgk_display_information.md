# _DXGK_DISPLAY_INFORMATION structure

## Description

Contains the display information that is passed between the operating system and the display miniport driver when the driver is started or stopped in response to a Plug and Play (PnP) event.

## Members

### `Width`

A UINT value that specifies the width of the current display mode in units of pixels.

### `Height`

A UINT value that specifies the height of the current display mode in units of pixels.

### `Pitch`

A UINT value that specifies the total number of bytes contained in one screen line.

### `ColorFormat`

A value of type [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) that indicates the pixel color format of the current display mode. The driver does not have to support all color formats in the **D3DDDIFORMAT** structure. For more information on formats that must be supported, see [DxgkCbAcquirePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership) and [DxgkDdiStopDeviceAndReleasePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership).

### `PhysicAddress`

The physical start address of the frame buffer for the current display mode.

### `TargetId`

An integer value that specifies the identifier of the video present target on the display adapter that the display device is connected to.

### `AcpiId`

A ULONG value that specifies the ACPI identifier of the video present target specified by the **TargetId** member.

**Note** If the video present target is not an ACPI device, this member must be set to zero.

## Remarks

For more information on the use of the members of **DXGK_DISPLAY_INFORMATION**, see [DxgkCbAcquirePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership) and [DxgkDdiStopDeviceAndReleasePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership).

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[DxgkCbAcquirePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership)

[DxgkDdiStopDeviceAndReleasePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership)