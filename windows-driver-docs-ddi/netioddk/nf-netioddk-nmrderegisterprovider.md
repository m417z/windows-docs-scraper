# NmrDeregisterProvider function

## Description

The
**NmrDeregisterProvider** function deregisters a provider module from the NMR.

## Parameters

### `NmrProviderHandle` [in]

A handle used by the NMR to represent the registration of the provider module. The NMR returns
this handle to the provider module when the provider module calls the
[NmrRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterprovider) function.

## Return value

The
**NmrDeregisterProvider** function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_PENDING** | The NMR initiated the deregistration of the provider module. The provider module must call the [NmrWaitForProviderDeregisterComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrwaitforproviderderegistercomplete) function to wait until the deregistration is complete before the provider module can be unloaded. |
| **Other status codes** | An error occurred. |

## Remarks

When a provider module calls the
**NmrDeregisterProvider** function, the NMR calls the provider module's
[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn) callback
function and the client module's
[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn) callback
function for each of the bindings between the provider module and a client module. The deregistration of
the provider module from the NMR is complete after the provider module has successfully detached from all
the client modules to which it is attached and all of those client modules have successfully detached
from the provider module.

A provider module typically calls the
**NmrDeregisterProvider** function from its
[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) function to detach itself from all of the
client modules to which it is attached before the provider module is unloaded from the system. After
calling the
**NmrDeregisterProvider** function a provider module must call the
[NmrWaitForProviderDeregisterComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrwaitforproviderderegistercomplete) function to wait for the deregistration to complete before the
provider module can be unloaded. A provider module must not return from a call to its
*Unload* function until after deregistration is
complete.

**Note** If a provider module uses the Windows Driver Framework, it will typically call the
**NmrDeregisterProvider** function from its
[EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload) event callback function. In
this situation, the provider module must not return from a call to its
*EvtDriverUnload* function until after
deregistration is complete.

## See also

[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn)

[EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload)

[NmrRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterprovider)

[NmrWaitForProviderDeregisterComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrwaitforproviderderegistercomplete)

[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn)

[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload)