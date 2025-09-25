# DXGKDDI_GETPOSTCOMPOSITIONCAPS callback function

## Description

Called to retrieve post composition capabilities. Support for this DDI is required for any WDDM 2.2 driver that wants to support post composition scaling.

## Parameters

### `hAdapter`

Identifies the adapter containing the overlay hardware.

### `pGetPostCompositionCaps` [in/out]

A pointer to a [DXGKARG_GETPOSTCOMPOSITIONCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getpostcompositioncaps) structure that receives the driver capabilities.

## Return value

DXGKDDI_GETPOSTCOMPOSITIONCAPS returns the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|If the routine has been successfully completed.|

## Remarks

This function is called at PASSIVE_LEVEL.

The multiplane overlay capabilities are allowed to change due to display configuration changes.