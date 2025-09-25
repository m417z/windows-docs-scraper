# DXGKCB_ACQUIRE_POST_DISPLAY_OWNERSHIP callback function

## Description

A kernel-mode display miniport driver (KMD) calls *Dxgkrnl*'s **DxgkCbAcquirePostDisplayOwnership** routine to obtain the display information from the current power-on self-test (POST) display device or the previously running WDDM driver.

The driver must use this display information to optimize the initial mode change request after the display device has been started.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The KMD previously obtained this handle in the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `DisplayInfo` [out]

Pointer to a [**DXGK_DISPLAY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_display_information) structure that is allocated by the KMD. If **DxgkCbAcquirePostDisplayOwnership** returns STATUS_SUCCESS, this structure contains display information for the current display device that is used for POST operations.

## Return value

**DxgkCbAcquirePostDisplayOwnership** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

Calling **DXGKCB_ACQUIRE_POST_DISPLAY_OWNERSHIP** ensures that the driver correctly initializes the display settings based on the current or most recent display configuration, especially after system start-up, device plug-in events, or resuming from hibernation.

### Allowed color formats

The **DisplayInfo->ColorFormat** member must include a bitwise-OR combination of the following two [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) formats:

* **D3DDDIFMT_X8R8G8B8**
* **D3DDDIFMT_A8R8G8B8**

If the OS reports back the **D3DDDIFMT_R8G8B8** format, the KMD should ignore it.

### Video present target initialization

It's possible that the **DisplayInfo->TargetId** member isn't initialized. In this case, the identifier of the video present target is **D3DDDI_ID_UNINITIALIZED**. Typically, this situation occurs after a system boot.

Similarly, it's possible that the **DisplayInfo->AcpiId** member isn't initialized. In this case, the ACPI identifier **AcpiId** has a value of zero.

In the case of a driver-to-driver upgrade, the previous driver will have provided the target identifier and the ACPI identifier.

### Implementation guidelines

Starting with WDDM 1.2, the KMD must follow these guidelines when it calls **DxgkCbAcquirePostDisplayOwnership**:

* The entry point for the **DxgkCbAcquirePostDisplayOwnership** function is part of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure. This structure is returned to the driver through the **DxgkInterface** parameter when the driver's [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function is called.

* KMD can optionally call **DxgkCbAcquirePostDisplayOwnership**. However, the OS might still call KMD's[**DxgkDdiStopDeviceAndReleasePostDisplayOwnership**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership) function, even if the driver didn't previously call **DxgkCbAcquirePostDisplayOwnership**, and the driver must handle that call appropriately. If the driver's **DxgkDdiStopDeviceAndReleasePostDisplayOwnership** function doesn't complete successfully, the OS will call the driver's [**DxgkDdiStopDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device) function.

* The KMD can call **DxgkCbAcquirePostDisplayOwnership** if the device is started in response to a Plug and Play (PnP) event. In this case, the driver must call **DxgkCbAcquirePostDisplayOwnership** from within the context of the call to the [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

* The KMD can call **DxgkCbAcquirePostDisplayOwnership** if the device resumes a **PowerDeviceD0** power state after a hibernation state. In this case, the driver must call **DxgkCbAcquirePostDisplayOwnership** from within the context of the call to the [**DxgkDdiSetPowerState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_set_power_state) function.

* The KMD must only call the **DxgkCbAcquirePostDisplayOwnership** function if it's running at least Windows 8. The KMD can call [**RtlGetVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion) to determine the version of the OS.

* **DxgkCbAcquirePostDisplayOwnership** can return a [**DXGK_DISPLAY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_display_information) structure with the **Width** member set to zero. This value indicates that either the current display device isn't capable of POST operations or the OS doesn't have the current display information for the current POST device.

## See also

[**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[**DXGK_DISPLAY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_display_information)

[**DxgkDdiSetPowerState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_set_power_state)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)

[**DxgkDdiStopDeviceAndReleasePostDisplayOwnership**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership)

[**RtlGetVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion)