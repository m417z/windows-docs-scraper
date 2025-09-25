# PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK callback function

## Description

A minifilter driver can register a routine of type *PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK* as the minifilter driver's *InstanceQueryTeardownCallback* routine.

## Parameters

### `FltObjects` [in]

Pointer to an [FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure that contains opaque pointers for the objects related to the current operation.

### `Flags` [in]

Bitmask of flags that describe why the given instance query teardown callback routine was called. No flags are currently defined.

## Return value

This callback routine returns **STATUS_SUCCESS** or an **NTSTATUS** value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DO_NOT_DETACH** | Returning this status value prevents the minifilter driver instance from being detached. This is an error code. |

## Remarks

When a minifilter driver registers itself by calling [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine, it can register a routine of type *PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK* as the minifilter driver's *InstanceQueryTeardownCallback* routine.

To register the *InstanceQueryTeardownCallback* routine, the minifilter driver stores the address of a routine of type *PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK* in the *InstanceQueryTeardownCallback* member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter driver passes as the *Registration* parameter of [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

The filter manager calls this routine to allow the minifilter driver to respond to a manual detach request. Such a request is received when a user-mode application calls [FilterDetach](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterdetach) or a kernel-mode component calls [FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume).

This routine is not called for automatic or mandatory detach requests, for example, when the minifilter driver is unloaded or a volume is dismounted.

If this routine returns an error or warning **NTSTATUS** code, such as **STATUS_FLT_DO_NOT_DETACH**, the minifilter driver instance is not detached from the volume. Otherwise, the instance is detached.

If a minifilter driver does not define an *InstanceQueryTeardownCallback* routine, its instances cannot be detached manually by calling [FilterDetach](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterdetach) or [FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume).

## See also

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[FilterDetach](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterdetach)

[FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_INSTANCE_SETUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)

[PFLT_INSTANCE_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback)