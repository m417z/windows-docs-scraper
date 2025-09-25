# MAPILOGOFF callback function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPILogoff** function ends a session with the messaging system.

## Parameters

### `lhSession` [in]

Handle for the Simple MAPI session to be terminated. Session handles are returned by the [MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon) function and invalidated by **MAPILogoff**. The value of the *lhSession* parameter must represent a valid session; it cannot be zero.

### `ulUIParam` [in]

Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type HWND (cast to a ULONG_PTR). If no dialog box is displayed during the call, *ulUIParam* is ignored.

### `flFlags`

Reserved; must be zero.

### `ulReserved`

Reserved; must be zero.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_FAILURE** | The *flFlags* parameter is invalid or one or more unspecified errors occurred. |
| **MAPI_E_INSUFFICIENT_MEMORY** | There was insufficient memory to proceed. The session was not terminated. |
| **MAPI_E_INVALID_SESSION** | An invalid session handle was used for the *lhSession* parameter. The session was not terminated. |
| **SUCCESS_SUCCESS** | The call succeeded and the session was terminated. |

## See also

[MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))