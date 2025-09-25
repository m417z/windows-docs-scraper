## Description

The **STOR_POWER_ACTION** enumerator indicates the power state that the system is about to enter during a power transition.

## Constants

### `StorPowerActionNone`

No system shutdown is about to occur.

### `StorPowerActionReserved`

Reserved.

### `StorPowerActionSleep`

The system is entering standby.

### `StorPowerActionHibernate`

The system is entering hibernation.

### `StorPowerActionShutdown`

The system is shutting down, but the type of shutdown is not known.

### `StorPowerActionShutdownReset`

The system is shutting down and resetting.

### `StorPowerActionShutdownOff`

The system is shutting down and powering off.

### `StorPowerActionWarmEject`

The system is preparing for ejection.

## See also

[SCSI_POWER_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_scsi_power_request_block)