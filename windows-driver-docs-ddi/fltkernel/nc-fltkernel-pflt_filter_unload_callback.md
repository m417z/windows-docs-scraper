# PFLT_FILTER_UNLOAD_CALLBACK callback function

## Description

A minifilter driver can register a routine of type PFLT_FILTER_UNLOAD_CALLBACK as the minifilter driver's *FilterUnloadCallback* routine.

## Parameters

### `Flags`

Bitmask of flags describing the unload request. This parameter can be **NULL** or the following:

| Flag | Meaning |
| ----- | ------ |
| FLTFL_FILTER_UNLOAD_MANDATORY | The filter manager sets this flag to indicate that the unload operation is mandatory. |

## Return value

This callback routine returns STATUS_SUCCESS or an NTSTATUS value such as the following:

| Return Code | Description |
| ----------- | ----------- |
| STATUS_FLT_DO_NOT_DETACH | If the unload operation is not mandatory, returning this status value prevents the minifilter driver from being unloaded. This is an error code. |

## Remarks

When a minifilter driver registers itself by calling [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter), it can register a *FilterUnloadCallback* routine. To register this callback routine, the minifilter driver stores the address of a routine of type PFLT_FILTER_UNLOAD_CALLBACK in the **FilterUnloadCallback** field of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter driver passes as a parameter to **FltRegisterFilter**.

Minifilter drivers are not required to register a *FilterUnloadCallback* routine. However, registering an unload routine is strongly recommended. If a minifilter driver does not register a *FilterUnloadCallback* routine, it cannot be unloaded.

When a minifilter driver does register a *FilterUnloadCallback* routine:

* The filter manager calls the *FilterUnloadCallback* routine to notify the minifilter driver that the filter manager is about to unload the minifilter driver.

* If the unload operation is not mandatory, and the *FilterUnloadCallback* routine returns an error or warning NTSTATUS code, such as STATUS_FLT_DO_NOT_DETACH, the minifilter driver is not unloaded. Otherwise, the minifilter driver is unloaded.

* If the FLTFL_FILTER_UNLOAD_MANDATORY flag is set in the *Flags* parameter, the unload operation is mandatory, and the minifilter driver cannot prevent itself from being unloaded.

See [When the FilterUnloadCallback Routine Is Called](https://learn.microsoft.com/windows-hardware/drivers/ifs/when-the-filterunloadcallback-routine-is-called) for more information about possible unload causes and the minifilter driver unload process.

## See also

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)