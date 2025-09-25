# DXGKDDI_SYSTEM_DISPLAY_WRITE callback function

## Description

Called by the operating system to request the display miniport driver to write an image block to the display device.

Starting with Windows 8, the operating system calls this function during a bugcheck operation following a system stop error. The operating system calls this function only if the display device was previously reset through a call to [DxgkDdiSystemDisplayEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_enable).

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem.

### `Source` [in]

A pointer to the start address of the source image to be written to the bugcheck screen that displays information about the system stop error.

### `SourceWidth` [in]

A UINT value that specifies the width, in units of pixels, of the specified source image.

### `SourceHeight` [in]

A UINT value that specifies the height, in units of pixels, of the specified source image.

### `SourceStride` [in]

A UINT value that specifies the number of bytes for each line of the specified source image.

### `PositionX` [in]

A UINT value that specifies the starting X coordinate that the specified source image should be written to on the display device.

### `PositionY` [in]

A UINT value that specifies the starting Y coordinate that the specified source image should be written to on the display device.

## Remarks

### Source image restrictions

The display miniport driver must follow these guidelines when its *DxgkDdiSystemDisplayWrite* function is called:

* The color format of the source image is always in the **D3DDDIFMT_R8G8B8** (24 bits per pixel) or **D3DDDIFMT_A8R8G8B8** (32 bpp) formats of the [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration. The display miniport driver had previously set the display mode to enable write operations in this format when its [DxgkDdiSystemDisplayEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_enable) was called.
* The source image is in non-paged memory. The display miniport driver should write this source image to the current frame buffer starting at the positions specified by the *PostionX* and *PositionY* parameters.
* The display miniport driver should use the CPU to write the image block to the frame buffer. When the system encounters a stop error, it may have been caused by a continuous timeout detection and recovery (TDR) on the display device. In that case, the graphics processing unit (GPU) might be in an unknown state.

  For more information about TDR, see [Timeout Detection and Recovery (TDR)](https://learn.microsoft.com/windows-hardware/drivers/display/timeout-detection-and-recovery).

### Use non-paged memory

Windows kernel-mode functions might not be available while this function is being called.

*DxgkDdiSystemDisplayWrite* can be called at any IRQL, so it must be in nonpageable memory. *DxgkDdiSystemDisplayWrite* must not call any code that is in pageable memory and must not manipulate any data that is in pageable memory.

## See also

[DxgkCbAcquirePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiStopDeviceAndReleasePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership)

[DxgkDdiSystemDisplayEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_enable)