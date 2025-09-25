# IPortDMus::RegisterServiceGroup

## Description

The `RegisterServiceGroup` method registers a service group with the DMus port driver.

## Parameters

### `ServiceGroup` [in]

Pointer to an [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) object. This is the service group that is to be registered.

## Remarks

The miniport driver calls the `RegisterServiceGroup` method to register a service group ([IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) object) with the port driver. The port driver can insert one or more of its service sinks ([IServiceSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicesink) objects) into this service group. The miniport driver sends notification (by calling [IPortDMus::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iportdmus-notify)) to the service group each time an interrupt occurs. Upon receiving notification, the service group schedules a deferred procedure call (DPC). The DPC iterates through all of the service sinks in the service group and sends notification to each.

The miniport driver typically calls **RegisterServiceSink** during the execution of its [IMiniportDMus::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iminiportdmus-init) method. The purpose of this call is to register the service group with the port driver early enough to begin handling interrupts just as soon as they are enabled. Note that the service group that the **Init** method outputs is not available to the port driver until after the return from the **Init** method.

If the miniport driver calls `RegisterServiceSink`, the service group that the miniport driver passes to the `RegisterServiceSink` method should be the same one that the miniport driver outputs through its **Init** method.

A typical miniport driver has no further need to call `RegisterServiceSink` once the return from **IMiniportDMus::Init** has occurred.

See the DMusUART sample audio driver in the Microsoft Windows Driver Kit (WDK) for a code example that shows how the miniport driver calls `RegisterServiceSink` from within its **IMiniportDMus::Init** method.

The *pServiceGroup* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IMiniportDMus::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iminiportdmus-init)

[IPortDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iportdmus)

[IPortDMus::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iportdmus-notify)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[IServiceSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicesink)