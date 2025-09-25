## Description

Retrieves the expiration event for the font set, if any. The expiration event is set on a system font set object if it is out of date due to fonts being installed, uninstalled, or updated. You should handle the event by getting a new system font set.

## Return value

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

An event handle, if called on the system font set, or `nullptr` if called on a custom font set.

## Remarks

You mustn't call **CloseHandle** on the returned event handle. The handle is owned by the font set object, and it remains valid as long as you hold a reference to the font set. You can wait on the returned event, or use [RegisterWaitForSingleObject](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-registerwaitforsingleobject) to request a callback when the event is set.

## See also