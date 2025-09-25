# DXGKDDI_SYSTEM_DISPLAY_ENABLE callback function

## Description

The OS calls the kernel-mode display driver's (KMD) **DxgkddiSystemDisplayEnable** function to request that KMD reset the current display device to a specified state.

## Parameters

### `MiniportDeviceContext` [in]

Handle to a context block associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `TargetId` [in]

A [**D3DDDI_VIDEO_PRESENT_TARGET_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_present_target) value that specifies the identifier of the video present target on the display adapter that the display device is connected to. This identifier could be for the target that was left in the current video present network (VidPn) state during the previous call to [**DxgkDdiCommitVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn).

### `Flags` [in]

Pointer to a [**DXGKARG_SYSTEM_DISPLAY_ENABLE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_system_display_enable_flags) value that contains a bitwise OR of flags. This member is reserved by the OS.

### `Width` [out]

Width of the display mode of the specified device, in pixels.

### `Height` [out]

Height of the display mode of the specified device, in pixels.

### `ColorFormat` [out]

Pointer to a [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) value that specifies the color format of the display device.

## Return value

**DxgkDdiSystemDisplayEnable** returns STATUS_SUCCESS if it succeeds. If the target specified by the **TargetId** parameter isn't connected to a display device, the function returns STATUS_NOT_SUPPORTED. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The OS calls **DxgkddiSystemDisplayEnable** during a bugcheck operation following a system stop error.

### Required steps by KMD

The KMD must follow these steps when its **DxgkDdiSystemDisplayEnable** function is called:

1. Cancel all GPU operations or reset the GPU to the idle state.
1. The OS indicates the video present target through the **TargetId** parameter. The driver must keep the display associated with this target powered on and visible. If the driver can't power on the display, it must fail the call to this function. In such a failure case, the OS might call [**DxgkDdiResetDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_reset_device) and cause a system bugcheck to occur.
1. Check the connectivity of the display associated with this target. If the target doesn't have a display connected, the driver must complete the call to this function and return the STATUS_NOT_SUPPORTED error code.
1. Disable the signal to all other displays that are connected to the display adapter. If this isn't possible, the driver should attempt to place a blank image on all other displays. If this isn't possible, the driver must leave the last image on the screen unchanged.
1. Keep the current display mode on the indicated target and provide this mode back to the OS as part of this function call.
1. If the driver can't maintain the current display mode, or if the target is not part of the active topology, the driver should attempt to set a frame buffer on another target that is capable of a display resolution of at least 640 x 480 pixels in a format of 24 bits per pixel. If this isn't possible, the driver can fail this function call, which will result in a system bugcheck and the display of a black screen.

KMD doesn't have to use a linear frame buffer mode. However, KMD should support write operations to this frame buffer from sources that have the **D3DDDIFMT_A8R8G8B8** format of the [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration.

### Source image restrictions

After KMD gives the OS control over display functionality, the OS can call the [**DxgkDdiSystemDisplayWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_write) function to update the screen image and to write a block of images from specified sources to the screen that was reset by the **DxgkDdiSystemDisplayEnable** function.

[**DxgkDdiSystemDisplayWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_write) provides the driver with the starting address of the source image as well as the stride, width, and height. The color format of the source image is always **D3DDDIFMT_X8R8G8B8**. The OS guarantees that the source image is in non-paged memory.

KMD must write this source image to the current screen starting at the positions specified by the **PositionX** and **PositionY** parameters of the [**DxgkDdiSystemDisplayWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_write) function.

It's recommended that the driver use the CPU to write the image from the source to the frame buffer because a system bugcheck might be caused by repeated [Timeout Detection and Recovery (TDR)](https://learn.microsoft.com/windows-hardware/drivers/display/timeout-detection-and-recovery) instances that result in the GPU being in an unknown condition.

### Use non-paged memory

Windows kernel-mode functions might not be available while this function is being called.

**DxgkDdiSystemDisplayEnable** can be called at any IRQL, so it must be in nonpageable memory. **DxgkDdiSystemDisplayEnable** must not call any code that is in pageable memory and must not manipulate any data that is in pageable memory.

### Automatic display switching

An automatic display switch driver's **DxgkDdiSystemDisplayEnable** DDI must ensure that panel self refresh (PSR) is disabled at the end of the call to it. For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[**DxgkCbAcquirePostDisplayOwnership**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiCommitVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn)

[**DxgkDdiResetDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_reset_device)

[**DxgkDdiStopDeviceAndReleasePostDisplayOwnership**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership)

[**DxgkDdiSystemDisplayWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_write)