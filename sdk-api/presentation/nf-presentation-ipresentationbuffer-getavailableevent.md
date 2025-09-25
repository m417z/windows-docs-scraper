## Description

Gets a handle to an event that signals when the buffer is available.

## Parameters

### `availableEventHandle`

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to the event.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

The caller is responsible for closing the returned event.

An application can wait on and query this event, but it cannot modify its state. The presentation manager controls this event.

## See also