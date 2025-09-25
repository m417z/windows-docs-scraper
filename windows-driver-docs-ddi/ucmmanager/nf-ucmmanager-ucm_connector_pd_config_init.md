# UCM_CONNECTOR_PD_CONFIG_INIT function

## Description

Initializes a [UCM_CONNECTOR_PD_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_pd_config) structure.

## Parameters

### `Config` [out]

Pointer to a caller-allocated [UCM_CONNECTOR_PD_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_pd_config) structure to initialize.

### `SupportedPowerRoles` [in]

A bitwise OR of [UCM_POWER_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_power_role)-typed flags.

## See also

[UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)