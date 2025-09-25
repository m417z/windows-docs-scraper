# SFFDISK_DCMD enumeration

## Description

The SFFDISK_DCMD enumeration identifies the type of Secure Digital (SD) card operation.

## Constants

### `SFFDISK_DC_GET_VERSION`

The operations retrieves the version of the card.

### `SFFDISK_DC_LOCK_CHANNEL`

The operation locks the interface channel.

### `SFFDISK_DC_UNLOCK_CHANNEL`

The operation unlocks the interface channel.

### `SFFDISK_DC_DEVICE_COMMAND`

The operation executes a device command.

## Remarks

Applications that submit IOCTL_SFFDISK_DEVICE_COMMAND requests to the SD stack use this enumeration to specify the type of operation. The application must assign one of the values of this enumeration to the **Command** member of the [SFFDISK_DEVICE_COMMAND_DATA](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff538133(v=vs.85)) structure.

## See also

[SFFDISK_DEVICE_COMMAND_DATA](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff538133(v=vs.85))