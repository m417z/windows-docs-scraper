# FltCancellableWaitForSingleObject function

## Description

The **FltCancellableWaitForSingleObject** routine executes a cancelable wait operation (a wait that can be terminated) on a dispatcher object.

## Parameters

### `Object` [in]

A pointer to an initialized dispatcher object (event, mutex, semaphore, thread, or timer) for which the caller supplies the storage.

### `Timeout` [in, optional]

A pointer to an optional time-out value. This parameter specifies the absolute or relative time, in 100 nanosecond units, when the wait is to be completed.

If **Timeout** points to a zero value (that is, ***Timeout** == 0), the routine returns without waiting. If the caller supplies a NULL pointer (that is, **Timeout** == NULL), the routine waits indefinitely until the object is set to the signaled state.

A positive **Timeout** value specifies an absolute time, relative to January 1, 1601. A negative **Timeout** value specifies an interval relative to the current time. Absolute expiration times track any changes in the system time. Relative expiration times are not affected by system time changes.

If **Timeout** is specified, the wait is automatically satisfied if the object is not set to the signaled state when the given interval expires.

A time-out value of zero (that is, ***Timeout** == 0) allows you to test a set of wait conditions, and to conditionally perform any additional actions if the wait can be immediately satisfied, as in the acquisition of a mutex.

### `CallbackData` [in, optional]

A pointer to the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure that represents the I/O operation that was issued by the user and that can be canceled by the user. The caller must ensure that the I/O operation will remain valid for the duration of this routine and that the I/O must not have a cancel routine set (for example, a [**FltSetCancelCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcancelcompletion) function must not have been called on the I/O operation). Note that the caller must hold the **CallbackData**; it cannot be passed to a lower-level driver.

## Return value

**FltCancellableWaitForSingleObject** can return one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The dispatcher object that is specified by the **Object** parameter has been set to the signaled state. |
| STATUS_TIMEOUT | A time-out occurred before the object was set to a signaled state. This value can also be returned when the specified wait condition cannot be immediately met and **Timeout** is set to zero. |
| STATUS_ABANDONED_WAIT_0 | The caller attempted to wait for a mutex that has been abandoned. |
| STATUS_CANCELLED | The wait was interrupted by a pending cancel request on the I/O operation. Note that this value is returned only if **CallbackData** corresponds to an IRP based operation is passed to **FltCancellableWaitForSingleObject** and the I/O was canceled by a routine such as [**FltCancelIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio). |
| STATUS_THREAD_IS_TERMINATING | The wait was interrupted because the application or user has terminated the thread. |

The return value only indicates the status of the wait.

Note that the NT_SUCCESS macro returns FALSE ("failure") for the STATUS_CANCELLED and STATUS_THREAD_IS_TERMINATING status values and TRUE ("success") for all other status values.

## Remarks

The **FltCancellableWaitForSingleObject** routine executes a cancelable wait operation on a dispatcher object. If the user or application terminates the thread, or if an I/O associated with the thread was canceled by a routine such as [**FltCancelIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio), the wait is canceled.

The routine is designed to support the [I/O Completion/Cancellation Guidelines](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn613954(v=vs.85)). The goal of these guidelines is to allow users to quickly terminate applications. This, in turn, requires that applications have the ability to quickly terminate threads that are executing I/O and any current I/O operations. This routine provides a way for user threads to block (that is, wait) in the kernel for I/O completion, dispatcher objects, or synchronization variables in a way that allows the wait to be readily canceled. This routine also permits the thread's wait to be terminated if the thread is terminated by a user or an application.

For example, a redirector may need to create a secondary I/O operation in order to process a user-mode I/O and synchronously wait for the secondary request to complete. One way to do this is to set up an event that will be signaled by the completion routine of the secondary I/O operation and then wait for the event to be signaled. Then, to perform a cancelable wait operation, **FltCancellableWaitForSingleObject** is called passing in the event associated with the secondary I/O operation, and the original user-mode I/O operation. The thread's wait for the event to be signaled is canceled if a pending termination event occurs or if the original user-mode I/O operation is canceled.

Note that terminating the wait does not automatically cancel any I/O operation that was issued by the caller - that must be handled separately by the caller.

A special consideration applies when the **Object** parameter passed to **FltCancellableWaitForSingleObject** is a mutex. If the dispatcher object that is waited on is a mutex, APC delivery is the same as for all other dispatcher objects during the wait. However, once **FltCancellableWaitForSingleObject** returns with STATUS_SUCCESS and the thread actually holds the mutex, only special kernel-mode APCs are delivered. Delivery of all other APCs, both kernel-mode and user-mode, is disabled. This restriction on the delivery of APCs persists until the mutex is released.

A mutex can be recursively acquired only MINLONG times. If this limit is exceeded, the routine raises a STATUS_MUTANT_LIMIT_EXCEEDED exception.

**FltCancellableWaitForSingleObject** must be called at IRQL PASSIVE_LEVEL if the **CallbackData** parameter represents a valid filter manager IRP. Otherwise, the routine can be called at IRQL less or equal to APC_LEVEL. Normal kernel APCs can be disabled by the caller, if needed, by calling the [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) or [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) routines. However, special kernel APCs must not be disabled.

The **FltCancellableWaitForSingleObject** routine will assert on debug builds if the **CallbackData** represents a Filter Manager IRP operation, but the IRP in the **CallbackData** structure is NULL.

## See also

[**ExInitializeFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[**FltCancelIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio)

[**FltCancellableWaitForMultipleObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancellablewaitformultipleobjects)

[**FltSetCancelCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcancelcompletion)

[**FltCancellableWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancellablewaitforsingleobject)

[**KeInitializeMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializemutex)

[**KeInitializeSemaphore**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializesemaphore)

[**KeInitializeTimer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimer)

[**KeWaitForMultipleObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[**KeWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)