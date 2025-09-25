# PCI_MSIX_MASKUNMASK_ENTRY callback function

## Description

The *MaskTableEntry* routine masks an interrupt in the MSI-X hardware interrupt table.

## Parameters

### `Context` [in]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [PCI_MSIX_TABLE_CONFIG_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_msix_table_config_interface) structure for the interface.

### `TableEntry` [in]

The index of the table entry in the MSI-X hardware interrupt table.

## Return value

The *MaskTableEntry* routine might return one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_INVALID_PARAMETER** | The *TableEntry* parameter is invalid. |

## Remarks

If a table entry is masked, the device does not generate any interrupts that correspond to that table entry.

You can unmask the table entry by calling [UnmaskTableEntry](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/gg604859(v=vs.85)).

## See also

[PCI_MSIX_TABLE_CONFIG_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_msix_table_config_interface)

[UnmaskTableEntry](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/gg604859(v=vs.85))