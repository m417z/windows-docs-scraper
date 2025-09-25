# FltUnregisterFilter function

## Description

A registered minifilter driver calls **FltUnregisterFilter** to unregister itself so that the Filter Manager no longer calls it to process I/O operations.

## Parameters

### `Filter` [in]

Opaque filter pointer returned by [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

## Return value

None

## Remarks

**FltUnregisterFilter** unregisters the minifilter driver's callback routines and removes any contexts that the minifilter driver has set on files, volumes, instances, streams, or stream handles. It also calls the minifilter driver's *InstanceTeardownStartCallback* and *InstanceTeardownCompleteCallback* ([PFLT_INSTANCE_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback)) routines for each minifilter driver instance.

A minifilter driver typically calls **FltUnregisterFilter** from its unload routine when it is about to be unloaded.

A minifilter driver can only call **FltUnregisterFilter** to unregister itself, not another minifilter driver.

To register a minifilter driver, call [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

## See also

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_FILTER_UNLOAD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_filter_unload_callback)

[PFLT_INSTANCE_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback)