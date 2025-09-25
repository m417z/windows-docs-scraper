# _MSFC_FCAdapterHBAAttributes structure

## Description

The MSFC_FCAdapterHBAAttributes structure is used by a WMI provider to expose attribute information associated with a fibre channel adapter.

## Members

### `UniqueAdapterId`

Indicates the unique adapter ID.

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `NodeWWN`

Contains the 64 bit world-wide name that indicates the node name of the HBA. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

### `VendorSpecificID`

Indicates a vendor-specific ID.

### `NumberOfPorts`

Indicates the number of ports on the HBA.

### `Manufacturer`

Contains an ASCII string that is 64 bytes or fewer in length and that identifies the name of the manufacturer of the HBA.

### `SerialNumber`

Contains an ASCII string that is 64 bytes or fewer in length and that identifies the serial number of the HBA.

### `Model`

Contains an ASCII string that is 256 bytes or fewer in length and that identifies the vendor-specific name of the HBA model.

### `ModelDescription`

Contains an ASCII string that is 256 bytes or fewer in length and that indicates the model description.

### `NodeSymbolicName`

Contains an ASCII string that is 256 bytes or fewer in length and that indicates the symbolic name for the fibre channel node.

### `HardwareVersion`

Contains an ASCII string that is 256 bytes or fewer in length and that indicates the vendor-specific hardware revision level of the HBA.

### `DriverVersion`

Contains an ASCII string that is 256 bytes or fewer in length and that indicates the vendor-specific version of the HBA miniport driver.

### `OptionROMVersion`

Contains an ASCII string that is 256 bytes or fewer in length and that indicates the vendor-specific option ROM or BIOS version of the HBA.

### `FirmwareVersion`

Contains an ASCII string that is 256 bytes or fewer in length and that indicates the vendor-specific firmware version of the HBA.

### `DriverName`

Contains an ASCII string that is 256 bytes or fewer in length and that indicates the file name for the driver binary file.

### `MfgDomain`

Contains the name of the HBA manufacturer.

## See also

[HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[MSFC_FCAdapterHBAAttributes WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-fcadapterhbaattributes-wmi-class)