# IPortWavePci::Notify

## Description

The `Notify` method notifies the port driver that an interrupt indicating the progress of the DMA pointer has occurred.

## Parameters

### `ServiceGroup` [in]

A pointer to the miniport driver's [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) object.

## Remarks

Some miniport drivers call this method from an ISR in response to a hardware interrupt after having cleared the interrupt source. Other drivers call this method from a timer DPC that is scheduled to run at regular intervals. As a general rule, only drivers that manage a single render stream from KMixer should rely on hardware interrupts. Drivers that support DirectSound hardware acceleration should turn off hardware interrupts and use timer DPCs instead. For more information, see [IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping).

Although the miniport driver is free to choose its own technique for determining when to call this method, this method should be called frequently enough to allow the port driver to fire pending position and clock events at regular intervals. Timing for this method is not as critical as it is for the [IPortWaveCyclic::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavecyclic-notify) method, however.

When an adapter driver installs an ISR, it submits a *ServiceContext* parameter along with the ISR's entry point (for details, see [Providing ISR Context Information](https://learn.microsoft.com/windows-hardware/drivers/kernel/providing-isr-context-information)). When the interrupt occurs, the operating system calls the ISR and passes *ServiceContext* as a call parameter to the ISR. Although the meaning of the *ServiceContext* parameter is known only to the driver developer, it is typically a pointer to the miniport object. The ISR uses this pointer to access information about the miniport object.

The *ServiceGroup* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IPortWaveCyclic::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavecyclic-notify)

[IPortWavePci](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavepci)

[IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)