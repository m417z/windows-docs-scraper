## Description

The **DXGK_DISPLAYMUX_INTERFACE_2** structure contains pointers to functions that are implemented by the kernel-mode display miniport driver (KMD) to support version 2 of the [automatic display switching](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch) feature.

## Members

### `Size`

[in] The size, in bytes, of this structure.

### `Version`

[in] The version number of the display mux interface. **Version** should be set to **DXGK_DISPLAYMUX_INTERFACE_VERSION_1** for this structure.

### `Context`

[in] A pointer to a private context block.

### `InterfaceReference`

[out] Pointer to a KMD-implemented interface reference function.

### `InterfaceDereference`

[out] Pointer to a KMD-implemented interface dereference function.

### `DxgkDdiDisplayMuxGetDriverSupportLevel`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxGetDriverSupportLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_get_driver_support_level) callback function.

### `DxgkDdiDisplayMuxGetRuntimeStatus`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxGetRuntimeStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_get_runtime_status) callback function.

### `DxgkDdiDisplayMuxPreSwitchAway`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxPreSwitchAway**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_pre_switch_away) callback function.

### `DxgkDdiDisplayMuxPreSwitchAwayGetPrivateData`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxPreSwitchAwayGetPrivateData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_pre_switch_away_get_private_data) callback function.

### `DxgkDdiDisplayMuxPreSwitchTo`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxPreSwitchTo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_pre_switch_to) callback function.

### `DxgkDdiDisplayMuxSwitchCanceled`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxSwitchCanceled**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_switch_canceled) callback function.

### `DxgkDdiDisplayMuxPostSwitchAway`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxPostSwitchAway**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_post_switch_away) callback function.

### `DxgkDdiDisplayMuxPostSwitchToPhase1`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxPostSwitchToPhase1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_post_switch_to_phase1) callback function.

### `DxgkDdiDisplayMuxPostSwitchToPhase2`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxPostSwitchToPhase2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_post_switch_to_phase2) callback function.

### `DxgkDdiDisplayMuxUpdateState`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxUpdateState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_update_state) callback function.

### `DxgkDdiDisplayMuxReportPresence`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxReportPresence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_report_presence) callback function.

### `DxgkDdiDisplayMuxSetInternalPanelInfo`

[out] Pointer to KMD's [**DxgkDdiDisplayMuxSetInternalPanelInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_set_internal_panel_info) callback function.

## Remarks

The OS queries for KMD's **DXGK_DISPLAYMUX_INTERFACE_2** at driver start. It does so by calling KMD's [**DxgkDdiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) function with [**QueryInterface->InterfaceType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_query_interface) set to GUID_WDDM_INTERFACE_DISPLAYMUX_2. If the KMD supports this interface, it returns a **DXGK_DISPLAYMUX_INTERFACE_2** structure with pointers to its automatic display switch callbacks.

A driver that exposes the GUID_WDDM_INTERFACE_DISPLAYMUX_2 interface must set [**DXGK_CHILD_CAPABILITIES.Type.IntegratedDisplayChild.DescriptorLength**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_integrated_display_child) to zero at adapter start if the mux isn't currently switched to the driver's GPU. Otherwise, the OS will fail the adapter start.

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DxgkddiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface)

[**QUERY_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_query_interface)