## Description

The **GetVirtualFunctionData** routine reads data from the PCI Express (PCIe) configuration space of a virtual function (VF) on a device that supports the single root I/O virtualization (SR-IOV) interface.

## Parameters

### `Context` [in, out]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [**PCI_VIRTUALIZATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pci_virtualization_interface) structure for the interface.

### `VirtualFunction` [in]

A zero-based value that specifies the VF on the device from which data is to be read.

### `Buffer` [out]

A pointer to the buffer that contains the configuration information read from the PCIe configuration space of the VF.

### `Offset` [in]

The offset into the PCIe configuration space data of the VF. This member specifies where this read operation begins.

### `Length` [in]

The length, in bytes, of the data to be read.

## Return value

The **GetVirtualFunctionData** routine returns the length, in bytes, of the PCIe configuration data that was read after a successful read operation. If the read operation is unsuccessful, the routine returns zero.

## Remarks

The **GetVirtualFunctionData** routine resembles the [GetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data) routine, except that it reads PCIe configuration data from a VF instead of from a device's physical function (PF).

The **GetVirtualFunctionData** routine is provided by the **GUID_PCI_VIRTUALIZATION_INTERFACE** interface. The [GetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data) routine is provided by the **GUID_BUS_INTERFACE_STANDARD** interface.

The virtualization stack calls **GetVirtualFunctionData** when a driver that is running in the guest operating system calls the [GetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data) routine.

## See also

[**PCI_VIRTUALIZATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pci_virtualization_interface)

[GetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data)