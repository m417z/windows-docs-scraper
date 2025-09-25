# UCM_CONNECTOR_TYPEC_CONFIG_INIT function

## Description

Initializes the [UCM_CONNECTOR_TYPEC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_typec_config) structure.

## Parameters

### `Config` [out]

Pointer to a caller-allocated [UCM_CONNECTOR_TYPEC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_typec_config) structure to initialize.

### `SupportedOperatingModes` [in]

Indicates the operating mode of the connector. This value is a bitwise OR of [UCM_TYPEC_OPERATING_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_typec_operating_mode)-typed flags.

### `SupportedPowerSourcingCapabilities` [in]

Indicates the power source capabilities of the connector. This value is a bitwise OR of [UCM_TYPEC_CURRENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_typec_current)-typed flags.