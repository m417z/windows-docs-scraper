# DXGKDDI_SETTARGETCONTENTTYPE callback function

## Description

Passes the content type for which the driver should optimize on the specified target.

**Note** This is functionally equivalent to the DxgkDdi_UpdateActiveVidPnPresentPath in previous WDDM versions if only the D3DKMDT_VIDPN_PRESENT_PATH_CONTENT field is changed.

## Parameters

### `hAdapter`

A handle that identifies the adapter.

### `pSetTargetContentTypeArg`

A pointer to a [DXGKARG_SETTARGETCONTENTTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_settargetcontenttype) structure that provides the target to be modified and the new type of content being displayed on it.

## Return value

If this routine succeeds, it returns STATUS_SUCCESS.

## Remarks

This is an optional DDI, so the function pointer in DRIVER_INITIALIZATION_DATA should be set to null if the DDI is not implemented for every adapter supported by the driver.
This function is always called at PASSIVE level so the supporting code should be made pageable.