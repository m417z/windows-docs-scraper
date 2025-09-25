# DXGK_TIMED_OPERATION_INTERFACE structure

## Description

The **DXGK_TIMED_OPERATION_INTERFACE** structure contains pointers to functions in the Timed Operation Interface, which is implemented by the display port driver.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The version number of the Timed Operation Interface. Version number constants are defined in *Dispmprt.h* (for example, DXGK_TIMED_OPERATION_INTERFACE_VERSION_1).

### `Context`

A pointer to a context that is provided by the display port driver.

### `InterfaceReference`

A pointer to an interface reference function that is implemented by the display port driver.

### `InterfaceDereference`

A pointer to an interface dereference function that is implemented by the display port driver.

### `TimedOperationStart`

The **TimedOperationStart** function starts or restarts a timed operation.

The driver should preset the **Size** member of the [**DXGK_TIMED_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation) structure that is pointed to by the **Op** parameter to **sizeof**(DXGK_TIMED_OPERATION). Parameter descriptions for **TimedOperationStart** follow.

* [out] **Op** is a pointer to a [**DXGK_TIMED_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation) structure that describes the timed operation to start or restart.

* [in] **Timeout** is a pointer to a time-out value, in 100-nanoseconds units, that specifies the relative time that was allotted for the timed operation to complete.

* [in] **OsHandled** is a Boolean value that specifies whether the operating system handles the time-out condition. A value of TRUE indicates that the driver does not have any reasonable way to handle the time-out condition and lets the operating system handle the time-out condition; FALSE indicates that the driver handles the time-out condition.

### `TimedOperationDelay`

The **TimedOperationDelay** function puts the current thread into an alertable or nonalertable wait state for a given interval with regard to the given timed operation time-out. Parameter descriptions for **TimedOperationDelay** follow.

* [in/out] **Op** is a pointer to a [**DXGK_TIMED_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation) structure that describes the timed operation to delay. This timed operation was started by a call to the **TimedOperationStart** function.

* [in] **WaitMode** is a KPROCESSOR_MODE-typed value that specifies the processor mode the driver waits in. The value can be either **KernelMode** or **UserMode**. Lower-level drivers in a stack should specify **KernelMode**.

* [in] **Alertable** is a Boolean value that specifies whether the wait is alertable. A value of TRUE indicates that the wait is alertable; FALSE indicates that the wait is nonalertable. Lower-level drivers in a stack should specify FALSE.

* [in] **Interval** is a pointer to variable that contains the relative time, in 100-nanoseconds units, for the delay. The sign of the value is ignored.

### `TimedOperationWaitForSingleObject`

The **TimedOperationWaitForSingleObject** function puts the current thread into a wait state until the given dispatcher object is set to a signaled state or optionally until the wait times out or until the time-out of the given timed operation expires. Parameter descriptions for **TimedOperationWaitForSingleObject** follow.

* [in] **Op** is a pointer to a [**DXGK_TIMED_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation) structure that describes the timed operation to put into a wait state. This timed operation was started by a call to the **TimedOperationStart** function.

* **Object** is a pointer to an initialized dispatcher object that the caller supplies the storage for. The dispatcher object can be an event, a mutex, a semaphore, a thread, or a timer.

* **WaitReason** is a KWAIT_REASON-typed value that specifies the reason for the wait. A driver should set this value to **Executive** or, if the driver is doing work on behalf of a user and is running in the context of a user thread, to **UserRequest**.

* **WaitMode** is a KPROCESSOR_MODE-typed value that specifies the processor mode the driver waits in. The value can be either **KernelMode** or **UserMode**. Lowest-level and intermediate drivers should specify **KernelMode**. If the object that is pointed to by the **Object** parameter is a mutex, the caller must specify **KernelMode**.

* **Alertable** is a Boolean value that specifies whether the wait is alertable. A value of TRUE indicates that the wait is alertable; FALSE indicates that the wait is nonalertable.

* **Timeout** is a pointer to variable that contains the relative time, in 100-nanoseconds units, for the wait to be completed. The sign of the value is ignored.

## Remarks

The display miniport driver supplies the **Size** and **Version** members of this structure, and then calls [**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services), which fills in the remaining members of this structure.

## See also

[**DXGK_TIMED_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation)

[**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services)