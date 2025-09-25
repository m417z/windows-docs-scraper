## Description

>[!WARNING]
>[**HalGetBusDataByOffset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halgetbusdatabyoffset) and **HalSetBusDataByOffset** are provided for backward compatibility but should be used only if the methods recommended in [Accessing Device Configuration Space](https://learn.microsoft.com/windows-hardware/drivers/kernel/accessing-device-configuration-space) cannot be used.

This function sets bus-configuration data for a device on a dynamically configurable I/O bus with a published, standard interface.

## Parameters

### `BusDataType` [in]

Bus data to set. This value can be PCIConfiguration. The upper bound on the types supported is always MaximumBusDataType.

### `BusNumber` [in]

Zero-based and system-assigned number of the bus in systems with several buses of the same BusDataType. This argument also carries the segment number. To specify the segment number, use (Segment << 8) | BusNumber

### `SlotNumber` [in]

Logical slot number or location of the device. If you specify PCIConfiguration as the BusDataType, this value is specified as a PCI_SLOT_NUMBER value, which is the slot and function numbers combined.

### `Buffer` [in]

Pointer to a caller-supplied buffer for configuration information specific to BusDataType.

If you specify PCIConfiguration, the buffer contains the PCI config space information for the specified SlotNumber and function number. The specified Offset and Length determine how much information to supply. Certain members of PCI config space have read-only values The caller is responsible for preserving the system-supplied values of read-only members. Note that for a Type-1 PCI device, HalSetBusDataByOffset prevents writes to registers inside the common header (first 256 bytes of the config space).

### `Offset` [in]

Byte offset in the PCI_COMMON_CONFIG structure where the caller-supplied configuration values begin. Callers can use the system-defined constant PCI_COMMON_HDR_LENGTH to specify the device-specific area of PCI_COMMON_CONFIG.

### `Length` [in]

Number of bytes in Buffer.

## Return value

The return value is the actual length written to the config space.

## Remarks

A driver can call this function or HalSetBusData if unusual circumstances or the nature of its device requires such a call. For example, a driver might call either of these functions to clear a bit in the PCI status register if its device signals a target abort during initialization. Usually, the hardware or startup code configures the device appropriately.

When accessing the device-specific area of the PCI configuration space, HalSetBusDataByOffset guarantees that this function never reads or writes data outside the range specified by the input Offset and Length and even if the input Length is exactly a byte or a two-byte word, this function never accesses any data outside the requested range.

## See also

[BUS_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bus_data_type)

[HalGetBusData](https://learn.microsoft.com/previous-versions/windows/embedded/ms899356(v=msdn.10))

[HalGetBusDataByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halgetbusdatabyoffset)

[HalSetBusData](https://learn.microsoft.com/previous-versions/windows/embedded/ms899359(v=msdn.10))

[HalTranslateBusAddress](https://learn.microsoft.com/previous-versions/windows/embedded/ms899361(v=msdn.10))

[**PCI_COMMON_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_common_config)