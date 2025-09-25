# IMiniportWavePciStream::Service

## Description

The `Service` method notifies the miniport driver of a request for service.

## Remarks

When the port driver calls the miniport driver's [IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream) method, that method outputs a reference to the new stream's [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) object. The port stream adds its own [IServiceSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicesink) object to the service group and awaits notification of a service request. The source of the notification is typically the miniport driver's interrupt service routine (ISR).

When the miniport driver's ISR calls the port driver's [IPortWavePci::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepci-notify) routine, the port driver queues a deferred procedure call (DPC). When the DPC executes, it calls the **RequestService** method on each of the **IServiceSink** objects in the service group. When the DPC calls this method on the port stream's **IServiceSink** object, the port driver in turn calls the miniport stream object's `Service` method.

## See also

[IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream)

[IMiniportWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepcistream)

[IPortWavePci::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepci-notify)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[IServiceSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicesink)