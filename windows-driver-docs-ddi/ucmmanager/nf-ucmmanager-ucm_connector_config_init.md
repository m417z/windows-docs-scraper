# UCM_CONNECTOR_CONFIG_INIT function

## Description

Initializes a [UCM_CONNECTOR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_config) structure.

## Parameters

### `Config` [out]

Pointer to a caller-allocated [UCM_CONNECTOR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_config) structure to initialize.

### `ConnectorId` [in]

The identifier to assign to the connector object. If there is only one connector, pass 0.

## See also

[UCM_MANAGER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_manager_config)