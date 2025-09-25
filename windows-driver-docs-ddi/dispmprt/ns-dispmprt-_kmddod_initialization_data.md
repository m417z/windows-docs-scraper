# _KMDDOD_INITIALIZATION_DATA structure

## Description

Contains pointers to functions implemented by a kernel mode display-only driver (KMDOD). The KMDOD's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function provides the Microsoft DirectX graphics kernel subsystem with entry points by filling in the members of this structure.

## Members

### `Version`

A positive integer that indicates the version of the functional interface implemented by the KMDOD. The KMDOD must set this member to **DXGKDDI_INTERFACE_VERSION**, which is defined in Dispmprt.h.

### `DxgkDdiAddDevice`

A pointer to the KMDOD's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `DxgkDdiStartDevice`

A pointer to the KMDOD's [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `DxgkDdiStopDevice`

A pointer to the KMDOD's [DxgkDdiStopDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device) function.

### `DxgkDdiRemoveDevice`

A pointer to the KMDOD's [DxgkDdiRemoveDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_remove_device) function.

### `DxgkDdiDispatchIoRequest`

A pointer to the KMDOD's [DxgkDdiDispatchIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dispatch_io_request) function.

### `DxgkDdiInterruptRoutine`

A pointer to the KMDOD's [DxgkDdiInterruptRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine) function.

**Note** This function pointer has special requirements. For more information, see Remarks.

### `DxgkDdiDpcRoutine`

A pointer to the KMDOD's [DxgkDdiDpcRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpc_routine) function.

**Note** This function pointer has special requirements. For more information, see Remarks.

### `DxgkDdiQueryChildRelations`

A pointer to the KMDOD's [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function.

### `DxgkDdiQueryChildStatus`

A pointer to the KMDOD's [DxgkDdiQueryChildStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_status) function.

### `DxgkDdiQueryDeviceDescriptor`

A pointer to the KMDOD's [DxgkDdiQueryDeviceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_device_descriptor) function.

### `DxgkDdiSetPowerState`

A pointer to the KMDOD's [DxgkDdiSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_set_power_state) function.

### `DxgkDdiNotifyAcpiEvent`

A pointer to the KMDOD's [DxgkDdiNotifyAcpiEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_acpi_event) function.

### `DxgkDdiResetDevice`

A pointer to the KMDOD's [DxgkDdiResetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_reset_device) function.

### `DxgkDdiUnload`

A pointer to the KMDOD's [DxgkDdiUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_unload) function.

### `DxgkDdiQueryInterface`

A pointer to the KMDOD's [DxgkDdiQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) function.

### `DxgkDdiControlEtwLogging`

A pointer to the KMDOD's [DxgkDdiControlEtwLogging](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_control_etw_logging) function.

### `DxgkDdiQueryAdapterInfo`

A pointer to the KMDOD's [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

### `DxgkDdiSetPalette`

A pointer to the KMDOD's [DxgkDdiSetPalette](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpalette) function that sets the palette for the display.

### `DxgkDdiSetPointerPosition`

A pointer to the KMDOD's [DxgkDdiSetPointerPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpointerposition) function.

### `DxgkDdiSetPointerShape`

A pointer to the KMDOD's [DxgkDdiSetPointerShape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpointershape) function.

### `DxgkDdiEscape`

A pointer to the KMDOD's [DxgkDdiEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape) function.

### `DxgkDdiCollectDbgInfo`

A pointer to the KMDOD's [DxgkDdiCollectDbgInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo) function.

### `DxgkDdiIsSupportedVidPn`

A pointer to the KMDOD's [DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn) function.

### `DxgkDdiRecommendFunctionalVidPn`

A pointer to the KMDOD's [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn) function.

### `DxgkDdiEnumVidPnCofuncModality`

A pointer to the KMDOD's [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality) function.

### `DxgkDdiSetVidPnSourceVisibility`

A pointer to the KMDOD's [DxgkDdiSetVidPnSourceVisibility](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourcevisibility) function.

### `DxgkDdiCommitVidPn`

A pointer to the KMDOD's [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function.

### `DxgkDdiUpdateActiveVidPnPresentPath`

A pointer to the KMDOD's [DxgkDdiUpdateActiveVidPnPresentPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateactivevidpnpresentpath) function.

### `DxgkDdiRecommendMonitorModes`

A pointer to the KMDOD's [DxgkDdiRecommendMonitorModes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendmonitormodes) function.

### `DxgkDdiGetScanLine`

A pointer to the KMDOD's [DxgkDdiGetScanLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getscanline) function.

**Note** This function pointer has special requirements. For more information, see Remarks.

### `DxgkDdiQueryVidPnHWCapability`

A pointer to the KMDOD's [DxgkDdiQueryVidPnHWCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryvidpnhwcapability) function.

### `DxgkDdiPresentDisplayOnly`

A pointer to the KMDOD's [DxgkDdiPresentDisplayOnly](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_presentdisplayonly) function.

### `DxgkDdiStopDeviceAndReleasePostDisplayOwnership`

A pointer to the KMDOD's [DxgkDdiStopDeviceAndReleasePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership) function.

### `DxgkDdiSystemDisplayEnable`

A pointer to the KMDOD's [DxgkDdiSystemDisplayEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_enable) function.

### `DxgkDdiSystemDisplayWrite`

A pointer to the KMDOD's [DxgkDdiSystemDisplayWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_write) function.

### `DxgkDdiGetChildContainerId`

A pointer to the KMDOD's [DxgkDdiGetChildContainerId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_get_child_container_id) function.

### `DxgkDdiControlInterrupt`

A pointer to the KMDOD's [DxgkDdiControlInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt) function.

**Note** This function pointer has special requirements. For more information, see Remarks.

### `DxgkDdiSetPowerComponentFState`

A pointer to the KMDOD's [DxgkDdiSetPowerComponentFState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddisetpowercomponentfstate) function.

### `DxgkDdiPowerRuntimeControlRequest`

A pointer to the KMDOD's [DxgkDdiPowerRuntimeControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddipowerruntimecontrolrequest) function.

### `DxgkDdiNotifySurpriseRemoval`

A pointer to the KMDOD's [DxgkDdiNotifySurpriseRemoval](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_surprise_removal) function.

### `DxgkDdiPowerRuntimeSetDeviceHandle`

A pointer to the KMDOD's DxgkDdiPowerRuntimeSetDeviceHandle function.

## Remarks

If the kernel mode display-only driver (KMDOD) supports the VSync control feature, it must implement all of the [DxgkDdiControlInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt), [DxgkDdiGetScanLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getscanline), [DxgkDdiInterruptRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine), and [DxgkDdiDpcRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpc_routine) functions and must provide valid function pointers to all of these functions in this structure. Conversely, if the KMDOD does not support the VSync control feature, it must not implement either *DxgkDdiControlInterrupt* or *DxgkDdiGetScanLine* functions and must not provide valid function pointers to either of these functions in this structure. For more information, see [Saving Energy with VSync Control](https://learn.microsoft.com/windows-hardware/drivers/display/saving-energy-with-vsync-control).

## See also

[DriverEntry of Display Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver)

[DxgkInitializeDisplayOnlyDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nf-dispmprt-dxgkinitializedisplayonlydriver)