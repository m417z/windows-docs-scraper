# _IDEREGS structure

## Description

The IDEREGS structure is used to report the contents of the IDE controller registers.

## Members

### `bFeaturesReg`

Holds the contents of the Features register. This register is used to specify Self-Monitoring Analysis and Reporting Technology (SMART) commands. This member can hold any of the following values:

| Feature | Meaning |
| --- | --- |
| READ_ATTRIBUTES | Retrieve the device attributes |
| READ_THRESHOLDS. | Retrieve threshold values that indicate when a drive is about to fail. |
| ENABLE_DISABLE_AUTOSAVE. | Enables the optional attribute autosave feature of the device when set to 1. Disables this feature when set to 0.. |
| SAVE_ATTRIBUTE_VALUES. | Instructs the device to save its attribute values to the device's non-volatile memory. |
| EXECUTE_OFFLINE_DIAGS | Causes the device to begin collecting SMART data in off-line mode or execute a self-diagnostic test routine in either captive or off-line mode. |
| SMART_READ_LOG | Retrieves the indicated log. |
| SMART_WRITE_LOG | Writes the indicated number of 512-byte data sectors to the indicated log. |
| ENABLE_SMART | Enables SMART functionality on the device. |
| DISABLE_SMART | Disables SMART functionality on the device. |
| RETURN_SMART_STATUS | Retrieves the reliability status of the device. |
| ENABLE_DISABLE_AUTO_OFFLINE | Enables offline mode when set to 1. Disables offline mode when 0. |

### `bSectorCountReg`

Holds the contents of the sector count register. IDE sector count register.

### `bSectorNumberReg`

Holds the contents of the sector number register.

### `bCylLowReg`

Holds the contents of the IDE low-order cylinder register.

### `bCylHighReg`

Holds the contents of the IDE high-order cylinder register.

### `bDriveHeadReg`

Holds the contents of the IDE drive/head register.

### `bCommandReg`

Holds the contents of the IDE command register.

### `bReserved`

Reserved for future use. Should always be zero.

## See also

[ATA_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_direct)

[ATA_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_ex)