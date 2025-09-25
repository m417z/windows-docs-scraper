## Description

>[!WARNING]
>**HalGetBusDataByOffset** and [**HalSetBusDataByOffset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halsetbusdatabyoffset) are provided for backward compatibility but should be used only if the methods recommended in [Accessing Device Configuration Space](https://learn.microsoft.com/windows-hardware/drivers/kernel/accessing-device-configuration-space) cannot be used.

This function retrieves information, starting at the offset, about a slot or address on an I/O bus.

## Parameters

### `BusDataType` [in]

Bus data to retrieve. The upper bound on the bus types supported is always MaximumBusDataType. The only supported BusDataType is `PCIConfiguration` All other types are deprecated.

### `BusNumber` [in]

Zero-based and system-assigned number of the bus in systems with several buses of the same BusDataType. This argument also carries the segment number. To specify the segment number, use (Segment << 8) | BusNumber

### `SlotNumber` [in]

Logical slot number or location of the device. If you specify PCIConfiguration as the BusDataType, this value is a PCI_SLOT_NUMBER value, which is the slot and function numbers combined.

### `Buffer` [in]

Pointer to a caller-supplied buffer for configuration information specific to BusDataType.

If you specify PCIConfiguration, the buffer contains the PCI config space information for the specified SlotNumber and function number. The specified Offset and Length determine how much information to supply. Certain members of PCI config space have read-only values The caller is responsible for preserving the system-supplied values of read-only members. Note that for a Type-1 PCI device, HalSetBusDataByOffset prevents writes to registers inside the common header (first 256bytes of the config space).

### `Offset` [in]

Byte offset in the PCI_COMMON_CONFIG structure for which the requested information should be returned. Callers can use the system-defined constant PCI_COMMON_HDR_LENGTH to specify the device-specific area of PCI_COMMON_CONFIG.

### `Length` [in]

Maximum number of bytes in the Buffer.

## Return value

The return value is the actual length read from the config space.

## Remarks

Device drivers call this function during initialization to locate their devices on a particular I/O bus. You can use the returned bus-type-specific configuration data in later calls to other configuration and initialization functions, such as HalTranslateBusAddress.

When accessing the device-specific area of the PCI configuration space, HalGetBusDataByOffset guarantees that this function never reads or writes data outside the range specified by the input Offset and Length. Even if the input Length is exactly a 1-byte or 2-byte word, this function never accesses any data outside the requested range.

## See also

[BUS_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bus_data_type)

[HalGetBusData](https://learn.microsoft.com/previous-versions/windows/embedded/ms899356(v=msdn.10))

[HalSetBusDataByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halsetbusdatabyoffset)

[HalSetBusData](https://learn.microsoft.com/previous-versions/windows/embedded/ms899359(v=msdn.10))

[HalTranslateBusAddress](https://learn.microsoft.com/previous-versions/windows/embedded/ms899361(v=msdn.10))

[**PCI_COMMON_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_common_config)