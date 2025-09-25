# NdisDeregisterProtocolDriver function

## Description

A protocol driver calls the
**NdisDeregisterProtocolDriver** function to release the resources that NDIS allocated when the driver
called the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function.

## Parameters

### `NdisProtocolHandle` [in]

The handle returned by the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function.

## Remarks

Registered protocol drivers typically call
**NdisDeregisterProtocolDriver** when the driver's
[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routine has been called or after errors occur
in the
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. Protocol drivers must not
call
**NdisDeregisterProtocolDriver** from any entry point that NDIS calls. Calling
**NdisDeregisterProtocolDriver** from such an entry point could cause a deadlock.

If a protocol driver has open bindings, its call to
**NdisDeregisterProtocolDriver** causes NDIS to call the protocol driver's
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function once for each open binding. NDIS calls
*ProtocolUnbindAdapterEx* within the context of the
**NdisDeregisterProtocolDriver** call.

After any outstanding bindings have been closed,
**NdisDeregisterProtocolDriver** releases all of the resources that NDIS allocated to track bindings
and filters for the protocol driver.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)

[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload)