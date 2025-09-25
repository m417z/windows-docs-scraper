# _MS_SM_AdapterInformationQuery structure

## Description

The MS_SM_AdapterInformationQuery structure is used by a WMI provider to expose attributes that are associated with a SAS adapter.

## Members

### `UniqueAdapterId`

The unique adapter ID.

### `HBAStatus`

The status of the operation.

### `NumberOfPorts`

The number of ports on the HBA.

### `VendorSpecificID`

A vendor-specific ID.

### `Manufacturer`

An ASCII string that is 64 bytes or fewer in length and that identifies the name of the manufacturer of the HBA.

### `SerialNumber`

An ASCII string that is 64 bytes or fewer in length and that identifies the serial number of the HBA.

### `Model`

An ASCII string that is 256 bytes or fewer in length and that identifies the vendor-specific name of the HBA model.

### `ModelDescription`

An ASCII string that is 256 bytes or fewer in length and that indicates the model description.

### `HardwareVersion`

An ASCII string that is 256 bytes or fewer in length and that indicates the vendor-specific hardware revision level of the HBA.

### `DriverVersion`

An ASCII string that is 256 bytes or fewer in length and that indicates the vendor-specific version of the HBA miniport driver.

### `OptionROMVersion`

An ASCII string that is 256 bytes or fewer in length and that indicates the vendor-specific option ROM or BIOS version of the HBA.

### `FirmwareVersion`

An ASCII string that is 256 bytes or fewer in length and that indicates the vendor-specific firmware version of the HBA.

### `DriverName`

An ASCII string that is 256 bytes or fewer in length and that indicates the file name for the driver binary file.

### `HBASymbolicName`

An ASCII string that is 256 bytes or fewer in length and that indicates the symbolic name for the fibre channel node.

### `RedundantOptionROMVersion`

An ASCII string that is 256 bytes or fewer in length and that indicates the vendor-specific option ROM or BIOS version of the HBA.

### `RedundantFirmwareVersion`

An ASCII string that is 256 bytes or fewer in length and that indicates the vendor-specific firmware version of the HBA.

### `MfgDomain`

The name of the HBA manufacturer.