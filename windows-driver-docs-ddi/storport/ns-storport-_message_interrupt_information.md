# _MESSAGE_INTERRUPT_INFORMATION structure

## Description

The **MESSAGE_INTERRUPT_INFORMATION** structure describes a message signaled interrupt (MSI).

## Members

### `MessageId`

An identifier identifies the MSI interrupt. A miniport driver can pass this value to [StorPortAcquireMSISpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquiremsispinlock) in the *MessageId* parameter to obtain a spin lock for synchronization purposes.

### `MessageData`

The data associated with the message.

### `MessageAddress`

The physical address associated with the message.

### `InterruptVector`

The interrupt vector associated with the message.

### `InterruptLevel`

The interrupt level associated with the message.

### `InterruptMode`

A value of type [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode) that specifies the interrupt mode associated with the message.

## Remarks

Miniport drivers retrieve the MSI information in a **MESSAGE_INTERRUPT_INFORMATION** structure by calling the [StorPortGetMSIInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetmsiinfo) routine.

## See also

[StorPortGetMSIInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetmsiinfo)