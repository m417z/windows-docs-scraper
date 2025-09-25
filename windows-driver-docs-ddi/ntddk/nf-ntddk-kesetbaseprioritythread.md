## Description

The **KeSetBasePriorityThread** routine sets the run-time priority, relative to the current process, for a given thread.

## Parameters

### `Thread` [in, out]

Pointer to a dispatcher object of type KTHREAD.

### `Increment` [in]

Specifies the value to be added to the base priority of the process for the **Thread**. This value can be positive or negative.

The effective range depends on the process's priority class:

- For variable priority class processes: The resulting priority must stay within 1 to (`LOW_REALTIME_PRIORITY` - 1)
- For real-time priority class processes: The resulting priority must stay within `LOW_REALTIME_PRIORITY` to `HIGH_PRIORITY`

If the absolute value of **Increment** is greater than or equal to `(HIGH_PRIORITY + 1) / 2`, priority saturation occurs, meaning subsequent changes to the parent process base priority will not affect this thread's base priority.

## Return value

**KeSetBasePriorityThread** returns the previous base priority increment of the given thread. The previous base priority increment is defined as the difference between the specified thread's old base priority and the base priority of the thread's process.

Special return values:

- This function returns 0 when an attempt is made to change the priority of an idle thread (threads in the initial kernel process). The function does not allow idle thread priorities to be changed.

- For saturated threads, this function returns `((HIGH_PRIORITY + 1) / 2) * saturation_value` rather than the simple priority difference, where saturation_value is +1 or -1 depending on whether the thread was saturated at high or low priority.

## Remarks

The new base priority is computed by adding the given **Increment**, which can be a negative value, to the base priority of the specified thread's process. The resultant value is stored as the base priority of the specified thread.

Drivers that set up device-dedicated threads with variable priority attributes can call this routine to set such a thread's priority relative to the system process in which the thread is created.

The new base priority is restricted to the priority class of the given thread's process. Therefore, the base priority is not allowed to cross over from a variable priority class to a real-time priority class or vice versa.

**KeSetBasePriorityThread** is a relatively expensive operation that should be used sparingly. Avoid frequent calls to this function, as repeated priority changes (such as once per minute) can significantly impact system performance and prevent the scheduler from operating efficiently. Use this function only when persistent priority changes are required, not for temporary adjustments or periodic updates.

## See also

[**KeGetCurrentThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentthread)

[**KeQueryPriorityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryprioritythread)

[**KeSetPriorityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetprioritythread)