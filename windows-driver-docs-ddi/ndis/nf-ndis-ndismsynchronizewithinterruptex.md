# NdisMSynchronizeWithInterruptEx function

## Description

Miniport drivers call the
**NdisMSynchronizeWithInterruptEx** function to synchronize the execution of a miniport driver-supplied
function with the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function.

## Parameters

### `NdisInterruptHandle` [in]

An interrupt handle that the miniport driver obtained in a previous call to the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function.

### `MessageId` [in]

A message-signaled interrupt with which the driver must synchronize. If NDIS did not grant message
signaled interrupts for the driver, NDIS ignores this parameter.
*MessageId* is an index to the
[IO_INTERRUPT_MESSAGE_INFO_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info_entry) structures inside a
[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure. NDIS passes a pointer to the associated
IO_INTERRUPT_MESSAGE_INFO structure at the
**MessageInfoTable** member when the driver successfully registers for MSI with the
**NdisMRegisterInterruptEx** function.

### `SynchronizeFunction` [in]

The entry point of the driver's
[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt) function.

### `SynchronizeContext` [in]

A pointer to a miniport-driver-determined context area that is passed to the
*MiniportSynchronizeInterrupt* function at
*SynchronizeContext* .

## Return value

**NdisMSynchronizeWithInterruptEx** returns the Boolean value that
*MiniportSynchronizeInterrupt* returns.

## Remarks

Miniport drivers that register an interrupt with
**NdisMRegisterInterruptEx** use
**NdisMSynchronizeWithInterruptEx**. The value that the
[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt) function returns is also returned by
**NdisMSynchronizeWithInterruptEx**. This propagated value provides status to the caller.

Any miniport driver function that shares resources with any other driver function that runs at DIRQL
must use
**NdisMSynchronizeWithInterruptEx** to synchronize its access to those resources. The
*MiniportSynchronizeInterrupt* function also runs at DIRQL, and the shared resources are protected by
a system-allocated spin lock. Thus, the shared resources are protected from simultaneous access by the
*MiniportInterrupt* function and the caller.

**NdisMSynchronizeWithInterruptEx** releases the system spin lock and restores the original IRQL of its
caller before it returns control.

For more information about acquiring and releasing NDIS spin locks, see
[Synchronization
and Notification in Network Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/synchronization-and-notification-in-network-drivers).

## See also

[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info)

[IO_INTERRUPT_MESSAGE_INFO_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info_entry)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)