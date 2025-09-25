# SCardAccessStartedEvent function

## Description

The **SCardAccessStartedEvent** function returns an event handle when an event signals that the smart card resource manager is started. The event-object handle can be specified in a call to one of the wait functions.

## Return value

The function returns an event HANDLE if it succeeds or **NULL** if it fails.

 If the function fails, the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function provides information on the cause of the failure.

## Remarks

The event-object handle returned can be specified in a call to one of the wait functions.

Do not close the handle returned by this function.
When you have finished using the handle, decrement the reference count by calling the [SCardReleaseStartedEvent](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreleasestartedevent) function.