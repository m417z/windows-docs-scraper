# DXGKDDI_GETMULTIPLANEOVERLAYCAPS callback function

## Description

Called to retrieve multiplane overlay capabilities. Support for this DDI is required for any WDDM 2.2 driver that wants to support multiple planes.

## Parameters

### `hAdapter` [in]

Identifies the adapter containing the overlay hardware.

### `pGetMultiPlaneOverlayCaps` [in/out]

A pointer to a [DXGKARG_GETMULTIPLANEOVERLAYCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getmultiplaneoverlaycaps) structure that receives the driver capabilities.

## Return value

DXGKDDI_GETMULTIPLANEOVERLAYCAPS returns the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|If the routine has been successfully completed.|

## Remarks

This function is called at PASSIVE_LEVEL.

The multiplane overlay capabilities are allowed to change due to display configuration changes.

For WDDM 2.2 drivers, this DDI is used to retrieve the multiplane overlay capabilities rather than the user mode DDIs.