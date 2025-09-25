# RegisterGPNotification function

## Description

The
**RegisterGPNotification** function enables an application to receive notification when there is a change in policy. When a policy change occurs, the specified event object is set to the signaled state.

## Parameters

### `hEvent` [in]

Handle to an event object. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to create the event object.

### `bMachine` [in]

Specifies the policy change type. If **TRUE**, computer policy changes are reported. If **FALSE**, user policy changes are reported.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call the
[UnregisterGPNotification](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-unregistergpnotification) function to unregister the handle from receiving policy change notifications. Call the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle when it is no longer required.

An application can also receive notifications about policy changes when a
[WM_SETTINGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-settingchange) message is broadcast. In this instance, the *wParam* parameter value is 1 if computer policy was applied; it is zero if user policy was applied. The *lParam* parameter points to the string "Policy".

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[UnregisterGPNotification](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-unregistergpnotification)