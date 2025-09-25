# _UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS structure

## Description

Describes the parameters for PD connection changed event.

## Members

### `Size`

Size of the **UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS** structure.

### `PdConnState`

The state of the connector indicated by one of the [UCM_PD_CONN_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_pd_conn_state)-typed flags.

### `Rdo`

An initialized [UCM_PD_REQUEST_DATA_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ns-ucmtypes-_ucm_pd_request_data_object) structure that describes the characteristics of the new connection state.

### `ChargingState`

Charging state of the port indicated by one of the [UCM_CHARGING_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_charging_state)-typed flags.

## Remarks

Initialize this structure by calling [UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_connector_pd_conn_state_changed_params_init). An initialized **UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS** structure is an input parameter value to [UcmConnectorPdConnectionStateChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorpdconnectionstatechanged) that is used by the client driver to notify UcmCx about the Attached state of the port.

## See also

[UcmConnectorPdConnectionStateChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorpdconnectionstatechanged)

[UcmConnectorTypeCAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectortypecattach)