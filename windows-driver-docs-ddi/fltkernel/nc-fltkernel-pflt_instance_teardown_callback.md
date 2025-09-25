# PFLT_INSTANCE_TEARDOWN_CALLBACK callback

## Description

A minifilter driver can register two routines of type **PFLT_INSTANCE_TEARDOWN_CALLBACK** as the minifilter driver's *InstanceTeardownStartCallback* and *InstanceTeardownCompleteCallback* routines.

## Parameters

### `FltObjects` [in]

Pointer to a [**FLT_RELATED_OBJECTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure that contains opaque pointers for the objects related to the current I/O operation.

### `Reason` [in]

Flag that indicates why the minifilter driver instance is being torn down. One of the following:

| Flag | Meaning |
| ---- | ------- |
| FLTFL_INSTANCE_TEARDOWN_MANUAL (0x00000001) | The instance is being detached because a user-mode application has called [**FilterDetach**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterdetach) or a kernel-mode component has called [**FltDetachVolume**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume). |
| FLTFL_INSTANCE_TEARDOWN_FILTER_UNLOAD (0x00000002) | The minifilter driver is being unloaded. |
| FLTFL_INSTANCE_TEARDOWN_MANDATORY_FILTER_UNLOAD (0x00000004) | The minifilter driver is being unloaded. |
| FLTFL_INSTANCE_TEARDOWN_VOLUME_DISMOUNT (0x00000008) | If set, the volume is being dismounted. (Or the volume has already been dismounted. Or the volume mount operation failed. Or the minifilter driver instance or the volume is being torn down. Or the file system unregistered itself as an active file system.) |
| FLTFL_INSTANCE_TEARDOWN_INTERNAL_ERROR (0x00000010) | The system experienced an unexpected internal error. |

## Remarks

When a minifilter driver registers itself by calling [**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) from its [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/ifs/writing-a-driverentry-routine-for-a-minifilter-driver) routine, it can register two routines of type PFLT_INSTANCE_TEARDOWN_CALLBACK as the minifilter driver's *InstanceTeardownStartCallback* and *InstanceTeardownCompleteCallback* routines. To register these callback routines, the minifilter driver stores the addresses of the two routines of type PFLT_INSTANCE_TEARDOWN_CALLBACK in the **InstanceTeardownStartCallback** and **InstanceTeardownCompleteCallback** members of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter driver passes as the *Registration* parameter of **FltRegisterFilter**.

The *InstanceTeardownStartCallback* and *InstanceTeardownCompleteCallback* routines are optional and can be **NULL**. If the minifilter driver specifies **NULL** for the *InstanceTeardownStartCallback* or *InstanceTeardownCompleteCallback* routine, the instance is still torn down.

The *InstanceTeardownStartCallback* routine is called when the filter manager starts tearing down a minifilter driver instance to allow the minifilter driver to complete any pended I/O operations and save state information.

The *InstanceTeardownStartCallback* routine must:

* Call [**FltCompletePendedPreOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpreoperation) for each I/O operation that was pended in the minifilter driver's preoperation callback routine to complete the operation or return control of the operation to the filter manager.
* Not pend any new I/O operations. If the minifilter driver uses a callback data queue, it must call [**FltCbdqDisable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable) to disable it.
* Call [**FltCompletePendedPostOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpostoperation) for each I/O operation that was pended in the minifilter driver's postoperation callback routine to return control of the operation to the filter manager.

The *InstanceTeardownStartCallback* routine can optionally do the following to allow the minifilter driver to unload as quickly as possible:

* Close any opened files.
* Ensure that worker threads perform only the minimum necessary to complete processing of outstanding work items.
* Call [**FltCancelIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio) to cancel any I/O operations that were initiated by the minifilter driver.
* Stop queuing new work items.

Once the minifilter driver's *InstanceTeardownStartCallback* routine is called, the minifilter driver's preoperation and postoperation callback routines are not called for any new I/O operations. However, they may be called for I/O operations that were started before instance teardown was initiated.

The *InstanceTeardownCompleteCallback* routine is called when the teardown process is complete to allow the minifilter driver to close open files and perform any other necessary cleanup processing.

The *InstanceTeardownCompleteCallback* routine must close any files that were opened by the minifilter driver.

The filter manager calls the minifilter driver's *InstanceTeardownCompleteCallback* routine only after all outstanding I/O operations have been completed or drained.

> [!WARNING]
> The *InstanceTeardownCompleteCallback* routine will not be called if any of the following conditions are true:
>
> * There are outstanding pended I/O operations.
> * There are any outstanding I/O operations that were initiated by the minifilter driver.

If the minifilter driver instance is being torn down because the minifilter driver is being unloaded, the unload operation appears to hang until the *InstanceTeardownCompleteCallback* routine returns. To debug these kinds of problems, you should enable the [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/driver-verifier) on your minifilter driver. The Filter Verifier [I/O Verification](https://learn.microsoft.com/windows-hardware/drivers/devtest/i-o-verification) option can help identify possible causes, such as unreleased references, that would prevent the minifilter driver from unloading. For more information, see [Filter Verifier](https://learn.microsoft.com/windows-hardware/drivers/ifs/development-and-testing-tools).

Note that referencing the instance (by calling [**FltObjectReference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectreference)) does not prevent the *InstanceTeardownCompleteCallback* routine from being called.

The filter manager calls the *InstanceTeardownStartCallback* and *InstanceTeardownCompleteCallback* routines at IRQL PASSIVE_LEVEL.

## See also

[**FLT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[**FLT_RELATED_OBJECTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[**FilterDetach**](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterdetach)

[**FltCancelIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio)

[**FltCbdqDisable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable)

[**FltCompletePendedPostOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpostoperation)

[**FltCompletePendedPreOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpreoperation)

[**FltDetachVolume**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume)

[**FltObjectReference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectreference)

[**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[**PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_query_teardown_callback)

[**PFLT_INSTANCE_SETUP_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)