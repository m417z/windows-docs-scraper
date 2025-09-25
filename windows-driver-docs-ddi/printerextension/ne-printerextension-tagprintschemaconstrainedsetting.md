## Description

The PrintSchemaConstrainedSetting enumeration specifies whether the Option is available based on the current device configuration. The **constrained** attribute appears only in a PrintCapabilities document.

## Constants

### `PrintSchemaConstrainedSetting_None`

The Option is not constrained.

### `PrintSchemaConstrainedSetting_PrintTicket`

The Option is constrained by the PrintTicket settings. Changing the PrintTicket document settings should be able to remove the constraint.

### `PrintSchemaConstrainedSetting_Admin`

The Option is constrained by the administrator's settings. The Option constraint should not be removable by a user without administrator privileges.

### `PrintSchemaConstrainedSetting_Device`

The Option is constrained by the device configuration. The Option should not be removable by either a user or administrator without changing the device configuration.

## See also

[IPrintSchemaOption::Constrained](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaoption-get_constrained)