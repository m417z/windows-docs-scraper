# _NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS structure

## Description

An NDIS miniport driver defines its interrupt characteristics in an
NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS structure and passes the structure to the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_MINIPORT_INTERRUPT, the
**Revision** member to NDIS_MINIPORT_INTERRUPT_REVISION_1, and the
**Size** member to NDIS_SIZEOF_MINIPORT_INTERRUPT_CHARACTERISTICS_REVISION_1.

### `InterruptHandler`

The entry point for the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function that is
associated with this interrupt.

### `InterruptDpcHandler`

The entry point for the
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function
that is associated with this interrupt.

### `DisableInterruptHandler`

The entry point for the
[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt) function.

### `EnableInterruptHandler`

The entry point for the
[MiniportEnableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_enable_interrupt) function.

### `MsiSupported`

Set this member to **TRUE** if the miniport driver supports message-signaled interrupt (MSI) service
functions. The miniport driver must provide entry points for the MSI service functions.

Setting this value to **FALSE** indicates that MSI is not supported. The MSI service function entry
points should be set to **NULL**.

### `MsiSyncWithAllMessages`

Set this member to **TRUE** if the miniport driver must serialize all MSI service functions.

Setting this value to **TRUE** can degrade interrupt performance. It is more efficient for multiple
interrupt service functions that handle different messages to run concurrently.

### `MessageInterruptHandler`

The entry point for the
[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt) function, if it exists, that is associated with this interrupt. If the
driver does not support message interrupts, set this member to **NULL**.

### `MessageInterruptDpcHandler`

The entry point for the
[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc) function, if any, that is associated with this interrupt. If the
driver does not support message-signaled interrupts, set this member to **NULL**.

### `DisableMessageInterruptHandler`

The entry point for the
[MiniportDisableMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_message_interrupt) function, if any. If the driver does not support message signaled
interrupts, set this member to **NULL**.

### `EnableMessageInterruptHandler`

The entry point for the
[MiniportEnableMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_enable_message_interrupt) function, if any. If the driver does not support message-signaled
interrupts, set this member to **NULL**.

### `InterruptType`

A variable of type **NDIS_INTERRUPT_TYPE**. NDIS sets this variable to indicate which kind of
interrupt it granted to the miniport driver. If the driver supports MSI, it must check this value if
**NdisMRegisterInterruptEx** returns NDIS_STATUS_SUCCESS. If
**InterruptType** is set to **NDIS_CONNECT_LINE_BASED**, then NDIS granted the driver a line-based
interrupt, which can happen even if the driver supports message-signaled interrupts. If
**InterruptType** is set to **NDIS_CONNECT_MESSAGE_BASED**, then NDIS granted the driver a
message-signaled interrupt. In this case, the driver can access
**MessageInfoTable** to obtain the interrupt information.

### `MessageInfoTable`

An NDIS-supplied pointer to an
[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure.

* If
  **InterruptType** is **NDIS_CONNECT_MESSAGE_BASED**, NDIS initializes an [IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info)
  structure with information about the interrupt and sets
  **MessageInfoTable** to a pointer to the structure. Miniport drivers must not modify the
  structure.
* If **InterruptType** is **NDIS_CONNECT_LINE_BASED**, **MessageInfoTable** must be NULL.

## Remarks

A miniport driver calls the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function
to register an interrupt. The driver allocates and initializes an **NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS**
structure to specify the interrupt characteristics and handler entry points and passes the structure to
**NdisMRegisterInterruptEx**.

## See also

[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info)

[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt)

[MiniportDisableMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_message_interrupt)

[MiniportEnableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_enable_interrupt)

[MiniportEnableMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_enable_message_interrupt)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt)

[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)