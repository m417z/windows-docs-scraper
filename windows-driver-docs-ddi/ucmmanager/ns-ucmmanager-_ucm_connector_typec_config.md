# _UCM_CONNECTOR_TYPEC_CONFIG structure

## Description

Describes the configuration options for a Type-C connector.

## Members

### `Size`

Size of the **UCM_CONNECTOR_TYPEC_CONFIG** structure.

### `IsSupported`

TRUE indicates a Type-C connector. FALSE, otherwise. is supported.

### `SupportedOperatingModes`

Indicates the supported operating mode of the connector. This value is a bitwise OR of [UCM_TYPEC_OPERATING_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_typec_operating_mode)-typed flags.

### `SupportedPowerSourcingCapabilities`

Indicates the supported power source capabilities of the connector. This value is a bitwise OR of [UCM_TYPEC_CURRENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_typec_current)-typed flags.

### `AudioAccessoryCapable`

Indicates whether the connector is capable of detecting a USB Type-C analog input as 3.5 mm audio jack.

### `EvtSetDataRole`

A pointer to the client driver's implementation of the [EVT_UCM_CONNECTOR_SET_DATA_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nc-ucmmanager-evt_ucm_connector_set_data_role) callback function.

## Remarks

Initialize this structure by calling [UCM_CONNECTOR_TYPEC_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_connector_typec_config_init). An initialized **UCM_CONNECTOR_TYPEC_CONFIG** structure is an input parameter value to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate) that is used by Policy Manager to create a connector object.

## See also

[UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)