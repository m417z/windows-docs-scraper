# _RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER structure

## Description

The **RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER** structure contains the connection properties for a target device that is connected to a serial bus (I2C, SPI, or UART).

## Members

### `Version`

The version number of this structure. This member is set to the RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_VERSION constant, which is defined in the Reshub.h header file.

### `PropertiesLength`

The size, in bytes, of the serial bus connection descriptor that starts with element 0 of the **ConnectionProperties** array.

### `ConnectionProperties`

The first byte of the serial bus connection descriptor. This byte is immediately followed by the remaining bytes of the descriptor. The **PropertiesLength** member specifies the total number of bytes occupied by the descriptor. The definition of the **ConnectionProperties** member uses the ANYSIZE_ARRAY constant, which the Ntdef.h header file defines to be 1. For more information, see Remarks.

## Syntax

```cpp
typedef struct _RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER {
  ULONG Version;
  ULONG PropertiesLength;
  UCHAR ConnectionProperties[ANYSIZE_ARRAY];
} RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER, *PRH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER;
```

## Remarks

The **ConnectionProperties** member of the **RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER** structure contains the first byte of the serial bus connection descriptor for the target device. The remaining bytes in the descriptor immediately follow this member in memory. The buffer allocated for the **RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER** structure is large enough to contain this structure plus the remaining bytes of the serial bus connection descriptor that extend past the end of the structure.

The format for the serial bus connection descriptor is described in the [ACPI 5.0 specification](https://uefi.org/specifications). For convenience, the Reshub.h header file defines the [PNP_SERIAL_BUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/reshub/ns-reshub-_pnp_serial_bus_descriptor) structure to enable drivers to access the values in this descriptor.

An SPB controller driver calls the [SpbTargetGetConnectionParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbtargetgetconnectionparameters) method to get the connection parameters for a target device on a [simple peripheral bus](https://learn.microsoft.com/previous-versions/hh450903(v=vs.85)) (typically, I²C or SPI). This method writes the connection parameters to an [SPB_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_connection_parameters) structure, and the **ConnectionParameters** member of this structure is a pointer to an **RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER** structure.

For a code example that uses the **RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER** structure, see [How to Get the Connection Settings for a Device](https://learn.microsoft.com/windows-hardware/drivers/spb/how-to-get-the-connection-settings-for-a-device).

## See also

[SPB_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_connection_parameters)

[SpbTargetGetConnectionParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbtargetgetconnectionparameters)

[PNP_SERIAL_BUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/reshub/ns-reshub-_pnp_serial_bus_descriptor)