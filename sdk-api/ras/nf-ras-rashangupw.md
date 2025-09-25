# RasHangUpW function

## Description

The
**RasHangUp** function terminates a remote access connection. The connection is specified with a RAS connection handle. The function releases all RASAPI32.DLL resources associated with the handle.

## Parameters

### `unnamedParam1` [in]

Specifies the remote access connection to terminate. This is a handle returned from a previous call to
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle specified in *hrasconn* is invalid. |

## Remarks

The connection is terminated even if the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) call has not yet been completed.

After this call, the *hrasconn* handle can no longer be used.

An application should not call
**RasHangUp** and then immediately exit. The connection state machine needs time to properly terminate. If the system prematurely terminates the state machine, the state machine can fail to properly close a port, leaving the port in an inconsistent state. Also, an immediate attempt to use the same connection may fail leaving the connection unusable. A simple way to avoid these problems is to call
[Sleep](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleep)(3000) after returning from
**RasHangUp**; after that pause, the application can exit. A more responsive way to avoid these problems is, after returning from
**RasHangUp**, to call
[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa)(*hrasconn*) and **Sleep**(0) in a loop until
**RasGetConnectStatus** returns **ERROR_INVALID_HANDLE**.

You can call
**RasHangUp** on the handle returned by
[RasGetSubEntryHandle](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetsubentryhandlea) to terminate a single link in a multi-link connection. However, in this case, you cannot use
[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa) to determine if the link terminated;
**RasGetConnectStatus** may not return **ERROR_INVALID_HANDLE** even though the link terminated successfully.

> [!NOTE]
> The ras.h header defines RasHangUp as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASCONN](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376725(v=vs.85))

[RasCustomHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomhangupfn)

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa)

[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)

[Sleep](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleep)