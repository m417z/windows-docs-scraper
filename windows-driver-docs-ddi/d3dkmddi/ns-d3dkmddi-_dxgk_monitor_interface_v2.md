# DXGK_MONITOR_INTERFACE_V2 structure

## Description

The **DXGK_MONITOR_INTERFACE_V2** structure contains pointers to functions that belong to the monitor interface, which is implemented by the video present network (VidPN) manager.

## Members

### `Version`

A value from the [**DXGK_MONITOR_INTERFACE_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_monitor_interface_version) enumeration that indicates the monitor interface version. Must be set to 2.

### `pfnAcquireMonitorSourceModeSet`

A pointer to the [**pfnAcquireMonitorSourceModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset) function.

### `pfnReleaseMonitorSourceModeSet`

A pointer to the [**pfnReleaseMonitorSourceModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_releasemonitorsourcemodeset) function.

### `pfnGetMonitorFrequencyRangeSet`

A pointer to the [**pfnGetMonitorFrequencyRangeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitorfrequencyrangeset) function.

### `pfnGetMonitorDescriptorSet`

A pointer to the [**pfnGetMonitorDescriptorSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getmonitordescriptorset) function.

### `pfnGetAdditionalMonitorModeSet`

A pointer to the [**pfnGetAdditionalMonitorModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getadditionalmonitormodeset) function.

### `pfnReleaseAdditionalMonitorModeSet`

A pointer to the [**pfnReleaseAdditionalMonitorModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_releaseadditionalmonitormodeset) function.

## Remarks

A display miniport driver must verify the interface version specified in the **Version** member before using this structure.

## See also

[**DXGK_MONITOR_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface)