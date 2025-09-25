# IMiniportWavePci::Service

## Description

The `Service` method notifies the miniport driver of a request for service.

## Remarks

When the port driver calls the miniport driver's [IMiniportWavePci::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-init) method, that method outputs a reference to the miniport driver's [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) object. The port driver adds its own [IServiceSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicesink) object to this service group and awaits notification of a service request. The source of the notification is typically the miniport driver's interrupt service routine (ISR).

When the miniport driver's ISR calls the port driver's [IPortWavePci::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepci-notify) routine, the port driver queues a deferred procedure call (DPC). When the DPC executes, it calls the **RequestService** method on each of the **IServiceSink** objects in the service group. When the DPC calls this method on the port driver's **IServiceSink** object, the port driver in turn calls the miniport driver's `Service` method.

## See also

[IMiniportWavePci](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepci)

[IMiniportWavePci::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-init)

[IPortWavePci::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepci-notify)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[IServiceSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicesink)