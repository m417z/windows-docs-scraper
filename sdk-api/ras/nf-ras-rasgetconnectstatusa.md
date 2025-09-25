# RasGetConnectStatusA function

## Description

The
**RasGetConnectStatus** function retrieves information on the current status of the specified remote access connection. An application can use this call to determine when an asynchronous
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) call is complete.

## Parameters

### `unnamedParam1` [in]

Specifies the remote access connection for which to retrieve the status. This handle must have been obtained from
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa).

### `unnamedParam2` [in, out]

Pointer to the
[RASCONNSTATUS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376728(v=vs.85)) structure that, on output, receives the status information.

On input, set the **dwSize** member of the structure to sizeof([RASCONNSTATUS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376728(v=vs.85))) in order to identify the version of the structure being passed.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | The function could not allocate sufficient memory to complete the operation. |

## Remarks

The return value for
**RasGetConnectStatus** is not necessarily equal to the value of the **dwError** member of the
[RASCONNSTATUS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376728(v=vs.85)) structure returned by
**RasGetConnectStatus**. The return value of
**RasGetConnectStatus** indicates errors that occur during the
**RasGetConnectStatus** function call, whereas the **dwError** member indicates errors that prevented the connection from being established.

> [!NOTE]
> The ras.h header defines RasGetConnectStatus as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASCONNSTATUS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376728(v=vs.85))

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)