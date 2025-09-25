## Description

The **PS_AVAILABLE_CPUS_CHANGE_CALLBACK** function is a callback routine that is called when the set of available CPUs changes for a process or the system.

## Parameters

### `Context` [in, optional]

A pointer to driver-defined context information that was specified when the callback was registered with [**PsRegisterProcessAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregisterprocessavailablecpuschangenotification) or [**PsRegisterSystemAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregistersystemavailablecpuschangenotification).

### `SequenceNumber` [in]

The current sequence number for the available CPUs. This value increments whenever the set of available CPUs changes.

## Remarks

This callback function is implemented by the driver and is called by the system when CPU availability changes.

The callback can be invoked at IRQL from PASSIVE_LEVEL to DISPATCH_LEVEL, so the implementation must be able to run at DISPATCH_LEVEL.

### When the Callback is Invoked

The callback is invoked when:

- CPUs are added or removed from the system (hotplug scenarios)
- Process affinity is modified (for process-specific registrations)
- System-wide CPU availability changes (for system registrations)
- CPU cores go online or offline
- Processor groups are modified

### Implementation Guidelines

- The callback should complete quickly since it may be called at DISPATCH_LEVEL
- Avoid blocking operations or lengthy processing
- Use the **SequenceNumber** parameter to detect and handle changes efficiently
- Query the current CPU availability using [**PsQueryProcessAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psqueryprocessavailablecpus) or [**PsQuerySystemAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psquerysystemavailablecpus) if needed

## See also

[**PsRegisterProcessAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregisterprocessavailablecpuschangenotification)

[**PsRegisterSystemAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregistersystemavailablecpuschangenotification)

[**PsUnregisterAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psunregisteravailablecpuschangenotification)

[**PsQueryProcessAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psqueryprocessavailablecpus)

[**PsQuerySystemAvailableCpus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psquerysystemavailablecpus)