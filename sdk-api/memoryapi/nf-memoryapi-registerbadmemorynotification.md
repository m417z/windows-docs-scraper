# RegisterBadMemoryNotification function

## Description

Registers a bad memory notification that is called when one or more bad memory pages are detected and the system
cannot remove at least one of them (for example if the pages contains modified data that has not yet been written
to the pagefile.)

## Parameters

### `Callback` [in]

A pointer to the application-defined
[BadMemoryCallbackRoutine](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh691011(v=vs.85)) function to
register.

## Return value

Registration handle that represents the callback notification. Can be passed to the
[UnregisterBadMemoryNotification](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unregisterbadmemorynotification)
function when no longer needed.

## Remarks

To compile an application that calls this function, define **_WIN32_WINNT** as
**_WIN32_WINNT_WIN8** or higher. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).