# NPI_CLIENT_ATTACH_PROVIDER_FN callback function

## Description

A client module's
*ClientAttachProvider* callback function attaches the client module to a provider module.

## Parameters

### `NmrBindingHandle` [in]

A handle used by the NMR to represent the binding between the client module and the provider
module.

### `ClientContext` [in]

A pointer to the client module's registration context. The client module passes this pointer to
the NMR when it calls the
[NmrRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterclient) function to register
itself with the NMR.

### `ProviderRegistrationInstance` [in]

A pointer to an
[NPI_REGISTRATION_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_registration_instance) structure. This structure contains the provider module's registration
data.

## Return value

A client module's
*ClientAttachProvider* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The client module and the provider module successfully attached to each other. |
| **STATUS_NOINTERFACE** | Either the client module did not attach to the provider module or the provider module did not attach to the client module. |
| **Other status codes** | An error occurred. |

## Remarks

After a client module has registered with the NMR, the NMR calls the client module's
*ClientAttachProvider* callback function, once for each provider module that is registered as a
provider of the same
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) for which the client module
has registered as a client.

The NMR also calls a client module's
*ClientAttachProvider* callback function whenever a new network module registers as a provider of the
same
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) for which the client module
has registered as a client.

A client module can examine the provider module's registration data. This data is in the structure
pointed to by the
*ProviderRegistrationInstance* parameter. The client module uses this data to determine whether it
will attach to the provider module:

* If the client module determines that it will attach to the provider module, then the
  *ClientAttachProvider* callback function calls the
  [NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider) function
  to continue the attachment process. In this situation the
  *ClientAttachProvider* callback function must return the status code that is returned by the call
  to the
  **NmrClientAttachProvider** function.
* If the client module determines that it will not attach to the provider module, then the
  *ClientAttachProvider* callback function must return STATUS_NOINTERFACE.

If the client module successfully attaches to the provider module, it must save the handle provided in
the
*NmrBindingHandle* parameter. The client module passes this handle as a parameter to the
[NmrClientDetachProviderComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientdetachprovidercomplete) function when it detaches from the provider module.

The NMR calls a client module's
*ClientAttachProvider* callback function at IRQL = PASSIVE_LEVEL.

## See also

[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn)

[NPI_CLIENT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_client_characteristics)

[NPI_REGISTRATION_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_registration_instance)

[NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider)

[NmrClientDetachProviderComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientdetachprovidercomplete)

[NmrRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterclient)