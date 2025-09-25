# _UCM_CONNECTOR_CONFIG structure

## Description

Describes the configuration options for a Type-C connector object. An initialized [UCM_MANAGER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_manager_config) structure is an input parameter value to [UcmInitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucminitializedevice).

## Members

### `Size`

Size of the **UCM_CONNECTOR_CONFIG** structure.

### `ConnectorId`

Connector identifier.

### `TypeCConfig`

A pointer to an initialized [UCM_CONNECTOR_TYPEC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_typec_config) structure that contains the configuration options for the connector.

### `PdConfig`

A pointer to an initialized [UCM_CONNECTOR_PD_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_pd_config) structure that contains the power roles supported by the connector.

## Remarks

Initialize this structure by calling [UCM_CONNECTOR_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_connector_config_init). An initialized **UCM_CONNECTOR_CONFIG** structure is an input parameter value to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate) that is used by the client driver to create a connector object.

## See also

- [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)