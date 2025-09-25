# NPI_CLIENT_DETACH_PROVIDER_FN callback function

## Description

A client module's
*ClientDetachProvider* callback function detaches the client module from a provider module.

## Parameters

### `ClientBindingContext` [in]

A pointer to the client module's context for the binding between the client module and the
provider module from which it is detaching. The client module passes this pointer to the NMR when it
calls the
[NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider) function
to attach to the provider module.

## Return value

A client module's
*ClientDetachProvider* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The client module successfully detached from the provider module. |
| **STATUS_PENDING** | The client module could not detach from the provider module immediately. |

## Remarks

The NMR calls a client module's
*ClientDetachProvider* callback function whenever the binding between the client module and a
provider module needs to be terminated. Detachment is initiated by either the client module calling the
[NmrDeregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterclient) function or the
provider module calling the
[NmrDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterprovider) function.

After its
*ClientDetachProvider* callback function has been called, a client module should not make any more
calls to any of the provider module's
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) functions. If there are no
in-progress calls to any of the provider module's
NPI functions when the client
module's
*ClientDetachProvider* callback function is called, the client module's
*ClientDetachProvider* callback function returns STATUS_SUCCESS.

If there are in-progress calls to one or more of the provider module's
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) functions when the client
module's
*ClientDetachProvider* callback function is called, then the client module's
*ClientDetachProvider* callback function returns STATUS_PENDING. In this situation, the client module
must call the
[NmrClientDetachProviderComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientdetachprovidercomplete) function after all in-progress calls to the provider module's
NPI functions have completed. The
call to the
**NmrClientDetachProviderComplete** function notifies the NMR that detachment from the provider module
is complete.

The NMR calls the client module's
[ClientCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_cleanup_binding_context_fn) callback function and the provider module's
[ProviderCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_cleanup_binding_context_fn) callback function after both the client module and the provider
module have completed detachment from each other.

The NMR calls a client module's
*ClientDetachProvider* callback function at any IRQL <= DISPATCH_LEVEL.

## See also

[ClientCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_cleanup_binding_context_fn)

[NPI_CLIENT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_client_characteristics)

[NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider)

[NmrClientDetachProviderComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientdetachprovidercomplete)

[NmrDeregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterclient)

[NmrDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterprovider)

[ProviderCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_cleanup_binding_context_fn)