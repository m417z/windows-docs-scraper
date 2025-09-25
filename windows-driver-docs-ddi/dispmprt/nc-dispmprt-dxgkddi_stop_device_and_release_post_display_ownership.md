# DXGKDDI_STOP_DEVICE_AND_RELEASE_POST_DISPLAY_OWNERSHIP callback function

## Description

The OS calls the kernel-mode display driver's (KMD) **DxgkddiStopDeviceAndReleasePostDisplayOwnership** function to request that KMD reset the display device and release ownership of the current power-on self-test (POST) device.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block that is associated with a display adapter. The KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem (*Dxgkrnl*).

### `TargetId` [in]

A **D3DDDI_VIDEO_PRESENT_TARGET_ID** value that specifies the identifier of the video present target on the display adapter that the display device is connected to. This identifier could be for the target that was left in the current video present network (VidPN) state during the previous call to [**DxgkDdiCommitVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn).

For more details about the use of the **TargetId** parameter, see the Remarks section.

### `DisplayInfo` [out]

A pointer to a [**DXGK_DISPLAY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_display_information) structure that is allocated by the OS.

## Return value

Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*. For more information, see the Remarks section.

## Remarks

Starting with Windows 8 (WDDM 1.2), the OS calls this function during a Plug and Play (PnP) stop operation.

To indicate to the OS that this function is supported, the driver must set the **NonVGASupport** member of the [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure when its [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function is called.

### Allowed color formats

The KMD should report only a 32-bit color format. Therefore the **DisplayInfo->ColorFormat** member must include only one of the following two [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) formats:

* **D3DDDIFMT_X8R8G8B8**
* **D3DDDIFMT_A8R8G8B8**

### Video present target initialization

The KMD must set the **DisplayInfo->TargetId** member to the target identifier of the display that remains active. Typically, this identifier will be the value of the **TargetId** parameter that the OS passed to the driver.

Similarly, the KMD must set the **DisplayInfo->AcpiId** member to the ACPI identifier of the display that remains active.

### Required steps by the KMD

The KMD must follow these steps when its **DxgkDdiStopDeviceAndReleasePostDisplayOwnership** function is called:

1. Stop the display device associated with the video present target indicated by the **TargetId** parameter but must keep the display associated with this target powered on and visible.

1. Check the connectivity of the display associated with this target. If the target doesn't have a display connected, the KMD must complete the call to this function and return the **STATUS_NOT_SUPPORTED** error code.

1. Disable the signal to all other displays that are connected to the display adapter. If this is not possible, the driver should attempt to place a blank image on all other displays. If this is not possible, the driver must leave the last image on the screen unchanged.

1. Keep the current display mode on the indicated target and provide this mode back to the OS as part of this function call.

1. If the driver can't maintain the current display mode, or if the target isn't part of the active topology, the driver should select an alternate active target and attempt to maintain the current resolution of that target. If that isn't possible, the driver should attempt to set the display to its native resolution or to a high-resolution mode. In this case, the display resolution must be set to at least 800 x 600 pixels in either **D3DDDIFMT_R8G8B8** (24 bits per pixel) or **D3DDDIFMT_X8R8G8B8** (32 bpp) color formats.

1. If no target is active, the driver should attempt to enable a target, preferably the internal panel, if it is available.

1. If possible, the driver must clear the current frame buffer and disable the hardware cursor and all display overlays.

1. If possible, the driver must set the gamma ramp of the device to its default values.

1. The driver must set the current frame buffer to be in a linear mode. The driver does this either by using the default swizzle range or by disabling swizzle mode.

1. The driver must make the current frame buffer accessible to the CPU by mapping the current frame buffer linearly into the CPU address space.

1. The driver must ensure that the visibility of the indicated target is set to "enabled."

After the KMD performs these steps, it must return the current display settings for the device. The driver returns this information by setting the members of the [**DXGK_DISPLAY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_display_information) structure that is referenced by the **DisplayInfo** parameter.

After the device has been stopped, this display information might be used by the Windows generic display driver to manage the display device.

### Other requirements

On systems that support the Unified Extensible Firmware Interface (UEFI), a VGA basic input/output system (BIOS) doesn't exist. To support PnP stop operations on these systems, WDDM 1.2 and later provides support for the OS to reset the POST device and to get its display information during a PnP stop operation. The OS does this by calling the KMD's **DxgkDdiStopDeviceAndReleasePostDisplayOwnership** function.

A PnP stop operation can occur in response to requests by processes such as the Device Manager, or during a driver upgrade process.

Starting with Windows 8, the OS calls the driver's **DxgkDdiStopDeviceAndReleasePostDisplayOwnership** function only on the POST device during a PnP stop operation.

It's optional for KMD to call [**DxgkCbAcquirePostDisplayOwnership**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership). However, the OS might still call KMD's **DxgkDdiStopDeviceAndReleasePostDisplayOwnership** function regardless of whether the driver made a previous call to **DxgkCbAcquirePostDisplayOwnership**.

If the driver successfully completes a call to this function, the OS won't call KMD's [**DxgkDdiStopDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device) function. If the driver fails to complete a call to this function, the OS will call **DxgkDdiStopDevice**, and device behavior will be the same as in Windows 7.

On UEFI-only systems, if the KMD fails a call to this function, a black screen is displayed and the IHV driver isn't installed. The workaround to this scenario is for the user to reboot the computer.

For more information on how this function is used in PnP scenarios, see [Plug and Play (PnP) in WDDM 1.2 and later](https://learn.microsoft.com/windows-hardware/drivers/display/plug-and-play--pnp--start-and-stop-cases).

## See also

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[**DXGK_DISPLAY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_display_information)

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DxgkCbAcquirePostDisplayOwnership**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)

[**DxgkDdiStopDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device)