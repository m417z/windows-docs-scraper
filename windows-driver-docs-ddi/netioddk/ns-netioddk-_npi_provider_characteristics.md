# _NPI_PROVIDER_CHARACTERISTICS structure

## Description

The NPI_PROVIDER_CHARACTERISTICS structure defines the characteristics of a provider module.

## Members

### `Version`

The version of the NMR with which the provider is registering. A provider module should set this
member to zero.

### `Length`

The size, in bytes, of the NPI_PROVIDER_CHARACTERISTICS structure.

### `ProviderAttachClient`

A pointer to the provider module's
[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn) callback
function.

### `ProviderDetachClient`

A pointer to the provider module's
[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn) callback
function.

### `ProviderCleanupBindingContext`

A pointer to the provider module's
[ProviderCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_cleanup_binding_context_fn) callback function. If the provider module does not dynamically
allocate the memory for its binding context and no other cleanup of its binding context is required,
then the provider module does not need to implement a
*ProviderCleanupBindingContext* callback function. If the provider module does not implement a
*ProviderCleanupBindingContext* callback function, then this member must be set to **NULL**.

### `ProviderRegistrationInstance`

An
[NPI_REGISTRATION_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_registration_instance) structure that specifies the identity of the provider module and the
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) for which it is
registering.

## Remarks

A provider module passes a pointer to an NPI_PROVIDER_CHARACTERISTICS structure to the
[NmrRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterprovider) function when it
registers itself with the NMR.

A provider module must make sure that this structure remains valid and resident in memory as long as
the provider module is registered with the NMR.

## See also

[NPI_REGISTRATION_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_registration_instance)

[NmrRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterprovider)

[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn)

[ProviderCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_cleanup_binding_context_fn)

[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn)