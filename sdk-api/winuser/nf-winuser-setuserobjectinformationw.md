# SetUserObjectInformationW function

## Description

Sets information about the specified window station or desktop object.

## Parameters

### `hObj` [in]

A handle to the window station, desktop object or a current process pseudo handle. This handle can be returned by the [CreateWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowstationa),
[OpenWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openwindowstationa),
[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa), [OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa) or [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) function.

### `nIndex` [in]

The object information to be set. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **UOI_FLAGS**<br><br>1 | Sets the object's handle flags. The *pvInfo* parameter must point to a [USEROBJECTFLAGS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-userobjectflags) structure. |
| **UOI_TIMERPROC_EXCEPTION_SUPPRESSION**<br><br>7 | Sets the exception handling behavior when calling [TimerProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-timerproc). *hObj* must be the process handle returned by the [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) function.<br><br>The *pvInfo* parameter must point to a BOOL. If TRUE, Windows will enclose its calls to [TimerProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-timerproc) with an exception handler that consumes and discards all exceptions. This has been the default behavior since Windows 2000, although that may change in future versions of Windows. <br><br>If *pvInfo* points to FALSE, Windows will not enclose its calls to [TimerProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-timerproc) with an exception handler. A setting of FALSE is recommended. Otherwise, the application could behave unpredictably, and could be more vulnerable to security exploits. |

### `pvInfo` [in]

A pointer to a buffer containing the object information, or a BOOL.

### `nLength` [in]

The size of the information contained in the buffer pointed to by *pvInfo*, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa)

[CreateWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowstationa)

[GetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectinformationa)

[OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa)

[OpenWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openwindowstationa)

[USEROBJECTFLAGS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-userobjectflags)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)

[Window Stations](https://learn.microsoft.com/windows/desktop/winstation/window-stations)

## Remarks

> [!NOTE]
> The winuser.h header defines SetUserObjectInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).