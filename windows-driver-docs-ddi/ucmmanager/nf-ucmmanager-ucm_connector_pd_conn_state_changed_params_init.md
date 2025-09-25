# UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS_INIT function

## Description

Initializes a [UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_pd_conn_state_changed_params) structure.

## Parameters

### `Params` [out]

Pointer to a caller-allocated [UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_pd_conn_state_changed_params) structure to initialize.

### `PdConnState` [in]

A [UCM_PD_CONN_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_pd_conn_state)-typed flag that indicates the connection state of the partner port.

## See also

[UcmConnectorPdConnectionStateChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorpdconnectionstatechanged)