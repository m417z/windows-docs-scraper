## Description

The **GNSS_DRIVERCOMMAND_PARAM** structure is used to send a command to the GNSS driver.

The command may involve configuring certain parameters and state variables of the underlying GNSS driver or device, or executing certain defined actions through the driver.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `CommandType`

Identifies the specific command that the driver is required to execute.

This is a well-defined list of GNSS driver commands, as defined by the [GNSS_DRIVERCOMMAND_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ne-gnssdriver-gnss_drivercommand_type) enumeration.

### `Reserved`

Reserved for future use.

### `CommandDataSize`

Size of the configuration data being sent to the driver.

### `Unused`

Padding buffer reserved for future use.

### `CommandData`

Data associated with the specific command type.

The driver must cast this buffer to the appropriate data type depending on the specific command.