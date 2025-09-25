# StorPortSetBusDataByOffset function

## Description

The **StorPortSetBusDataByOffset** routine writes bus-specific configuration information.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

### `BusDataType` [in]

Contains a value of type [BUS_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bus_data_type) that specifies the type of the bus for which configuration information is to be written. Currently, its value can be **PCIConfiguration**. However, additional types of standardized, dynamically configurable buses will be supported in future. The upper bound on the bus types supported is always **MaximumBusDataType**.

### `SystemIoBusNumber` [in]

Specifies the system-assigned number of the I/O bus on which the HBA is connected. The miniport driver's [HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine obtains this value from the input **PORT_CONFIGURATION_INFORMATION****SystemIoBusNumber** member.

### `SlotNumber` [in]

Indicates the logical slot number of the HBA.

When **PCIConfiguration** is specified as the *BusDataType*, this parameter must be specified as a PCI_SLOT_NUMBER-type value.

### `Buffer` [in]

Pointer to a caller-supplied storage area with configuration information specific to *BusDataType*.

When **PCIConfiguration** is specified, the buffer contains some or all of the PCI_COMMON_CONFIG information for the given *SlotNumber*. The specified *Offset* and *Length* determine how much information is supplied.

### `Offset` [in]

Specifies the byte offset within the PCI_COMMON_CONFIG structure at which the caller-supplied configuration values begin. A miniport driver can use PCI_COMMON_HDR_LENGTH to specify the offset of the device-specific area in PCI_COMMON_CONFIG.

### `Length` [in]

Indicates the length, in bytes, of the maximum amount of data to return.

## Return value

**StorPortSetBusDataByOffset** returns the number of bytes of configuration data written.

## See also

[ScsiPortSetBusDataByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportsetbusdatabyoffset)