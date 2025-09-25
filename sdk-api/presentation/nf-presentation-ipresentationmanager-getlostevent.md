## Description

Gets a handle to an event that signals when the presentation manager hits an error it cannot recover from.

## Parameters

### `lostEventHandle`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

A handle to the event.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

The returned event will be signaled when the presentation manager hits an error it cannot recover from. In this case, the application should release this presentation manager and create a new one.

An application can wait on and query this event, but it cannot modify its state. The presentation manager controls this event.

## See also