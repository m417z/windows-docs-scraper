## Description

The **PCI_VIRTUALIZATION_INTERFACE** structure enables drivers to manage and configure the PCI Express (PCIe) configuration space for a virtual function (VF). VFs are exposed on the PCI bus by devices that support the single root I/O virtualization (SR-IOV) interface.

This structure describes the **GUID_PCI_VIRTUALIZATION_INTERFACE** interface.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The driver-defined interface version.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to an [*InterfaceReference*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) routine that increments the interface's reference count.

### `InterfaceDereference`

A pointer to an [*InterfaceDereference*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine that decrements the interface's reference count.

### `SetVirtualFunctionData`

A pointer to a [*SetVirtualFunctionData*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-set_virtual_device_data) routine that writes data to the PCIe configuration space of an SR-IOV device's VF.

### `GetVirtualFunctionData`

A pointer to a [*GetVirtualFunctionData*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_device_data) routine that reads data from the PCIe configuration space of an SR-IOV device's VF.

### `GetLocation`

A pointer to a [*GetLocation*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_device_location) routine that provides information about the current device location of a VF in the PCIe hierarchy. This information is necessary for a virtualization system that is using an I/O memory management unit (IOMMU) to route traffic to or from the device.

### `GetResources`

A pointer to a [*GetResources*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_device_resources) routine that provides information about the resources that are available for virtualization on an SR-IOV device.

### `EnableVirtualization`

A pointer to an [*EnableVirtualization*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-enable_virtualization) routine that enables or disables virtualization on an SR-IOV device.

### `GetVirtualFunctionProbedBars`

A pointer to a [*GetVirtualFunctionProbedBars*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_function_probed_bars) routine that allows a non-privileged Hyper-V virtual machine (VM) to determine what would be read from the PCIe Base Address Registers (BARs) of a VF after a query by the PCI bus driver. The PCI driver performs this query to determine the memory or I/O address space that the device requires.

## Remarks

For devices that support the SR-IOV interface, drivers occasionally have to access and manage the PCIe configuration space of the device's VFs. Drivers call routines from the GUID_PCI_VIRTUALIZATION_INTERFACE interface to access the PCIe configuration space of the VFs on the device.

Since a device's VFs do not appear as complete PCIe devices on the PCI bus, the [**GUID_BUS_INTERFACE_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard) interface cannot be used for the management of a VF.

The **PCI_VIRTUALIZATION_INTERFACE** structure is an extension of the [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

A driver obtains a pointer to the **PCI_VIRTUALIZATION_INTERFACE** structure by sending an [**IRP_MN_QUERY_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) I/O request packet (IRP) to its bus driver with *InterfaceType* set to GUID_PCI_VIRTUALIZATION_INTERFACE.

## See also

[**GUID_BUS_INTERFACE_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard)

[*InterfaceDereference*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)

[**InterfaceReference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[**IRP_MN_QUERY_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)