# KeReleaseSemaphore function

## Description

The **KeReleaseSemaphore** routine releases the specified semaphore object.

## Parameters

### `Semaphore` [in, out]

A pointer to an initialized semaphore object for which the caller provides the storage.

### `Increment` [in]

Specifies the priority increment to be applied if releasing the semaphore causes a wait to be satisfied.

### `Adjustment` [in]

Specifies a value to be added to the current semaphore count. This value must be positive.

### `Wait` [in]

Specifies whether the call to **KeReleaseSemaphore** is to be followed immediately by a call to one of the **KeWait*Xxx*** routines. If **TRUE**, the **KeReleaseSemaphore** call must be followed by a call to [KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects), **KeWaitForMutexObject**, or [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject). For more information, see the following Remarks section.

## Return value

If the return value is zero, the previous state of the semaphore object is not-signaled.

## Remarks

**KeReleaseSemaphore** supplies a run-time priority boost for waiting threads. If this call sets the semaphore to the signaled state, the semaphore count is augmented by the specified value. The caller can also specify whether it will call one of the **KeWait*Xxx*** routines as soon as **KeReleaseSemaphore** returns control.

Releasing a semaphore object causes the semaphore count to be augmented by the value of the *Adjustment* parameter. If the resulting value is greater than the limit of the semaphore object, the count is not adjusted and an exception, STATUS_SEMAPHORE_LIMIT_EXCEEDED, is raised.

Augmenting the semaphore object count causes the semaphore to attain a signaled state, and an attempt is made to satisfy as many waits as possible on the semaphore object.

The **KeReleaseSemaphore** routine might temporarily raise the IRQL. If the *Wait* parameter is **FALSE**, the routine, before it returns, restores the IRQL to the original value that it had at the start of the call.

If *Wait* = **TRUE**, the routine returns without lowering the IRQL. In this case, the **KeReleaseSemaphore** call must be immediately followed by a **KeWait*Xxx*** call. By setting *Wait* = **TRUE**, the caller can prevent an unnecessary context switch from occurring between the **KeReleaseSemaphore** call and the **KeWait*Xxx*** call. The **KeWait*Xxx*** routine, before it returns, restores the IRQL to its original value at the start of the **KeReleaseSemaphore** call. Although the IRQL disables context switches between the two calls, these calls cannot reliably be used as the start and end of an atomic operation. For example, between these two calls, a thread that is running at the same time on another processor might change the state of the semaphore object or of the target of the wait.

> [!WARNING]
> A pageable thread or pageable driver routine that runs at IRQL = PASSIVE_LEVEL should never call **KeReleaseSemaphore** with the *Wait* parameter set to **TRUE**. Such a call causes a fatal page fault if the calling function happens to be paged out between the calls to **KeReleaseSemaphore** and **KeWait*Xxx***.

For more information about semaphore objects, see [Semaphore Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/semaphore-objects).

Callers of **KeReleaseSemaphore** must be running at IRQL <= DISPATCH_LEVEL provided that *Wait* is set to **FALSE**. Otherwise, the caller must be running at IRQL = PASSIVE_LEVEL.

## See also

[KeInitializeSemaphore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializesemaphore)

[KeReadStateSemaphore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstatesemaphore)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)