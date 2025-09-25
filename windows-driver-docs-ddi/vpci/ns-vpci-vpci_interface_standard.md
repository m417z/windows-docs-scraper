## Description

The **VPCI\_INTERFACE\_STANDARD** interface structure enables device drivers to access blocks of configuration data that is specific to a PCI Express (PCIe) virtual function (VF) of devices that support the single root I/O virtualization (SR-IOV) interface.

This structure describes the **GUID\_VPCI\_INTERFACE\_STANDARD** interface.

> [!NOTE]
> The location of the VF configuration block and the format of the configuration data are defined by the independent hardware vendor (IHV) of the device. They are used only by the drivers of the PCIe physical function (PF) and the VF.

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

### `WriteVfConfigBlock`

A pointer to a [*WriteVfConfigBlock*](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/nc-vpci-vpci_write_block) routine that writes a block of configuration data for a PCIe VF.

### `ReadVfConfigBlock`

A pointer to a [*ReadVfConfigBlock*](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/nc-vpci-vpci_read_block) routine that reads a block of configuration data for a PCIe VF.

### `SerialNumber`

A UINT32 value that contains the serial number for the PCIe VF on the device. The virtualization stack generates a unique serial number for each VF that is exposed on the device.

## Remarks

The **GUID\_VPCI\_INTERFACE\_STANDARD** interface is provided by the virtual PCI (VPCI) bus driver that creates the physical device objects (PDOs) that are layered below the loaded drivers for the VFs. These drivers are loaded in the guest operating system that runs in a Hyper-V child partition.

A driver obtains a pointer to the **VPCI\_INTERFACE\_STANDARD** structure by sending an [**IRP\_MN\_QUERY\_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) IRP to its bus driver with **InterfaceType** set to GUID\_VPCI\_INTERFACE\_STANDARD.

## See also

[*InterfaceDereference*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)

[*InterfaceReference*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[**IRP\_MN\_QUERY\_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[*ReadVfConfigBlock*](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/nc-vpci-vpci_read_block)

[*WriteVfConfigBlock*](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/nc-vpci-vpci_write_block)