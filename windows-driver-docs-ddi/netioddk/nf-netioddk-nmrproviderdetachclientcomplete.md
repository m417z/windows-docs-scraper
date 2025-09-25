# NmrProviderDetachClientComplete function

## Description

The
**NmrProviderDetachClientComplete** function notifies the NMR that a provider module has completed
detaching from a client module.

## Parameters

### `NmrBindingHandle` [in]

A handle used by the NMR to represent the binding between the client module and the provider
module. The NMR passes this handle to the provider module when it calls the provider module's
[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn) callback
function.

## Remarks

A provider module calls the
**NmrProviderDetachClientComplete** function when it asynchronously completes detaching from a client
module after returning STATUS_PENDING from its
[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn) callback
function.

A provider module should not call the
**NmrProviderDetachClientComplete** function if it returns STATUS_SUCCESS from its
[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn) callback
function.

## See also

[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn)

[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn)