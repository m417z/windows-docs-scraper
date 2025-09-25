# IPortDMus::Notify

## Description

The `Notify` method should be called from the miniport driver's interrupt service routine (ISR) when a hardware interrupt has occurred. This call requests that the port driver call the miniport driver back with a deferred procedure call (DPC) while the miniport driver handles the interrupt.

## Parameters

### `ServiceGroup` [in, optional]

Pointer to an [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) object. This parameter is optional and can be specified as **NULL**. For more information, see the following Remarks section.

## Remarks

The `Notify` method sends notification to the miniport driver's service group:

* If the *pServiceGroup* parameter is non-**NULL**, the `Notify` method calls the **RequestService** method on the [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) object that this parameter points to.
* If *pServiceGroup* is **NULL**:
  + The `Notify` method calls the **RequestService** method on the miniport driver's **IServiceGroup** object. This is the **IServiceGroup** object that the miniport driver output during the [IMiniportDMus::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iminiportdmus-init) call. The miniport driver also might have registered this object early (that is, earlier than the return from **Init**) by calling [IPortDMus::RegisterServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iportdmus-registerservicegroup).
  + The `Notify` method also calls the **RequestService** method on the **IServiceGroup** object belonging to each of the miniport driver's streams. This is the **IServiceGroup** object that the [IMiniportDMus::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iminiportdmus-newstream) method outputs.

The miniport driver typically calls `Notify` to notify the port driver that the audio device has generated a hardware interrupt. When an interrupt signals, for example, that some register needs to be read, the miniport driver's ISR cannot access the MXF (MIDI transform filter) graph at the elevated IRQL. Instead, the miniport driver can store the input data (a byte of MIDI data, for example) from the register, call `Notify`, and wait for the port driver to get back to it with a DPC.

When the miniport driver's ISR calls `Notify`, the port driver receives the notification at the elevated hardware interrupt IRQL and puts a DPC on the queue. When IRQL drops to the DISPATCH_LEVEL, the port driver's DPC fires and services the miniport driver.

Within the DPC, the port driver calls [IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage) on the miniport driver's input stream with a parameter of **NULL** to signify that the miniport driver can now put the previously stored MIDI message into the MXF graph because the IRQL has dropped back to DISPATCH_LEVEL.

This method is vital for accurate timing. Most miniports will call this method in response to a notification interrupt after having cleared the interrupt source. Although the miniport driver is free to use other methods for determining when to call this method, precise timing is important and should be maintained.

When an adapter driver installs an ISR, it submits a *ServiceContext* parameter along with the ISR's entry point (for details, see [Providing ISR Context Information](https://learn.microsoft.com/windows-hardware/drivers/kernel/providing-isr-context-information)). When the interrupt occurs, the operating system calls the ISR and passes *ServiceContext* as a call parameter to the ISR. Although the meaning of the *ServiceContext* parameter is known only to the driver developer, it is typically a pointer to the miniport object. The ISR uses this pointer to access information about the miniport object.

The *pServiceGroup* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage)

[IMiniportDMus::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iminiportdmus-init)

[IMiniportDMus::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iminiportdmus-newstream)

[IPortDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iportdmus)

[IPortDMus::RegisterServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iportdmus-registerservicegroup)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)