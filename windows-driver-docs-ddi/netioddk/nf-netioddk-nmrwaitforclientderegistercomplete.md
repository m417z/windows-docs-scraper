# NmrWaitForClientDeregisterComplete function

## Description

The
**NmrWaitForClientDeregisterComplete** function waits for the deregistration of a client module to
complete.

## Parameters

### `NmrClientHandle` [in]

A handle used by the NMR to represent the registration of the client module. The NMR returns this
handle to the client module when the client module calls the
[NmrRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterclient) function.

## Return value

The
**NmrWaitForClientDeregisterComplete** function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The NMR completed deregistering the client module. |
| **STATUS_INVALID_PARAMETER** | The client module called the **NmrWaitForClientDeregisterComplete** function before calling the [NmrDeregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterclient) function, or the handle specified in the NmrClientHandle parameter is not a valid client handle. |
| **Other status codes** | An error occurred. |

## Remarks

A client module calls the
**NmrWaitForClientDeregisterComplete** function to wait for the deregistration of the client module to
complete. A client module calls the
**NmrWaitForClientDeregisterComplete** function only after calling the
[NmrDeregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterclient) function.

A client module typically calls the
**NmrWaitForClientDeregisterComplete** function from its
[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) function to wait until it is completely
deregistered from the NMR before the client module is unloaded from the system. A client module must not
return from a call to its
**Unload** function until after deregistration is
complete.

**Note** If a client module uses the Windows Driver Framework, it will typically call the
**NmrWaitForClientDeregisterComplete** function from its
[EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload) event callback function. In
this situation, the client module must not return from a call to its
*EvtDriverUnload* function until after
deregistration is complete.

## See also

[NmrDeregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterclient)