# DRIVER_INITIALIZATION_DATA structure

## Description

The **DRIVER_INITIALIZATION_DATA** structure contains pointers to functions implemented by the display miniport driver (KMD). KMD's [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver) function provides the DirectX graphics kernel subsystem with entry points by filling in the members of this structure.

## Members

### `Version`

A positive integer that indicates the version of the functional interface implemented by the KMD. The KMD must set this member to **DXGKDDI_INTERFACE_VERSION**, which is defined in *Dispmprt.h*.

### `DxgkDdiAddDevice`

A pointer to the KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `DxgkDdiStartDevice`

A pointer to the KMD's [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `DxgkDdiStopDevice`

A pointer to the KMD's [**DxgkDdiStopDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device) function.

### `DxgkDdiRemoveDevice`

A pointer to the KMD's [**DxgkDdiRemoveDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_remove_device) function.

### `DxgkDdiDispatchIoRequest`

A pointer to the KMD's [**DxgkDdiDispatchIoRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dispatch_io_request) function.

### `DxgkDdiInterruptRoutine`

A pointer to the KMD's [**DxgkDdiInterruptRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine) function.

### `DxgkDdiDpcRoutine`

A pointer to the KMD's [**DxgkDdiDpcRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpc_routine) function.

### `DxgkDdiQueryChildRelations`

A pointer to the KMD's [**DxgkDdiQueryChildRelations**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function.

### `DxgkDdiQueryChildStatus`

A pointer to the KMD's [**DxgkDdiQueryChildStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_status) function.

### `DxgkDdiQueryDeviceDescriptor`

A pointer to the KMD's [**DxgkDdiQueryDeviceDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_device_descriptor) function.

### `DxgkDdiSetPowerState`

A pointer to the KMD's [**DxgkDdiSetPowerState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_set_power_state) function.

### `DxgkDdiNotifyAcpiEvent`

A pointer to the KMD's [**DxgkDdiNotifyAcpiEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_acpi_event) function.

### `DxgkDdiResetDevice`

A pointer to the KMD's [**DxgkDdiResetDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_reset_device) function.

### `DxgkDdiUnload`

A pointer to the KMD's [**DxgkDdiUnload**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_unload) function.

### `DxgkDdiQueryInterface`

A pointer to the KMD's [**DxgkDdiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) function.

### `DxgkDdiControlEtwLogging`

A pointer to the KMD's [**DxgkDdiControlEtwLogging**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_control_etw_logging) function.

### `DxgkDdiQueryAdapterInfo`

A pointer to the KMD's [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

### `DxgkDdiCreateDevice`

A pointer to the KMD's [**DxgkDdiCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function.

### `DxgkDdiCreateAllocation`

A pointer to the KMD's [**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function.

### `DxgkDdiDestroyAllocation`

A pointer to the KMD's [**DxgkDdiDestroyAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyallocation) function.

### `DxgkDdiDescribeAllocation`

A pointer to the KMD's [**DxgkDdiDescribeAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_describeallocation) function.

### `DxgkDdiGetStandardAllocationDriverData`

A pointer to the KMD's [**DxgkDdiGetStandardAllocationDriverData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata) function.

### `DxgkDdiAcquireSwizzlingRange`

A pointer to the KMD's [**DxgkDdiAcquireSwizzlingRange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) function.

### `DxgkDdiReleaseSwizzlingRange`

A pointer to the KMD's [**DxgkDdiReleaseSwizzlingRange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_releaseswizzlingrange) function.

### `DxgkDdiPatch`

A pointer to the KMD's [**DxgkDdiPatch**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_patch) function.

### `DxgkDdiSubmitCommand`

A pointer to the KMD's [**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) function.

### `DxgkDdiPreemptCommand`

A pointer to the KMD's [**DxgkDdiPreemptCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_preemptcommand) function.

### `DxgkDdiBuildPagingBuffer`

A pointer to the KMD's [**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function.

### `DxgkDdiSetPalette`

