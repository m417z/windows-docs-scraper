# NmrClientDetachProviderComplete function

## Description

The
**NmrClientDetachProviderComplete** function notifies the NMR that a client module has completed
detaching from a provider module.

## Parameters

### `NmrBindingHandle` [in]

A handle used by the NMR to represent the binding between the client module and the provider
module. The NMR passes this handle to the client module when it calls the client module's
[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn) callback
function.

## Remarks

A client module calls the
**NmrClientDetachProviderComplete** function when it asynchronously completes detaching from a provider
module after returning STATUS_PENDING from its
[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn) callback
function.

A client module should not call the
**NmrClientDetachProviderComplete** function if it returns STATUS_SUCCESS from its
[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn) callback
function.

## See also

[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn)

[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn)