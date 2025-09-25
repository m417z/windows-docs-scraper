# _DXGKARG_SETTARGETCONTENTTYPE structure

## Description

Used to hold the arguments for [DXGKDDI_SETTARGETCONTENTTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settargetcontenttype)

## Members

### `TargetId`

The identifier of a display adapter's video present target.

### `ContentType`

A D3DKMDT_VIDPN_PRESENT_PATH_CONTENT value indicating the type of content being presented on the target id for which the driver should optimize.