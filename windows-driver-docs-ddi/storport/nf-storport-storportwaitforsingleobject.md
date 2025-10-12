# StorPortWaitForSingleObject function

## Description

A miniport can call **StorPortWaitForSingleObject** function to put the current thread into a wait state until the given dispatcher object is set to signaled state or optionally times out.

## Parameters

### `HwDeviceExtension`

Pointer to the storage miniport's device extension.

### `Object`

Pointer to the initialized dispatcher object (event, mutex, semaphore, thread, or timer).

### `Alertable`

Boolean value set TRUE if the wait is alertable and FALSE otherwise.

### `Timeout`

Pointer to the timeout value that specifies the absolute or relative time, in 100-nanosecond units, at which the wait is to be completed.

A positive value specifies an absolute time, relative to January 1, 1601. A negative value specifies an interval relative to the current time. Absolute expiration times track any changes in the system time; relative expiration times are not affected by system time changes.

If *Timeout* = 0, the routine returns without waiting. If the miniport supplies a NULL pointer, the routine waits indefinitely until the dispatcher object is set to the signaled state. For more information, see the following Remarks section.

## Return value

**StorPortSetEvent** returns a status code such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_INVALID_PARAMETER | One or more of the parameters are invalid. |
| STOR_STATUS_SUCCESS | The ETW event was successfully logged. |
| STOR_STATUS_UNSUCCESSFUL | The operation failed. |

## Remarks

See [**KeWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) for more details.

Callers of **StorportWaitForSingleObject** must be running at IRQL <= DISPATCH_LEVEL. However, if *Timeout* = NULL or *Timeout* != 0, the caller must be running at IRQL <= APC_LEVEL and in a nonarbitrary thread context. (If *Timeout* != NULL and *Timeout* = 0, the caller must be running at IRQL <= DISPATCH_LEVEL.)

## See also

[**KeWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)

[**StorPortInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeevent)

[**StorportSetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetevent)