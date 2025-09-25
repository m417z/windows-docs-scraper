# _BTHX_CAPABILITIES structure

## Description

The BTHX_CAPABILITIES structure describes the capabilities of the Bluetooth Extensible Transport Driver.

## Members

### `MaxAclTransferInSize`

The maximum size, in bytes, of the ACL packets the transport layer can accept.

### `ScoSupport`

The type of SCO supported. This must be set to **ScoSupportHCIBypass**.

### `MaxScoChannels`

The maximum supported number of SCO channels. This must be set to 1.

### `IsDeviceIdleCapable`

Whether the device supports idle/sleep power state. TRUE if the device can support idle (in low duty cycle state), else FALSE.

### `IsDeviceWakeCapable`

Whether the device supports remote wake. TRUE if the device supports waking the system from sleep, else FALSE.