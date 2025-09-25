# STOR_RICH_DEVICE_DESCRIPTION structure

## Description

The **STOR_RICH_DEVICE_DESCRIPTION** structure describes the attributes of the **physical device** for which a driver is requesting a DMA (direct memory access) adapter.

## Members

### `Version`

The version of the structure. Must be **STOR_RICH_DEVICE_DESCRIPTION_STRUCTURE_VERSION**.

### `Size`

The size of the structure, in bytes.

### `VendorId[STOR_VENDOR_ID_LENGTH` + 1]

A string representing the device’s vendor ID. May be an empty string if **ModelNumber** is provided.

### `ModelNumber[STOR_MODEL_NUMBER_LENGTH` + 1]

A string representing the device’s model.

### `FirmwareRevision[STOR_FIRMWARE_REVISION_LENGTH` + 1]

A string representing the device’s currently active firmware revision.

## Remarks

A miniport can choose to support this unit control if the device reports longer **ModelNumber** or **FirmwareRevision** information than defined in SCSI.

This is invoked during the unit enumeration process or the device description update process. **ScsiUnitRichDescription** is a caller-allocated version of this structure.

## See also

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)