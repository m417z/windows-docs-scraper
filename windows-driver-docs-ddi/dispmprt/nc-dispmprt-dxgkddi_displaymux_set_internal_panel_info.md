## Description

*Dxgkrnl* calls the kernel-mode display driver's (KMD) **DxgkddiDisplayMuxSetInternalPanelInfo** function to provide the driver with information about the internal panel.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `VidPnTargetId`

[in] The VidPN target that the DDI is being called for.

### `pInternalPanelInfo`

[in] Pointer to a [**DXGK_DISPLAYMUX_SET_INTERNAL_PANEL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-dxgk_displaymux_set_internal_panel_info) structure that contains information about the internal panel.

## Return value

**DxgkddiDisplayMuxSetInternalPanelInfo** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns an appropriate error code.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

When an adapter is started but the mux isn't yet connected to the adapter, the driver can't communicate with the internal panel to collect information. On the first mux switch to that adapter, the OS calls **DxgkddiDisplayMuxSetInternalPanelInfo** to provide this internal panel information to the driver. The driver can subsequently report the internal panel information to the OS correctly.

**DxgkddiDisplayMuxSetInternalPanelInfo** is called only once during the first instance of a mux switch to a specific adapter after that adapter has been started, provided that the mux wasn't connected to the adapter when the adapter was started. This call is made just before [**DxgkDdiDisplayMuxPreSwitchTo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_pre_switch_to) is called.

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DXGK_DISPLAYMUX_SET_INTERNAL_PANEL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-dxgk_displaymux_set_internal_panel_info)

[**DxgkDdiDisplayMuxPreSwitchTo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_pre_switch_to)