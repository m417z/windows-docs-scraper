## Description

**STOR_RICH_DEVICE_DESCRIPTION** is the structure pointed to by the **Parameters** parameter when a miniport's **[HwStorUnitControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)** routine is called with a **ControlType** of **ScsiUnitRichDescription**.

## Members

### `Version`

The version of the structure. This value should be **STOR_RICH_DEVICE_DESCRIPTION_STRUCTURE_VERSION_V2**.

### `Size`

The size of the structure, in bytes. Should be `sizeof(STOR_RICH_DEVICE_DESCRIPTION_V2)`.

### `VendorId[STOR_VENDOR_ID_LENGTH` + 1]

A string representing the device's vendor ID. May be an empty string if **ModelNumber** is provided. The miniport should fill this in.

### `ModelNumber[STOR_MODEL_NUMBER_LENGTH` + 1]

A string representing the device's model. The miniport should fill this in.

### `FirmwareRevision[STOR_FIRMWARE_REVISION_LENGTH` + 1]

A string representing the device's currently active firmware revision. The miniport should fill this in.

## See also

- **[HwStorUnitControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)**