# _NPI_CLIENT_CHARACTERISTICS structure

## Description

The NPI_CLIENT_CHARACTERISTICS structure defines the characteristics of a client module.

## Members

### `Version`

The version of the NMR with which the client is registering. A client module should set this
member to zero.

### `Length`

The size, in bytes, of the NPI_CLIENT_CHARACTERISTICS structure.

### `ClientAttachProvider`

A pointer to the client module's
[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn) callback
function.

### `ClientDetachProvider`

A pointer to the client module's
[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn) callback
function.

### `ClientCleanupBindingContext`

A pointer to the client module's
[ClientCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_cleanup_binding_context_fn) callback function. If the client module does not dynamically allocate
the memory for its binding context and no other cleanup of its binding context is required, then the
client module does not need to implement a
*ClientCleanupBindingContext* callback function. If the client module does not implement a
*ClientCleanupBindingContext* callback function, then this member must be set to **NULL**.

### `ClientRegistrationInstance`

An
[NPI_REGISTRATION_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_registration_instance) structure that specifies the identity of the client module and the
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) for which it is
registering.

## Remarks

A client module passes a pointer to an NPI_CLIENT_CHARACTERISTICS structure to the
[NmrRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterclient) function when it
registers itself with the NMR.

A client module must make sure that this structure remains valid and resident in memory as long as the
client module is registered with the NMR.

## See also

[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn)

[ClientCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_cleanup_binding_context_fn)

[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn)

[NPI_REGISTRATION_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_registration_instance)

[NmrRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterclient)