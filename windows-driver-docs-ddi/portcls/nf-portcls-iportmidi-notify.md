# IPortMidi::Notify

## Description

The `Notify` method notifies the port driver that an interrupt indicating the progress of the DMA pointer has occurred. It should be called from the miniport driver's interrupt service routine (ISR).

## Parameters

### `ServiceGroup` [in, optional]

Pointer to the miniport driver's [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) object.

## Remarks

This method is vital for accurate timing. Most miniports will call this method in response to a notification interrupt after having cleared the interrupt source. Although the miniport driver is free to use other methods for determining when to call this method, precise timing is important and should be maintained.

When an adapter driver installs an ISR, it submits a *ServiceContext* parameter along with the ISR's entry point (for details, see [Providing ISR Context Information](https://learn.microsoft.com/windows-hardware/drivers/kernel/providing-isr-context-information)). When the interrupt occurs, the operating system calls the ISR and passes *ServiceContext* as a call parameter to the ISR. Although the meaning of the *ServiceContext* parameter is known only to the driver developer, it is typically a pointer to the miniport object. The ISR uses this pointer to access information about the miniport object.

The *ServiceGroup* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IPortMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportmidi)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)