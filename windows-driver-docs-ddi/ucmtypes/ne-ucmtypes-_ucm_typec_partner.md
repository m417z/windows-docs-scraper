# _UCM_TYPEC_PARTNER enumeration

## Description

Defines the state of the Type-C connector.

## Constants

### `UcmTypeCPartnerInvalid`

The partner port state is invalid.

### `UcmTypeCPartnerUfp`

The partner is an upstream facing port (UFP).

### `UcmTypeCPartnerDfp`

The partner is a downstream facing port (DFP).

### `UcmTypeCPartnerPoweredCableNoUfp`

The partner is a powered cable that requires VConn, that currently does not have a UFP attached on the other end.

### `UcmTypeCPartnerPoweredCableWithUfp`

The partner is a powered and upstream facing.

### `UcmTypeCPartnerAudioAccessory`

The partner is used as an audio accessory.

### `UcmTypeCPartnerDebugAccessory`

The partner is a debug accessory.

## See also

- [UCM_CONNECTOR_TYPEC_ATTACH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_typec_attach_params)
- [UcmConnectorTypeCAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectortypecattach)