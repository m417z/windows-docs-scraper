# NdisIfDeregisterProvider function

## Description

The
**NdisIfDeregisterProvider** function deregisters an interface provider that was previously registered by
a call to the
[NdisIfRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterprovider) function.

## Parameters

### `NdisProviderHandle` [in]

A handle that identifies the network interface provider. The caller obtained this handle from a
previous call to the
[NdisIfRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterprovider) function.

## Remarks

NDIS drivers call the
**NdisIfDeregisterProvider** function to deregister as a network interface provider. NDIS drivers
should deregister as interface providers when they are unloaded.

The interface provider must ensure that it does not have any interfaces registered when it calls
**NdisIfDeregisterProvider**. To deregister interfaces, the provider must call the
[NdisIfDeregisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifderegisterinterface) function once for each registered interface.

The provider must not use the provider handle that it passed at the
*NdisProviderHandle* parameter after it calls
**NdisIfDeregisterProvider**.

## See also

[NdisIfDeregisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifderegisterinterface)

[NdisIfRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterprovider)