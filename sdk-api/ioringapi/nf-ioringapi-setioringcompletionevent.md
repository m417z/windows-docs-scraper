## Description

Registers a completion queue event with an I/O ring.

## Parameters

### `ioRing`

An **HIORING** representing a handle to the I/O ring for which the completion event is registered.

### `hEvent`

A handle to the event object. The [CreateEvent](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createeventa) or [OpenEvent](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openeventa) function returns this handle.

## Return value

Returns an HRESULT including the following values:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| E_INVALID_HANDLE | An invalid handle was passed in the *ioRing* parameter. |
| E_INVALIDARG | An invalid handle was passed in the *hEvent* parameter. |

## Remarks

The kernel will signal this event when it places the first entry into an empty completion queue, i.e. the kernel only sets the event to the signaled state when the completion queue transitions from the empty to non-empty state. Applications should call [PopIoRingCompletion](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-popioringcompletion) until it indicates no more entries and then wait for any additional async completions to complete via the provided HANDLE. Otherwise, the event won’t enter the signaled state and the wait may block until a timeout occurs, or forever if an infinite timeout is used.

The kernel will internally duplicate the handle, so it is safe for the application to close the handle when waits are no longer needed. Providing an event handle value of NULL simply clears any existing value. Setting a value of INVALID_HANDLE_VALUE raises an error, as will any other invalid handle value, to aid in detecting code bugs early.

There is, at most, one event handle associated with an HIORING, attempting to set a second one will replace any that already exists.

## See also

[PopIoRingCompletion](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-popioringcompletion)