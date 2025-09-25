# _UCM_CONNECTOR_PD_CONFIG structure

## Description

Describes the Power Delivery 2.0 capabilities of the connector.

## Members

### `Size`

Size of the **UCM_CONNECTOR_PD_CONFIG** structure.

### `IsSupported`

If TRUE, a PD role is supported. (Default).

If FALSE, a PD role is not supported.

### `SupportedPowerRoles`

Indicates the operating mode of the connector. This value is a bitwise OR of [UCM_POWER_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_power_role)-typed flags.

### `EvtSetPowerRole`

A pointer to the Policy Manager's implementation of the [EVT_UCM_CONNECTOR_SET_POWER_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nc-ucmmanager-evt_ucm_connector_set_power_role) event callback.

## Remarks

Initialize this structure by calling [UCM_CONNECTOR_PD_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_connector_pd_config_init). An initialized [UCM_CONNECTOR_TYPEC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_typec_config) structure is set to the **PdConfig** member of the [UCM_CONNECTOR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_config) structure, which is an input parameter value to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate) that is called by Policy Manager to create a connector object.

## See also

[UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)