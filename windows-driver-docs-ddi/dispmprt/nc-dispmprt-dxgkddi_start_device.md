# DXGKDDI_START_DEVICE callback function

## Description

The *DxgkDdiStartDevice* function prepares a display adapter to receive I/O requests.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `DxgkStartInfo` [in]

A pointer to a [DXGK_START_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_start_info) structure that contains information that the display miniport driver needs for initialization.

### `DxgkInterface` [in]

A pointer to a [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that contains pointers to functions, implemented by the DirectX graphics kernel subsystem, that the display miniport driver can call.

### `NumberOfVideoPresentSources` [out]

A pointer to a **ULONG** variable that receives the number of video present sources supported by the display adapter. For more information about video present sources, see [Multiple Monitors and Video Present Networks](https://learn.microsoft.com/windows-hardware/drivers/display/multiple-monitors-and-video-present-networks).

### `NumberOfChildren` [out]

A pointer to a **ULONG** variable that receives the total number of devices that are children of the display adapter represented by *MiniportDeviceContext*. This count must include potential child devices as well as child devices that are currently present. For example, if docking a portable computer will make additional video outputs available, those video outputs must be counted regardless of whether the portable computer is currently docked. For more information about child devices, see [Child Devices of the Display Adapter](https://learn.microsoft.com/windows-hardware/drivers/display/child-devices-of-the-display-adapter).

## Return value

*DxgkDdiStartDevice* returns **STATUS_SUCCESS** if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The *DxgkDdiStartDevice* function must perform the following actions:

* Save the function pointers supplied by the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure passed to the *DxgkInterface* parameter. Also save the **DeviceHandle** member of the **DXGKRNL_INTERFACE** structure; you will need that handle to call back into the DirectX graphics kernel subsystem.
* Allocate a [DXGK_DEVICE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_device_info) structure, and call [DxgkCbGetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_get_device_information) to fill in the members of that structure, which include the registry path, the PDO, and a list of translated resources for the display adapter represented by *MiniportDeviceContext*. Save selected members (ones that the display miniport driver will need later) of the **DXGK_DEVICE_INFO** structure in the context block represented by *MiniportDeviceContext.*
* Map memory resources into system space by calling the [DxgkCbMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_map_memory) function.
* Initialize the context block represented by *MiniportDeviceContext* with any state that is required to prepare the hardware to receive I/O requests.
* Set *NumberOfVideoPresentSources*  to the number of video present sources supported by the display adapter that is represented by *MiniportDeviceContext*.
* Set *NumberOfChildren*  to the number of devices that are (or could become) children of the display adapter represented by *MiniportDeviceContext*.
* Enable interrupts for the display adapter represented by *MiniportDeviceContext*.

Starting with Windows Display Driver Model (WDDM) 1.2, the display miniport driver calls the [DxgkCbAcquirePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership) function to obtain the information about the display mode that had been previously set by the firmware and system loader. If **DxgkCbAcquirePostDisplayOwnership** returns with **STATUS_SUCCESS**, the driver determines whether it has to reinitialize the display based on the display mode information that was returned through the *DisplayInfo* parameter. Otherwise, the driver should not assume that any specific display mode is currently enabled on the device, and it should initialize the display.

The *DxgkDdiStartDevice* function should be made pageable.

## See also

[DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[DXGK_DEVICE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_device_info)

[DxgkCbAcquirePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership)

[DxgkCbGetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_get_device_information)

[DxgkCbMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_map_memory)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiStopDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device)