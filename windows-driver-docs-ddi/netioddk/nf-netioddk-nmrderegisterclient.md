# NmrDeregisterClient function

## Description

The
**NmrDeregisterClient** function deregisters a client module from the NMR.

## Parameters

### `NmrClientHandle` [in]

A handle used by the NMR to represent the registration of the client module. The NMR returns this
handle to the client module when the client module calls the
[NmrRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterclient) function.

## Return value

The
**NmrDeregisterClient** function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_PENDING** | The NMR initiated the deregistration of the client module. The client module must call the [NmrWaitForClientDeregisterComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrwaitforclientderegistercomplete) function to wait until the deregistration is complete before the client module can be unloaded. |
| **Other status codes** | An error occurred. |

## Remarks

When a client module calls the
**NmrDeregisterClient** function, the NMR calls the client module's
[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn) callback
function and the provider module's
[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn) callback
function for each of the bindings between the client module and a provider module. The deregistration of
the client module from the NMR is complete after the client module has successfully detached from all the
provider modules to which it is attached and all of those provider modules have successfully detached
from the client module.

A client module typically calls the
**NmrDeregisterClient** function from its
[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) function to detach itself from all of the
provider modules to which it is attached before the client module is unloaded from the system. After
calling the
**NmrDeregisterClient** function, a client module must call the
[NmrWaitForClientDeregisterComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrwaitforclientderegistercomplete) function to wait for the deregistration to complete before the
client module can be unloaded. A client module must not return from a call to its
**Unload** function until after deregistration is
complete.

**Note** If a client module uses the Windows Driver Framework, it will typically call the
**NmrDeregisterClient** function from its
[EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload) event callback function. In
this situation, the client module must not return from a call to its
*EvtDriverUnload* function until after
deregistration is complete.

## See also

[ClientDetachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_detach_provider_fn)

[EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload)

[NmrRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterclient)

[NmrWaitForClientDeregisterComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrwaitforclientderegistercomplete)

[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn)

[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload)