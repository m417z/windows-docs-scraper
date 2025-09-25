# _UCM_CONNECTOR_TYPEC_ATTACH_PARAMS structure

## Description

Describes the partner that is currently attached to the connector.

## Members

### `Size`

Size of the **UCM_CONNECTOR_TYPEC_ATTACH_PARAMS** structure.

### `Partner`

The type of partner attached to the connector, indicated by a [UCM_TYPEC_PARTNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_typec_partner) value.

### `CurrentAdvertisement`

Power sourcing capabilities of: the partner port when **PortPartnerType** is **UcmTypeCPortStateDfp**; the local port when **PortPartnerType** is not **UcmTypeCPortStateDfp**.

### `ChargingState`

Optional. Charging state of the port indicated by one of the [UCM_CHARGING_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_charging_state)-typed flags.

## Remarks

Initialize this structure by calling [UCM_CONNECTOR_TYPEC_ATTACH_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_connector_typec_attach_params_init). An initialized **UCM_CONNECTOR_TYPEC_ATTACH_PARAMS** structure is an input parameter value to [UcmConnectorTypeCAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectortypecattach) that is used by the client driver to notify UcmCx about the Attached state of the port.

## See also

- [UcmConnectorTypeCAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectortypecattach)