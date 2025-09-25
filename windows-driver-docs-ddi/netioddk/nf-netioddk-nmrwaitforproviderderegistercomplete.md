# NmrWaitForProviderDeregisterComplete function

## Description

The
**NmrWaitForProviderDeregisterComplete** function waits for the deregistration of a provider module to
complete.

## Parameters

### `NmrProviderHandle` [in]

A handle used by the NMR to represent the registration of the provider module. The NMR returns
this handle to the provider module when the provider module calls the
[NmrRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterprovider) function.

## Return value

The
**NmrWaitForProviderDeregisterComplete** function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The NMR completed deregistering the provider module. |
| **STATUS_INVALID_PARAMETER** | The provider module called the **NmrWaitForProviderDeregisterComplete** function before calling the [NmrDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterprovider) function, or the handle specified in the NmrClientHandle parameter is not a valid provider handle. |
| **Other status codes** | An error occurred. |

## Remarks

A provider module calls the
**NmrWaitForProviderDeregisterComplete** function to wait for the deregistration of the provider module
to complete. A provider module calls the
**NmrWaitForProviderDeregisterComplete** function only after calling the
[NmrDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterprovider) function.

A provider module typically calls the
**NmrWaitForProviderDeregisterComplete** function from its
[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) function to wait until it is completely
deregistered from the NMR before the provider module is unloaded from the system. A provider module must
not return from a call to its
*Unload* function until after deregistration is
complete.

**Note** If a provider module uses the Windows Driver Framework, it will typically call the
**NmrWaitForProviderDeregisterComplete** function from its
[EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload) event callback function. In
this situation, the provider module must not return from a call to its
*EvtDriverUnload* function until after
deregistration is complete.

## See also

[NmrDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterprovider)