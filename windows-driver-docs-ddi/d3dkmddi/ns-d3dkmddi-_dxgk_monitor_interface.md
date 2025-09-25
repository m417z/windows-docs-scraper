# DXGK_MONITOR_INTERFACE structure

## Description

The **DXGK_MONITOR_INTERFACE** structure contains pointers to functions that belong to the monitor Interface, which is implemented by the video present network (VidPN) manager.

## Members

### `Version`

A value from the [**DXGK_MONITOR_INTERFACE_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_monitor_interface_version) enumeration that indicates the monitor interface version. Must be set to 1.

### `pfnAcquireMonitorSourceModeSet`

A pointer to the [**pfnAcquireMonitorSourceModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset) function.

### `pfnReleaseMonitorSourceModeSet`

A pointer to the [**pfnReleaseMonitorSourceModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_releasemonitorsourcemodeset) function.

### `pfnGetMonitorFrequencyRangeSet`

A pointer to the [**pfnGetMonitorFrequencyRangeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitorfrequencyrangeset) function.

### `pfnGetMonitorDescriptorSet`

A pointer to the [**pfnGetMonitorDescriptorSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitordescriptorset) function.

## Remarks

A display miniport driver must verify the interface version specified in the **Version** member before using this structure.

## See also

[**DXGK_MONITOR_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2)