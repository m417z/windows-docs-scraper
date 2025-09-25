# _DXGKARG_UPDATEMONITORLINKINFO structure

## Description

Contains arguments for the [DXGKDDI_UPDATEMONITORLINKINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatemonitorlinkinfo) callback function.

## Members

### `VideoPresentTargetId`

The identifier of a display adapter's video present target.

### `MonitorLinkInfo`

Pointer to a [DXGK_MONITORLINKINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitorlinkinfo) structure, which the driver must fill to describe the capabilities of the monitor over the link through which it has been attached.

## Remarks

## See also