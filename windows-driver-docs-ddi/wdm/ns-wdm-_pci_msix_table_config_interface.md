# _PCI_MSIX_TABLE_CONFIG_INTERFACE structure

## Description

The **PCI_MSIX_TABLE_CONFIG_INTERFACE** structure enables device drivers to modify their MSI-X interrupt settings. This structure describes the [GUID_MSIX_TABLE_CONFIG_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_msix_table_config_interface) interface.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The driver-defined interface version.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to an [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) routine that increments the interface's reference count.

### `InterfaceDereference`

A pointer to an [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine that decrements the interface's reference count.

### `SetTableEntry`

A pointer to the interface's [SetTableEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pci_msix_set_entry) routine.

### `MaskTableEntry`

A pointer to the interface's [MaskTableEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pci_msix_maskunmask_entry) routine.

### `UnmaskTableEntry`

A pointer to the interface's [UnmaskTableEntry](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/gg604859(v=vs.85)) routine.

### `GetTableEntry`

Reserved for future use.

### `GetTableSize`

Reserved for future use.

## Remarks

A driver obtains a pointer to the **PCI_MSIX_TABLE_CONFIG_INTERFACE** structure by sending an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) IRP to its bus driver with **InterfaceType** set to [GUID_MSIX_TABLE_CONFIG_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_msix_table_config_interface).

## See also

[GUID_MSIX_TABLE_CONFIG_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_msix_table_config_interface)

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)

[InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference)

[MaskTableEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pci_msix_maskunmask_entry)

[SetTableEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pci_msix_set_entry)

[UnmaskTableEntry](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/gg604859(v=vs.85))