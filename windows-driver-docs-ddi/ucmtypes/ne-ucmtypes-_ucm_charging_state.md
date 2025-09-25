# _UCM_CHARGING_STATE enumeration

## Description

Defines the charging state of a Type-C connector.

## Constants

### `UcmChargingStateInvalid`

Indicates the charging state is invalid.

### `UcmChargingStateNotCharging`

Indicates the port is not drawing a charge.

### `UcmChargingStateNominalCharging`

Indicates the port is drawing a nominal charge.

### `UcmChargingStateSlowCharging`

Indicates the port is drawing a slow charge.

### `UcmChargingStateTrickleCharging`

Indicates the port is drawing a trickle charge.

## See also

[UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_pd_conn_state_changed_params)

[UCM_CONNECTOR_TYPEC_ATTACH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_typec_attach_params)

[UcmConnectorPdConnectionStateChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorpdconnectionstatechanged)

[UcmConnectorTypeCAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectortypecattach)