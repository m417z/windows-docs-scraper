# NPI_PROVIDER_DETACH_CLIENT_FN callback function

## Description

A provider module's
*ProviderDetachClient* callback function detaches the provider module from a client module.

## Parameters

### `ProviderBindingContext` [in]

A pointer to the provider module's context for the binding between the provider module and the
client module from which it is detaching. The provider module's
[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn) callback
function returns this pointer to the NMR when it attaches to the client module.

## Return value

A provider module's
*ProviderDetachClient* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The provider module successfully detached from the client module. |
| **STATUS_PENDING** | The provider module could not detach from the client module immediately. |

## Remarks

The NMR calls a provider module's
*ProviderDetachClient* callback function whenever the binding between the provider module and a
client module needs to be terminated. Detachment is initiated by either the client module calling the
[NmrDeregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterclient) function or the
provider module calling the
[NmrDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterprovider) function.

After its
*ProviderDetachClient* callback function has been called, a provider module should not make any more
calls to any of the client module's
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) callback functions. If there
are no in-progress calls to any of the client module's
NPI callback functions when the
provider module's
*ProviderDetachClient* callback function is called, then the provider module's
*ProviderDetachClient* callback function returns STATUS_SUCCESS.

If there are in-progress calls to one or more of the client module's
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) callback functions when the
provider module's
*ProviderDetachClient* callback function is called, the provider module's
*ProviderDetachClient* callback function returns STATUS_PENDING. In this situation, the provider
module must call the
[NmrProviderDetachClientComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrproviderdetachclientcomplete) function after all in-progress calls to the client module's
NPI callback functions have
completed. The call to the
**NmrProviderDetachClientComplete** function notifies the NMR that detachment from the client module is
complete.

The NMR calls the client module's
[ClientCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_cleanup_binding_context_fn) callback function and the provider module's
[ProviderCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_cleanup_binding_context_fn) callback function after both the client module and the provider
module have completed detaching from each other.

The NMR calls a provider module's
*ProviderDetachClient* callback function at any IRQL <= DISPATCH_LEVEL.

## See also

[ClientCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_cleanup_binding_context_fn)

[NPI_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_provider_characteristics)

[NmrDeregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterclient)

[NmrDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterprovider)

[NmrProviderDetachClientComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrproviderdetachclientcomplete)

[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn)

[ProviderCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_cleanup_binding_context_fn)