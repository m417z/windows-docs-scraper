# KeDelayExecutionThread function

## Description

The **KeDelayExecutionThread** routine puts the current thread into an alertable or nonalertable wait state for a specified interval.

## Parameters

### `WaitMode` [in]

Specifies the processor mode in which the caller is waiting, which can be either **KernelMode** or **UserMode**. Lower-level drivers should specify **KernelMode**.

### `Alertable` [in]

Specifies **TRUE** if the wait is alertable. Lower-level drivers should specify **FALSE**.

### `Interval` [in]

Specifies the absolute or relative time, in units of 100 nanoseconds, for which the wait is to occur. A negative value indicates relative time. Absolute expiration times track any changes in system time; relative expiration times are not affected by system time changes.

## Return value

**KeDelayExecutionThread** returns one of the following values that describes how the delay was completed:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The delay completed because the specified interval elapsed. |
| **STATUS_ALERTED** | The delay completed because the thread was alerted. |
| **STATUS_USER_APC** | A user-mode APC was delivered before the specified *Interval* expired. |

Note that the NT_SUCCESS macro recognizes all of these status values as "success" values.

## Remarks

The expiration time is computed and the current thread is put in a wait state. When the specified interval has passed, the thread exits the wait state and is put in the ready state, becoming eligible for execution.

The *Alertable* parameter determines when the thread can be alerted and its wait state consequently aborted. For additional information, see [Waits and APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/waits-and-apcs).

If the *WaitMode* parameter is **UserMode**, the kernel stack can be swapped out during the wait. Consequently, a caller must never attempt to pass parameters on the stack when calling **KeDelayExecutionThread** using the **UserMode** argument.

It is especially important to check the return value of **KeDelayExecutionThread** when the *WaitMode* parameter is **UserMode** or *Alertable* is **TRUE**, because **KeDelayExecutionThread** might return early with a status of STATUS_USER_APC or STATUS_ALERTED.

All long term waits that can be aborted by a user should be **UserMode** waits and *Alertable* should be set to **FALSE**.

Where possible, *Alertable* should be set to **FALSE** and *WaitMode* should be set to **KernelMode**, in order to reduce driver complexity. The principal exception to this guideline is when the wait is a long-term wait.

The expiration time of the delay is expressed as either an absolute time at which the delay is to expire, or a time relative to the current system time. If the *Interval* parameter value is positive, the expiration time is an absolute time. If this value is negative, the expiration time is a relative time.

Expiration times are measured relative to the system clock, and the accuracy with which the operating system can detect when a timer expires is limited by the granularity of the system clock. For more information, see [Timer Accuracy](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-accuracy).

## See also

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime)