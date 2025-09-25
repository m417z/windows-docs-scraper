# NPI_PROVIDER_CLEANUP_BINDING_CONTEXT_FN callback function

## Description

A provider module's
*ProviderCleanupBindingContext* callback function performs any necessary cleanup and deallocation of
the provider module's binding context after the provider module and a client module have detached from one
another.

## Parameters

### `ProviderBindingContext` [in]

A pointer to the provider module's context for the binding between the provider module and the
client module from which it has detached. The provider module's
[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn) callback
function returns this pointer to the NMR when it attaches to the client module.

## Remarks

The NMR calls a provider module's
*ProviderCleanupBindingContext* callback function after the provider and a client module have
detached from one another.

A provider module's
*ProviderCleanupBindingContext* callback function should perform any necessary cleanup of the data
contained within the provider module's binding context structure. It should then free the memory for the
binding context structure if the provider module dynamically allocated the memory for the structure.

If the provider module does not dynamically allocate the memory for its binding context and no other
cleanup of its binding context is required, then the provider module does not need to implement a
*ProviderCleanupBindingContext* callback function. If the provider module does not implement a
*ProviderCleanupBindingContext* callback function, then it must set the
*ProviderCleanupBindingContext* member of the
[NPI_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_provider_characteristics) structure to **NULL** when it calls the
[NmrRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterprovider) function to
register itself with the NMR.

The NMR calls a provider module's
*ProviderCleanupBindingContext* callback function at any IRQL <= DISPATCH_LEVEL.

## See also

[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn)

[NPI_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_provider_characteristics)

[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn)

[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn)