## Description

The **SetVirtualFunctionData** routine writes data to the PCI Express (PCIe) configuration space of a virtual function (VF) on a device that supports the single root I/O virtualization (SR-IOV) interface.

## Parameters

### `Context` [in, out]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [**PCI_VIRTUALIZATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pci_virtualization_interface) structure for the interface.

### `VirtualFunction` [in]

A zero-based value that specifies the VF on the device from which data is to be written.

### `Buffer` [in]

A pointer to the buffer that contains the configuration information to be written to the PCIe configuration space of the VF.

### `Offset` [in]

The offset into the PCIe configuration space data of the VF. This member specifies where this write operation begins.

### `Length` [in]

The length, in bytes, of the data to be written.

## Return value

The ***SetVirtualFunctionData** routine returns the length, in bytes, of the PCIe configuration data that was written after a successful write operation. If the write operation is unsuccessful, the routine returns zero.

## Remarks

The ***SetVirtualFunctionData** routine is similar to the [SetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data) routine, except that it writes PCIe configuration data to a VF instead of to a device's physical function (PF).

The ***SetVirtualFunctionData** routine is provided by the **GUID_PCI_VIRTUALIZATION_INTERFACE** interface. The [SetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data) routine is provided by the **GUID_BUS_INTERFACE_STANDARD** interface.

The virtualization stack calls ***SetVirtualFunctionData** when a driver that is running in the guest operating system calls the [SetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data) routine.

## See also

[SetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data)

[**PCI_VIRTUALIZATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pci_virtualization_interface)