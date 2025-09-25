# NPI_CLIENT_CLEANUP_BINDING_CONTEXT_FN callback function

## Description

A client module's
*ClientCleanupBindingContext* callback function performs any necessary cleanup and deallocation of the
client module's binding context after the client module and a provider module have detached from one
another.

## Parameters

### `ClientBindingContext` [in]

A pointer to the client module's context for the binding between the client module and the
provider module from which it has detached. The client module passes this pointer to the NMR when it
calls the
[NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider) function
to attach to the provider module.

## Remarks

The NMR calls a client module's
*ClientCleanupBindingContext* callback function after the client module and a provider module have
detached from one another.

A client module's
*ClientCleanupBindingContext* callback function should perform any necessary cleanup of the data
contained within the client module's binding context structure. It should then free the memory for the
binding context structure if the client module dynamically allocated the memory for the structure.

If the client module does not dynamically allocate the memory for its binding context and no other
cleanup of its binding context is required, then the client module does not need to implement a
*ClientCleanupBindingContext* callback function. If the client module does not implement a
*ClientCleanupBindingContext* callback function, then it must set the
*ClientCleanupBindingContext* member of the
[NPI_CLIENT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_client_characteristics) structure to **NULL** when it calls the
[NmrRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterclient) function to register
itself with the NMR.

The NMR calls a client module's
*ClientCleanupBindingContext* callback function at any IRQL <= DISPATCH_LEVEL.

## See also

[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn)

[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn)

[NPI_CLIENT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_client_characteristics)

[NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider)

[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn)