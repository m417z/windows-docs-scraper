# UCM_CONNECTOR_TYPEC_ATTACH_PARAMS_INIT function

## Description

Initializes a [UCM_CONNECTOR_TYPEC_ATTACH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_typec_attach_params) structure.

## Parameters

### `Params`

Pointer to a caller-allocated [**UCM_CONNECTOR_TYPEC_ATTACH_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_typec_attach_params) structure to initialize.

### `Partner`

A [**UCM_TYPE_C_PORT_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_typec_partner)-typed flag that indicates the state of the partner port.

## See also

[UcmConnectorTypeCAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectortypecattach)