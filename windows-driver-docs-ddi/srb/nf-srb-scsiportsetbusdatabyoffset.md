# ScsiPortSetBusDataByOffset function

## Description

The **ScsiPortSetBusDataByOffset** routine sets bus-configuration data for an adapter on a dynamically configurable I/O bus with a published, standard interface.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `BusDataType` [in]

Contains a value of type [BUS_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bus_data_type) that specifies the type of bus data to be set. Currently, its value can be **PCIConfiguration**. However, additional types of standardized, dynamically configurable buses will be supported in future. The upper bound on the bus types supported is always **MaximumBusDataType**.

### `SystemIoBusNumber` [in]

Specifies the system-assigned number of the I/O bus on which the HBA is connected. The miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine obtains this value from the input PORT_CONFIGURATION_INFORMATION **SystemIoBusNumber** member.

### `SlotNumber` [in]

Specifies the logical slot number of the HBA.

When **PCIConfiguration** is specified as the *BusDataType*, this parameter must be specified as a PCI_SLOT_NUMBER-type value.

### `Buffer` [in]

Pointer to a caller-supplied storage area with configuration information specific to *BusDataType*.

When **PCIConfiguration** is specified, the buffer contains some or all of the PCI_COMMON_CONFIG information for the given *SlotNumber*. The specified *Offset* and *Length* determine how much information is supplied.

### `Offset` [in]

Specifies the byte offset within the PCI_COMMON_CONFIG structure at which the caller-supplied configuration values begin. A miniport driver can use PCI_COMMON_HDR_LENGTH to specify the offset of the device-specific area in PCI_COMMON_CONFIG.

### `Length` [in]

Specifies the number of bytes in the storage area at *Buffer*.

## Return value

**ScsiPortSetBusDataByOffset** returns the number of bytes of data successfully set for the given *SlotNumber*. If the given *BusDataType* is not valid for the current platform or if the supplied information is invalid, **ScsiPortSetBusDataByOffset** returns zero.

## Remarks

Miniport drivers of HBAs on a PCI bus seldom call **ScsiPortSetBusDataByOffset** unless unusual circumstances or the nature of a particular driver's HBA requires such a call. For example, a miniport driver might call **ScsiPortSetBusDataByOffset** to clear a bit in the PCI status register if its HBA signals a target abort during initialization or to set device-specific configuration data for the HBA.

**ScsiPortSetBusDataByOffset** can be called only from the miniport driver's *HwScsiFindAdapter* routine or from HwScsiAdapterControl when the control type is **ScsiSetRunningConfig**.

## See also

[HalSetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85))

[PCI_COMMON_CONFIG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537455(v=vs.85))

[PCI_SLOT_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_slot_number)

[PORT_CONFIGURATION_INFORMATION (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_port_configuration_information)

[ScsiPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetbusdata)