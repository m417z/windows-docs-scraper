## Description

The **PsRegisterSystemAvailableCpusChangeNotification** function registers a callback to be called when the CPUs that are available to the system process undergo a change.

## Parameters

### `Callback` [in]

Pointer to the callback function to be called. This parameter is of type [**PS_AVAILABLE_CPUS_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ps_available_cpus_change_callback).

### `Context` [in, optional]

Supplies a context parameter that will be passed to the callback function.

### `ObservedSequenceNumber` [in, optional]

Optional pointer to the most recent available CPUs sequence number observed by the caller. If the sequence number has advanced since that observation, a callback will be made immediately.

### `RegistrationHandle` [out]

Pointer to a buffer that upon success receives a handle to the callback registration (PS_AVAILABLE_CPUS_CHANGE_REGISTRATION).

## Return value

**PsRegisterSystemAvailableCpusChangeNotification** returns one of the following NTSTATUS values:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The callback was registered successfully. |
| **STATUS_INSUFFICIENT_RESOURCES** | The callback could not be registered due to insufficient system resources. |

## Remarks

This routine must be called at PASSIVE_LEVEL.

The callback will be invoked whenever the set of available CPUs for the system process changes. This can occur due to CPU hotplug operations or other system events that affect overall CPU availability.

To unregister the callback, call [**PsUnregisterAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psunregisteravailablecpuschangenotification) with the registration handle returned by this function.

If an **ObservedSequenceNumber** is provided and the current sequence number has advanced beyond it, the callback will be invoked immediately upon registration.

This function monitors system-wide CPU availability changes, as opposed to process-specific changes monitored by [**PsRegisterProcessAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregisterprocessavailablecpuschangenotification).

## See also

[**PsUnregisterAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psunregisteravailablecpuschangenotification)

[**PsRegisterProcessAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregisterprocessavailablecpuschangenotification)

[**PS_AVAILABLE_CPUS_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ps_available_cpus_change_callback)