A pointer to the KMD's [**DxgkDdiSetPalette**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpalette) function that sets the palette for the display.

### `DxgkDdiSetPointerPosition`

A pointer to the KMD's [**DxgkDdiSetPointerPosition**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpointerposition) function.

### `DxgkDdiSetPointerShape`

A pointer to the KMD's [**DxgkDdiSetPointerShape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpointershape) function.

### `DxgkDdiResetFromTimeout`

A pointer to the KMD's [**DxgkDdiResetFromTimeout**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetfromtimeout) function.

### `DxgkDdiRestartFromTimeout`

A pointer to the KMD's [**DxgkDdiRestartFromTimeout**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_restartfromtimeout) function.

### `DxgkDdiEscape`

A pointer to the KMD's [**DxgkDdiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape) function.

### `DxgkDdiCollectDbgInfo`

A pointer to the KMD's [**DxgkDdiCollectDbgInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo) function.

### `DxgkDdiQueryCurrentFence`

A pointer to the KMD's [**DxgkDdiQueryCurrentFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querycurrentfence) function.

### `DxgkDdiIsSupportedVidPn`

A pointer to the KMD's [**DxgkDdiIsSupportedVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn) function.

### `DxgkDdiRecommendFunctionalVidPn`

A pointer to the KMD's [**DxgkDdiRecommendFunctionalVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn) function.

### `DxgkDdiEnumVidPnCofuncModality`

A pointer to the KMD's [**DxgkDdiEnumVidPnCofuncModality**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality) function.

### `DxgkDdiSetVidPnSourceAddress`

A pointer to the KMD's [**DxgkDdiSetVidPnSourceAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddress) function.

### `DxgkDdiSetVidPnSourceVisibility`

A pointer to the KMD's [**DxgkDdiSetVidPnSourceVisibility**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourcevisibility) function.

### `DxgkDdiCommitVidPn`

A pointer to the KMD's [**DxgkDdiCommitVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function.

### `DxgkDdiUpdateActiveVidPnPresentPath`

A pointer to the KMD's [**DxgkDdiUpdateActiveVidPnPresentPath**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateactivevidpnpresentpath) function.

### `DxgkDdiRecommendMonitorModes`

A pointer to the KMD's [**DxgkDdiRecommendMonitorModes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendmonitormodes) function.

### `DxgkDdiRecommendVidPnTopology`

A pointer to the KMD's [**DxgkDdiRecommendVidPnTopology**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendvidpntopology) function.

### `DxgkDdiGetScanLine`

A pointer to the KMD's [**DxgkDdiGetScanLine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getscanline) function.

### `DxgkDdiStopCapture`

A pointer to the KMD's [**DxgkDdiStopCapture**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_stopcapture) function.

### `DxgkDdiControlInterrupt`

A pointer to the KMD's [**DxgkDdiControlInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt) function.

### `DxgkDdiCreateOverlay`

A pointer to the KMD's [**DxgkDdiCreateOverlay**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createoverlay) function.

> [!NOTE]
> The following functions are specific to the graphics context device that was created through [**DxgkDdiCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice):

### `DxgkDdiDestroyDevice`

A pointer to the KMD's [**DxgkDdiDestroyDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroydevice) function.

### `DxgkDdiOpenAllocation`

A pointer to the KMD's [**DxgkDdiOpenAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo) function.

### `DxgkDdiCloseAllocation`

A pointer to the KMD's [**DxgkDdiCloseAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_closeallocation) function.

### `DxgkDdiRender`

A pointer to the KMD's [**DxgkDdiRender**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) function.

### `DxgkDdiPresent`

A pointer to the KMD's [**DxgkDdiPresent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) function.

> [!NOTE]
> The following functions are specific to the overlay that was created through [DxgkDdiCreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createoverlay):

### `DxgkDdiUpdateOverlay`

A pointer to the KMD's [**DxgkDdiUpdateOverlay**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateoverlay) function.

### `DxgkDdiFlipOverlay`

A pointer to the KMD's [**DxgkDdiFlipOverlay**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_flipoverlay) function.

### `DxgkDdiDestroyOverlay`

A pointer to the KMD's [**DxgkDdiDestroyOverlay**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyoverlay) function.

> [!NOTE]
> The following functions are specific to supporting contexts:

### `DxgkDdiCreateContext`

A pointer to the KMD's [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) function.

### `DxgkDdiDestroyContext`

A pointer to the KMD's [**DxgkDdiDestroyContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroycontext) function.

### `DxgkDdiLinkDevice`

A pointer to the KMD's [**DxgkDdiLinkDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_link_device) function. Be aware that this function is specific to supporting linked graphics adapters.

### `DxgkDdiSetDisplayPrivateDriverFormat`

A pointer to the KMD's [**DxgkDdiSetDisplayPrivateDriverFormat**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setdisplayprivatedriverformat) function.

### `DxgkDdiDescribePageTable`

This member is reserved and should be set to zero. Available only when DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN7.

### `DxgkDdiUpdatePageTable`

This member is reserved and should be set to zero. Available only when DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN7.

### `DxgkDdiUpdatePageDirectory`

This member is reserved and should be set to zero. Available only when DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN7.

### `DxgkDdiMovePageDirectory`

This member is reserved and should be set to zero. Available only when DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN7.

### `DxgkDdiSubmitRender`

This member is reserved and should be set to zero. Available only when DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN7.

### `DxgkDdiCreateAllocation2`

This member is reserved and should be set to zero. Available only when DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN7.

### `DxgkDdiRenderKm`

A pointer to the KMD's [**DxgkDdiRenderKm**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm) function. Available only when DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN7.

### `Reserved`

This member is reserved and should be set to zero. Available only when DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN7.

### `DxgkDdiQueryVidPnHWCapability`

A pointer to the KMD's [**DxgkDdiQueryVidPnHWCapability**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryvidpnhwcapability) function. Available only when DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN7.

### `DxgkDdiSetPowerComponentFState`

A pointer to the KMD's [**DxgkDdiSetPowerComponentFState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddisetpowercomponentfstate) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiQueryDependentEngineGroup`

A pointer to the KMD's [**DxgkDdiQueryDependentEngineGroup**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydependentenginegroup) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiQueryEngineStatus`

A pointer to the KMD's [**DxgkDdiQueryEngineStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryenginestatus) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiResetEngine`

A pointer to the KMD's [**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiStopDeviceAndReleasePostDisplayOwnership`

A pointer to the KMD's [**DxgkDdiStopDeviceAndReleasePostDisplayOwnership**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiSystemDisplayEnable`

A pointer to the KMD's [**DxgkDdiSystemDisplayEnable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_enable) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiSystemDisplayWrite`

A pointer to the KMD's [**DxgkDdiSystemDisplayWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_system_display_write) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiCancelCommand`

A pointer to the KMD's [**DxgkDdiCancelCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelcommand) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiGetChildContainerId`

A pointer to the KMD's [**DxgkDdiGetChildContainerId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_get_child_container_id) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiPowerRuntimeControlRequest`

A pointer to the KMD's [**DxgkDdiPowerRuntimeControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddipowerruntimecontrolrequest) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay`

A pointer to the KMD's [**DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiNotifySurpriseRemoval`

A pointer to the KMD's [**DxgkDdiNotifySurpriseRemoval**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_surprise_removal) function. Available starting with Windows 8 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN8).

### `DxgkDdiGetNodeMetadata`

A pointer to the KMD's [**DxgkDdiGetNodeMetadata**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getnodemetadata) function. Available starting with Windows 8.1 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM1_3).

### `DxgkDdiSetPowerPState`

This member is reserved and should be set to zero. Available starting with Windows 8.1 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM1_3).

### `DxgkDdiControlInterrupt2`

A pointer to the KMD's [**DxgkDdiControlInterrupt2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2) function. Available starting with Windows 8.1 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM1_3).

### `DxgkDdiCheckMultiPlaneOverlaySupport`

A pointer to the KMD's [**DxgkDdiCheckMultiPlaneOverlaySupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport) function. Available starting with Windows 8.1 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM1_3).

### `DxgkDdiCalibrateGpuClock`

A pointer to the KMD's [**DxgkDdiCalibrateGpuClock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_calibrategpuclock) function. Available starting with Windows 8.1 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM1_3).

### `DxgkDdiFormatHistoryBuffer`

A pointer to the KMD's [**DxgkDdiFormatHistoryBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_formathistorybuffer) function. Available starting with Windows 8.1 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM1_3).

### `DxgkDdiRenderGdi`

A pointer to the [DxgkDdiRenderGdi](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_rendergdi) callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiSubmitCommandVirtual`

A pointer to the [DXGKDDI_SUBMITCOMMANDVIRTUAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommandvirtual) callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiSetRootPageTable`

A pointer to the [DXGKDDI_SETROOTPAGETABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setrootpagetable) callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiGetRootPageTableSize`

A pointer to the [DXGKDDI_GETROOTPAGETABLESIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getrootpagetablesize) callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiMapCpuHostAperture`

A pointer to the [DXGKDDI_MAPCPUHOSTAPERTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_mapcpuhostaperture) callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiUnmapCpuHostAperture`

A pointer to the [DXGKDDI_UNMAPCPUHOSTAPERTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_unmapcpuhostaperture) callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiCheckMultiPlaneOverlaySupport2`

A pointer to the [DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport2) callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiCreateProcess`

A pointer to the [DXGKDDI_CREATEPROCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess) callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiDestroyProcess`

A pointer to the [DXGKDDI_DESTROYPROCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyprocess) callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2`

A pointer to the [DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay2) callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `Reserved1`

Reserved. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `Reserved2`

Reserved. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiPowerRuntimeSetDeviceHandle`

A pointer to the DXGKDDI_POWERRUNTIMESETDEVICEHANDLE callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiSetStablePowerState`

A pointer to the DXGKDDI_SETSTABLEPOWERSTATE callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiSetVideoProtectedRegion`

A pointer to the DXGKDDI_SETVIDEOPROTECTEDREGION callback function. Available starting with Windows 10 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_0).

### `DxgkDdiCheckMultiPlaneOverlaySupport3`

A pointer to the [DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport3) callback function. Available starting with Windows 10 version 1607 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_1).

### `DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3`

A pointer to the [DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay3) callback function. Available starting with Windows 10 version 1607 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_1).

### `DxgkDdiPostMultiPlaneOverlayPresent`

A pointer to the [DXGKDDI_POSTMULTIPLANEOVERLAYPRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_postmultiplaneoverlaypresent) callback function. Available starting with Windows 10 version 1607 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_1).

### `DxgkDdiValidateUpdateAllocationProperty`

A pointer to the DXGKDDI_VALIDATEUPDATEALLOCATIONPROPERTY callback function. Available starting with Windows 10 version 1607 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_1).

### `DxgkDdiControlModeBehavior`

A pointer to the [DXGKDDI_CONTROLMODEBEHAVIOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlmodebehavior) callback function. Available starting with Windows 10 version 1607 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_1).

### `DxgkDdiUpdateMonitorLinkInfo`

A pointer to the [DXGKDDI_UPDATEMONITORLINKINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatemonitorlinkinfo) callback function. Available starting with Windows 10 version 1607 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_1).

### `DxgkDdiCreateHwContext`

A pointer to the [DXGKDDI_CREATEHWCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiDestroyHwContext`

A pointer to the [DXGKDDI_DESTROYHWCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroycontext) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiCreateHwQueue`

A pointer to the DXGKDDI_CREATEHWQUEUE callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiDestroyHwQueue`

A pointer to the DXGKDDI_DESTROYHWQUEUE callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiSubmitCommandToHwQueue`

A pointer to the [DXGKDDI_SUBMITCOMMANDTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommandtohwqueue) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiSwitchToHwContextList`

A pointer to the [DXGKDDI_SWITCHTOHWCONTEXTLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_switchtohwcontextlist) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiResetHwEngine`

A pointer to the [DXGKDDI_RESETENGINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiCreatePeriodicFrameNotification`

A pointer to the [DXGKDDI_CREATEPERIODICFRAMENOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createperiodicframenotification) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiDestroyPeriodicFrameNotification`

A pointer to the [DXGKDDI_DESTROYPERIODICFRAMENOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyperiodicframenotification) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiSetTimingsFromVidPn`

A pointer to the [DXGKDDI_SETTIMINGSFROMVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiSetTargetGamma`

A pointer to the [DXGKDDI_SETTARGETGAMMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settargetgamma) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiSetTargetContentType`

A pointer to the [DXGKDDI_SETTARGETCONTENTTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settargetcontenttype) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiSetTargetAnalogCopyProtection`

A pointer to the [DXGKDDI_SETTARGETANALOGCOPYPROTECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settargetanalogcopyprotection) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiSetTargetAdjustedColorimetry`

A pointer to the [DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_settargetadjustedcolorimetry) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiDisplayDetectControl`

A pointer to the [DXGKDDI_DISPLAYDETECTCONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_displaydetectcontrol) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiQueryConnectionChange`

A pointer to the [DXGKDDI_QUERYCONNECTIONCHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryconnectionchange) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiExchangePreStartInfo`

A pointer to the [DXGKDDI_EXCHANGEPRESTARTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_exchangeprestartinfo) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiGetMultiPlaneOverlayCaps`

A pointer to the [DXGKDDI_GETMULTIPLANEOVERLAYCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getmultiplaneoverlaycaps) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiGetPostCompositionCaps`

A pointer to the [DXGKDDI_GETPOSTCOMPOSITIONCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getpostcompositioncaps) callback function. Available starting with Windows 10 version 1703 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_2).

### `DxgkDdiUpdateHwContextState`

A pointer to the [DXGKDDI_UPDATEHWCONTEXTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatehwcontextstate) callback function. Available starting with Windows 10 version 1709 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_3).

### `DxgkDdiCreateProtectedSession`

A pointer to the [DXGKDDI_CREATEPROTECTEDSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprotectedsession) callback function. Available starting with Windows 10 version 1709 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_3).

### `DxgkDdiDestroyProtectedSession`

A pointer to the [DXGKDDI_DESTROYPROTECTEDSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyprotectedsession) callback function. Available starting with Windows 10 version 1709 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_3).

### `DxgkDdiSetSchedulingLogBuffer`

A pointer to the [DXGKDDI_SETSCHEDULINGLOGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setschedulinglogbuffer) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiSetupPriorityBands`

A pointer to the [DXGKDDI_SETUPPRIORITYBANDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setupprioritybands) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiNotifyFocusPresent`

A pointer to the [DXGKDDI_NOTIFYFOCUSPRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_notifyfocuspresent) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiSetContextSchedulingProperties`

A pointer to the [DXGKDDI_SETCONTEXTSCHEDULINGPROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setcontextschedulingproperties) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiSuspendContext`

A pointer to the [DXGKDDI_SUSPENDCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_suspendcontext) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiResumeContext`

A pointer to the [DXGKDDI_RESUMECONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resumecontext) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiSetVirtualMachineData`

A pointer to the [DXGKDDI_SETVIRTUALMACHINEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvirtualmachinedata) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiBeginExclusiveAccess`

A pointer to the [DXGKDDI_BEGINEXCLUSIVEACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_beginexclusiveaccess) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiEndExclusiveAccess`

A pointer to the [DXGKDDI_ENDEXCLUSIVEACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_endexclusiveaccess) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiQueryDiagnosticTypesSupport`

A pointer to the [DXGKDDI_QUERYDIAGNOSTICTYPESSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydiagnostictypessupport) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiControlDiagnosticReporting`

A pointer to the [DXGKDDI_CONTROLDIAGNOSTICREPORTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_controldiagnosticreporting) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiResumeHwEngine`

A pointer to the [DXGKDDI_RESUMEHWENGINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resumehwengine) callback function. Available starting with Windows 10 version 1803 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_4).

### `DxgkDdiSignalMonitoredFence`

Pointer to a [DxgkDdiSignalMonitoredFence](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_signalmonitoredfence), called to add a GPU instruction to signal the paging monitored fence object to the DMA (direct memory access) buffer. Available starting with Windows 10 version 1809 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_5).

### `DxgkDdiPresentToHwQueue`

A pointer to the [DXGKDDI_PRESENTTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_presenttohwqueue) callback function. Available starting with Windows 10 version 1809 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_5).

### `DxgkDdiValidateSubmitCommand`

A pointer to the [DXGKDDI_VALIDATESUBMITCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_validatesubmitcommand) callback function. Available starting with Windows 10 version 1809 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_5).

### `DxgkDdiSetTargetAdjustedColorimetry2`

A pointer to the [DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_settargetadjustedcolorimetry2) callback function. Available starting with Windows 10 version 1809 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_5).

### `DxgkDdiSetTrackedWorkloadPowerLevel`

A pointer to the [DxgkDdiSetTrackedWorkloadPowerLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settrackedworkloadpowerlevel) callback function. Available starting with Windows 10 version 1809 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_5).

### `DxgkDdiSaveMemoryForHotUpdate`

A pointer to the [DxgkDdiSaveMemoryForHotUpdate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_savememoryforhotupdate) callback function. Available starting with Windows 10 version 1903 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_6).

### `DxgkDdiRestoreMemoryForHotUpdate`

A pointer to the [DxgkDdiRestoreMemoryForHotUpdate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_restorememoryforhotupdate) callback function. Available starting with Windows 10 version 1903 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_6).

### `DxgkDdiCollectDiagnosticInfo`

A pointer to the [DxgkDdiCollectDiagnosticInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_collectdiagnosticinfo) callback function. Available starting with Windows 10 version 1903 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_6).

### `Reserved3`

Reserved; set to zero. Available starting with Windows 10 version 1903 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_6).

### `DxgkDdiControlInterrupt3`

A pointer to the **DxgkDdiControlInterrupt3** callback function. Available starting with Windows 10 version 2004 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_7).

### `DxgkDdiSetFlipQueueLogBuffer`

A pointer to the **DxgkDdiSetFlipQueueLogBuffer** callback function. Available starting with Windows Server 2022 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_9).

### `DxgkDdiUpdateFlipQueueLog`

A pointer to the **DxgkDdiUpdateFlipQueueLog** callback function. Available starting with Windows Server 2022 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_9).

### `DxgkDdiCancelQueuedFlips`

A pointer to the **DxgkDdiCancelQueuedFlips** callback function. Available starting with Windows Server 2022 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_9).

### `DxgkDdiSetInterruptTargetPresentId`

A pointer to the **DxgkDdiSetInterruptTargetPresentId** callback function. Available starting with Windows Server 2022 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM2_9).

### `DxgkDdiSetAllocationBackingStore`

A pointer to the **DxgkDdiSetAllocationBackingStore** callback function. Available starting with Windows 11 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_0).

### `DxgkDdiCreateCpuEvent`

A pointer to the **DxgkDdiCreateCpuEvent** callback function. Available starting with Windows 11 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_0).

### `DxgkDdiDestroyCpuEvent`

A pointer to the **DxgkDdiDestroyCpuEvent** callback function. Available starting with Windows 11 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_0).

### `DxgkDdiCancelFlips`

A pointer to the **DxgkDdiCancelFlips** callback function. Available starting with Windows 11 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_0).

### `DxgkDdiCreateNativeFence`

A pointer to the **DxgkDdiCreateNativeFence** callback function. Available starting with Windows 11 version 22H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_1).

### `DxgkDdiDestroyNativeFence`

A pointer to the **DxgkDdiDestroyNativeFence** callback function. Available starting with Windows 11 version 22H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_1).

### `DxgkDdiUpdateMonitoredValues`

A pointer to the **DxgkDdiUpdateMonitoredValues** callback function. Available starting with Windows 11 version 22H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_1).

### `DxgkDdiUpdateCurrentValuesFromCpu`

A pointer to the **DxgkDdiUpdateCurrentValuesFromCpu** callback function. Available starting with Windows 11 version 22H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_1).

### `DxgkDdiCreateDoorbell`

A pointer to the **DxgkDdiCreateDoorbell** callback function. Available starting with Windows 11 version 22H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_1).

### `DxgkDdiConnectDoorbell`

A pointer to the **DxgkDdiConnectDoorbell** callback function. Available starting with Windows 11 version 22H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_1).

### `DxgkDdiDisconnectDoorbell`

A pointer to the **DxgkDdiDisconnectDoorbell** callback function. Available starting with Windows 11 version 22H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_1).

### `DxgkDdiDestroyDoorbell`

A pointer to the **DxgkDdiDestroyDoorbell** callback function. Available starting with Windows 11 version 22H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_1).

### `DxgkDdiNotifyWorkSubmission`

A pointer to the **DxgkDdiNotifyWorkSubmission** callback function. Available starting with Windows 11 version 22H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_1).

### `Reserved4`

Reserved. Available starting with Windows 11 version 22H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_1).

### `DxgkDdiCreateMemoryBasis`

A pointer to the **DxgkDdiCreateMemoryBasis** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiDestroyMemoryBasis`

A pointer to the **DxgkDdiDestroyMemoryBasis** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiStartDirtyTracking`

A pointer to the **DxgkDdiStartDirtyTracking** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiStopDirtyTracking`

A pointer to the **DxgkDdiStopDirtyTracking** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiQueryDirtyBitData`

A pointer to the **DxgkDdiQueryDirtyBitData** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiPrepareLiveMigration`

A pointer to the **DxgkDdiPrepareLiveMigration** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiSaveImmutableMigrationData`

A pointer to the **DxgkDdiSaveImmutableMigrationData** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiSaveMutableMigrationData`

A pointer to the **DxgkDdiSaveMutableMigrationData** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiEndLiveMigration`

A pointer to the **DxgkDdiEndLiveMigration** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiRestoreImmutableMigrationData`

A pointer to the **DxgkDdiRestoreImmutableMigrationData** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiRestoreMutableMigrationData`

A pointer to the **DxgkDdiRestoreMutableMigrationData** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiWriteVirtualizedInterrupt`

A pointer to the **DxgkDdiWriteVirtualizedInterrupt** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiSetVirtualGpuResources2`

A pointer to the **DxgkDdiSetVirtualGpuResources2** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiSetVirtualFunctionPauseState`

A pointer to the **DxgkDdiSetVirtualFunctionPauseState** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiOpenNativeFence`

A pointer to the **DxgkDdiOpenNativeFence** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiCloseNativeFence`

A pointer to the **DxgkDdiCloseNativeFence** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiSetNativeFenceLogBuffer`

A pointer to the **DxgkDdiSetNativeFenceLogBuffer** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiUpdateNativeFenceLogs`

A pointer to the **DxgkDdiUpdateNativeFenceLogs** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiCollectDbgInfo2`

A pointer to the **DxgkDdiCollectDbgInfo2** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiNotifyContextPriorityChange`

A pointer to the **DxgkDdiNotifyContextPriorityChange** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

### `DxgkDdiResetDisplayEngine`

A pointer to the **DxgkDdiResetDisplayEngine** callback function. Available starting with Windows 11 version 24H2 (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WDDM3_2).

## See also

[**DriverEntry of Display Miniport Driver**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver)