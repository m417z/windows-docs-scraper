# RasInvokeEapUI function

## Description

The
**RasInvokeEapUI** function displays a custom user interface to obtain Extensible Authentication Protocol (EAP) information from the user.

## Parameters

### `unnamedParam1` [in]

Handle to the connection returned by
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala).

### `unnamedParam2` [in]

Specifies the subentry returned in the callback.

### `unnamedParam3` [in]

Pointer to the
[RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85)) structure. This structure should be the same as that passed to
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) when restarting from a paused state. Ensure that the **dwSize** member of the
**RASDIALEXTENSIONS** structure specifies the size of the structure. Obtain the size using sizeof(**RASDIALEXTENSIONS**). This parameter cannot be **NULL**.

### `unnamedParam4` [in]

Handle to the parent window to use when displaying the EAP user interface.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The *hRasConn* parameter is zero, or the *lpExtensions* parameter is **NULL**. |
| **ERROR_INVALID_SIZE** | The value of the **dwSize** member of the [RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85)) structure specifies a version of the structure that isn't supported by the operating system in use. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85))

[RASEAPINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377242(v=vs.85))

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)