# _DXGKARG_RECOMMENDMONITORMODES structure

## Description

The DXGKARG_RECOMMENDMONITORMODES structure contains arguments for the [DxgkDdiRecommendMonitorModes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendmonitormodes) function.

## Members

### `VideoPresentTargetId`

An integer that identifies a video present target on the display adapter.

### `hMonitorSourceModeSet`

A handle to a monitor source mode set object. This set contains a list of modes that are supported by the monitor that is connected to the video present target identified by *VideoPresentTargetId*.

### `pMonitorSourceModeSetInterface`

A pointer to a [DXGK_MONITORSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitorsourcemodeset_interface) structure. The structure contains pointers to functions that the display miniport driver can use to inspect, and possibly add modes to, the monitor source mode set.

## See also

[DXGK_MONITORSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitorsourcemodeset_interface)

[DxgkDdiRecommendMonitorModes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendmonitormodes)