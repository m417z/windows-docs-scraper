# DXGKDDI_QUERYCONNECTIONCHANGE callback function

## Description

The OS calls **DXGKDDI_QUERYCONNECTIONCHANGE** in response to a status change reported through [**DxgkCbIndicateConnectorChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_indicate_connector_change) or when the **OutputFlags.ConnectorStatusChanges** field indicates that a call to [**SetTimingsFromVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn) has detected connector status changes.

## Parameters

### `hAdapter`

A handle that identifies the adapter.

### `pQueryConnectionChange`

A pointer to a [**DXGKARG_QUERYCONNECTIONCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryconnectionchange) structure that provides the OS allocated buffer into which the oldest change should be copied by the driver. The oldest change is judged by lowest [**ConnectionChangeId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_connection_change).

## Return value

|Return value|Description|
|--- |--- |
|STATUS_SUCCESS|Returned if the routine succeeds and returns the requested change.|
|STATUS_ALREADY_COMPLETE|Returned if the routine succeeds, but the changes have already been reported to the OS.|

## Remarks

This function is always called at PASSIVE level so the supporting code should be made pageable.