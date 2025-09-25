# PFLT_COMPLETED_ASYNC_IO_CALLBACK callback

## Description

A minifilter driver that initiates an asynchronous I/O operation can specify a routine of type PFLT_COMPLETED_ASYNC_IO_CALLBACK routine to be called when the operation is completed.

## Parameters

### `CallbackData` [in]

Pointer to the callback data structure for the I/O operation.

### `Context` [in]

Context pointer that the minifilter driver passed as a parameter to [FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio), [FltReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile), or [FltWriteFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltwritefile).

## Remarks

When a minifilter driver calls [FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio), [FltReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile) or [FltWriteFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltwritefile) to initiate an asynchronous I/O operation, the minifilter driver can optionally specify a callback routine to be called when the I/O operation is completed. This is done by specifying a routine of type PFLT_COMPLETED_ASYNC_IO_CALLBACK for the *CallbackRoutine* parameter.

When the I/O operation is completed, this callback routine is called in an arbitrary thread context, at IRQL <= DISPATCH_LEVEL.

Because the PFLT_COMPLETED_ASYNC_IO_CALLBACK routine can be called at IRQL DISPATCH_LEVEL, it is subject to the following constraints:

* It cannot safely call any kernel-mode routines that require a lower IRQL.
* Any data structures used in this routine must be allocated from nonpaged pool.
* It cannot be made pageable.
* It cannot acquire resources, mutexes, or fast mutexes. However, it can acquire spin locks.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio)

[FltReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile)

[FltWriteFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltwritefile)