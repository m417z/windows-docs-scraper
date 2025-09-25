# _WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS structure

## Description

The WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS union describes which members of a [WHEA_PCIEXPRESS_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pciexpress_error_section) structure contain valid data.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.PortType`

A single bit that indicates that the **PortType** member of the WHEA_PCIEXPRESS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Version`

A single bit that indicates that the **Version** member of the WHEA_PCIEXPRESS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.CommandStatus`

A single bit that indicates that the **CommandStatus** member of the WHEA_PCIEXPRESS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.DeviceId`

A single bit that indicates that the **DeviceId** member of the WHEA_PCIEXPRESS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.DeviceSerialNumber`

A single bit that indicates that the **DeviceSerialNumber** member of the WHEA_PCIEXPRESS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.BridgeControlStatus`

A single bit that indicates that the **BridgeControlStatus** member of the WHEA_PCIEXPRESS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.ExpressCapability`

A single bit that indicates that the **ExpressCapability** member of the WHEA_PCIEXPRESS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.AerInfo`

A single bit that indicates that the **AerInfo** member of the WHEA_PCIEXPRESS_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `ValidBits`

A ULONGLONG representation of the contents of the WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS union.

## Remarks

A WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS union is contained within the [WHEA_PCIEXPRESS_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pciexpress_error_section) structure.

## See also

[WHEA_PCIEXPRESS_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pciexpress_error_section)