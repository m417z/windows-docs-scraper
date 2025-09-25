# PCI_MSIX_SET_ENTRY callback function

## Description

The *SetTableEntry* routine sets the message ID for a table entry in the MSI-X hardware interrupt table.

## Parameters

### `Context` [in]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [PCI_MSIX_TABLE_CONFIG_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_msix_table_config_interface) structure for the interface.

### `TableEntry` [in]

The index of the table entry in the MSI-X hardware interrupt table.

### `MessageNumber` [in]

The message ID for the interrupt. This value is also the index for the interrupt's entry in the **MessageInfo** member of the [IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure that describes the driver's message-signaled interrupts. The [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) function supplies a pointer to this structure.

## Return value

The *SetTableEntry* routine might return one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_INVALID_PARAMETER** | The device does not use MSI-X, or the *TableEntry* or *MessageNumber* parameters do not correspond to interrupt resources that are assigned to the device. |

## Remarks

By default, the operating system assigns the index of the table entry as the message ID for the interrupt. If there are more table entries than messages, the system sets the remaining table entries to correspond to message zero. The driver can use the *SetTableEntry* routine to assign a different message ID.

## See also

[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info)

[IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex)

[PCI_MSIX_TABLE_CONFIG_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_msix_table_config_interface)