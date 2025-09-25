# _PNP_SERIAL_BUS_DESCRIPTOR structure

## Description

The **PNP_SERIAL_BUS_DESCRIPTOR** structure describes the physical connection of a target device to a serial bus (I2C, SPI, or UART).

## Members

### `Tag`

The serial bus type. This member is set to 0x8e for a serial bus (I2C, SPI, or UART) connection. For more information, see the description of the serial bus connection descriptor in the [ACPI 5.0 specification](https://uefi.org/specifications).

### `Length`

The length, in bytes, of the serial bus connection descriptor. To be consistent with the ACPI 5.0 specification, the byte count in the **Length** member of the **PNP_SERIAL_BUS_DESCRIPTOR** structure equals the structure size, minus the three bytes in the **Tag** and **Length** members at the start of the structure, plus the number of bytes of bus-type-specific data and Resource Source string that follow the structure. The Resource Source string, which is a required field, has a minimum size of two bytes (for a one-character Resource Source name and a terminating null). Thus, the minimum valid **Length** value is 11. For more information, see the ACPI 5.0 specification.

### `RevisionId`

The revision ID of the serial bus connection descriptor. This member is set to the SERIAL_BUS_DESCRIPTOR_REVISION constant, which is defined in the Reshub.h header file.

### `ResourceSourceIndex`

Reserved for future use. This member is unused and set to zero.

### `SerialBusType`

The serial bus type. This member is set to 1 (for I2C), 2 (for SPI), or 3 (for UART). Other values are either reserved for future use, or are defined by the hardware vendor. For more information, see the ACPI 5.0 specification.

### `GeneralFlags`

Flags that are common to all serial bus types. Bit 0 is the subordinate-mode flag. If this bit is set to 1, the communication of this connection is initiated by the bus controller; otherwise, the communication is initiated by the target device. Bit 1 is the consumer/producer flag, and is always set to 1. No other flag bits are currently defined. For more information, see the ACPI 5.0 specification.

### `TypeSpecificFlags`

Flags that are specific to the serial bus type. For an I2C bus, bit 0 is set if the connection uses 10-bit addresses; otherwise, the connection uses 7-bit addresses. No other flag bits are currently defined for I2C. For more information, see the ACPI 5.0 specification.

### `TypeSpecificRevisionId`

The revision ID of the variant of this structure that is used for the serial bus type (I2C, SPI, and UART) that is specified by the **Tag** member. Each serial bus type extends the **PNP_SERIAL_BUS_DESCRIPTOR** structure by adding fields that are specific to the bus type. For more information, see the ACPI 5.0 specification.

### `TypeDataLength`

The length, in bytes, of the bus-type-specific data that follows the **PNP_SERIAL_BUS_DESCRIPTOR** structure. This length value includes the data between the end of the **TypeDataLength** member and the start of the Resource Source string, but does not include the Resource Source string. For more information, see the ACPI 5.0 specification.

## Syntax

```cpp
typedef struct _PNP_SERIAL_BUS_DESCRIPTOR {
  UCHAR  Tag;
  USHORT Length;
  UCHAR  RevisionId;
  UCHAR  ResourceSourceIndex;
  UCHAR  SerialBusType;
  UCHAR  GeneralFlags;
  USHORT TypeSpecificFlags;
  UCHAR  TypeSpecificRevisionId;
  USHORT TypeDataLength;
} PNP_SERIAL_BUS_DESCRIPTOR, *PPNP_SERIAL_BUS_DESCRIPTOR;
```

## Remarks

This structure defines the data fields in a serial bus connection descriptor, as described in section 6.4.3.8.2 of the ACPI 5.0 specification. This descriptor describes the bus connection to a target device that is connected to a serial bus (I2C, SPI, or UART).

For example, for a device on an I2C bus, the **PNP_SERIAL_BUS_DESCRIPTOR** structure (and its bus-type-specific extension) specify the bus address of the device, the address mode (7-bit or 10-bit), and the frequency at which to run the bus clock when the device is accessed. For a code example that shows how an I2C controller driver extracts this information from the structure, see [How to Get the Connection Settings for a Device](https://learn.microsoft.com/windows-hardware/drivers/spb/how-to-get-the-connection-settings-for-a-device).

The **PNP_SERIAL_BUS_DESCRIPTOR** structure definition in the Reshub.h header file is preceded by an include statement for the Pshpack1.h header file, which configures the compiler to pack adjacent structure members to byte boundaries, without intervening gaps. Software can then overlay the packed structure over the memory image of the serial bus connection descriptor to access the individual fields of this descriptor. The USHORT members of the structure might not be aligned to even byte boundaries in memory. The bytes in the USHORT members are stored in little-endian order for the x86, x64, and ARM processor architectures.