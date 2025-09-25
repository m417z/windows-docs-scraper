# VideoPortWaitForSingleObject function

## Description

The **VideoPortWaitForSingleObject** function puts the current thread into a wait state until the given dispatch object is set to the signaled state, or (optionally) until the wait times out.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `Object` [in]

Pointer to the event object.

### `Timeout` [in]

(Optional) Pointer to a time-out value that specifies the absolute or relative time at which the wait is to be completed. A negative value specifies a wait interval relative to the current time. The value should be expressed in units of 100 nanoseconds. Absolute expiration times track any changes in the system time; relative expiration times are not affected by system time changes.

## Return value

**VideoPortWaitForSingleObject** returns one of the following values:

|Return code|Description|
|--- |--- |
|ERROR_INVALID_PARAMETER|One of the parameters is invalid or the call attempted to wait for a mapped user event.|
|NO_ERROR|The event object specified in the pObject parameter satisfied the wait.|
|WAIT_TIMEOUT|A time-out occurred before the event object was set to the signaled state. This value can be returned when the specified set of wait conditions cannot be immediately met and Timeout is set to zero.|

## Remarks

The miniport driver should not attempt to wait for a mapped user event.

Callers of **VideoPortWaitForSingleObject** must be running at IRQL <= DISPATCH_LEVEL. Usually, the caller will be running at IRQL = PASSIVE_LEVEL and in a nonarbitrary thread context. A call to this function while running at IRQL = DISPATCH_LEVEL is valid if and only if the caller specifies a *Timeout* value of zero. That is, a miniport driver must not wait for a nonzero interval at IRQL = DISPATCH_LEVEL.