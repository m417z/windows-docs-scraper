# GET_SET_DEVICE_DATA callback function

## Description

The *GetBusData* routine reads data from the device's configuration space.

## Parameters

### `Context` [in]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [BUS_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard) structure for the interface.

### `DataType` [in]

The type of bus data to read. For more information, see the discussion of the *WhichSpace* parameter in [IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config).

### `Buffer` [in]

A pointer to the buffer that holds the configuration information to be read from the device's configuration space.

### `Offset` [in]

The offset into the bus-specific device data where this read operation begins. For example, if the *DataType* parameter is **PCI_WHICHSPACE_CONFIG**, the *Offset* parameter value is the offset into PCI Configuration Space.

### `Length` [in]

The length, in bytes, of data to read.

## Return value

The *GetBusData* routine returns the length, in bytes, of the configuration data that is read after a successful read operation. If the read operation is unsuccessful, a value of zero is returned.

## Remarks

Depending on the value of the *DataType* parameter, the *GetBusData* routine can be called only from the interrupt request levels (IRQLs) that are defined in the following table.

| *DataType* value | IRQL |
| --- | --- |
| **PCI_WHICHSPACE_CONFIG** | <= DIRQL |
| **PCI_WHICHSPACE_ROM** | <= APC_LEVEL |
| **PCCARD_COMMON_MEMORY**<br><br>**PCCARD_COMMON_MEMORY_INDIRECT** | <= DISPATCH_LEVEL |
| **PCCARD_ATTRIBUTE_MEMORY**<br><br>**PCCARD_ATTRIBUTE_MEMORY_INDIRECT** | <= DISPATCH_LEVEL |
| **PCCARD_PCI_CONFIGURATION_SPACE** | <= DIRQL |

The following remarks apply to drivers for PCI Express (PCIe) virtual functions (VFs) on devices that support the single root I/O virtualization (SR-IOV) interface:

* Drivers for PCIe VFs should call the *GetBusData* routine at IRQL <= APC_LEVEL.
* In order to read PCI Configuration data for the VF at IRQL = DISPATCH_LEVEL, the driver must issue I/O requests of [IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config).

## See also

[BUS_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard)

[IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config)