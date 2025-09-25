# RASDIALFUNC1 callback function

## Description

A
**RasDialFunc1** function is called by the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function when a change of state occurs during a remote access connection process. A
**RasDialFunc1** function is comparable to a
[RasDialFunc](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc) function, but is enhanced by the addition of two parameters: a handle to the RAS connection, and an extended error code.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

### `unnamedParam3`

### `unnamedParam4`

### `unnamedParam5`

#### - dwError [in]

Specifies the error that has occurred. If no error has occurred, *dwError* is zero.

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) calls
**RasDialFunc1** with *dwError* set to zero upon entry to each connection state. If an error occurs within a state,
**RasDial** calls
**RasDialFunc1** again with a nonzero *dwError* value.

In some error cases, the *dwExtendedError* parameter contains extended error information.

#### - dwExtendedError [in]

Specifies extended error information for certain nonzero values of *dwError*. For all other values of *dwError, dwExtendedError* is zero.

The contents of *dwExtendedError* are defined for values of *dwError* as follows.

| dwError | Meaning |
| --- | --- |
| **ERROR_SERVER_NOT_RESPONDING** | Specifies the NetBIOS error that occurred. |
| **ERROR_NETBIOS_ERROR** | Specifies the NetBIOS error that occurred. |
| **ERROR_AUTH_INTERNAL** | Specifies an internal diagnostics code. |
| **ERROR_CANNOT_GET_LANA** | Specifies a routing error code, which is a RAS error. |

#### - hrasconn [in]

Handle to the RAS connection, as returned by
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala).

#### - rascs [in]

Specifies the
[RASCONNSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85)) enumerator value that indicates the state the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) remote access connection process is about to enter.

#### - unMsg [in]

Specifies the type of event that has occurred. Currently, the only event defined is WM_RASDIALEVENT.

## Remarks

A
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) connection operation is suspended during a call to a
**RasDialFunc1** callback function. For that reason, the
**RasDialFunc1** implementation generally returns as quickly as possible. There are two exceptions to that rule. Asynchronous (slow) devices such as modems often have time-out periods measured in seconds rather than milliseconds; a slow return from a
**RasDialFunc1** function is generally not a problem. The prompt return requirement also does not apply when *dwError* is nonzero, indicating that an error has occurred. It is safe, for example, to put up an error dialog box and wait for user input.

The
**RasDialFunc1** implementation should not depend on the order or occurrence of particular
[RASCONNSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85)) connection states, because this may vary between platforms.

Do not call the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function from within a
**RasDialFunc1** callback function. Call the
[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa),
[RasEnumEntries](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumentriesa),
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa),
[RasGetErrorString](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeterrorstringa), and
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa) functions from within the callback function. For example, calling
**RasGetConnectStatus** from within a callback function would be useful for determining the name and type of the connecting device.

Note that, for convenience,
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa) can be called from within a
**RasDialFunc1** callback function. However, much of the hang-up processing occurs after the
**RasDialFunc1** callback function has returned.

**RasDialFunc1** is a placeholder for the application-defined or library-defined function name.

## See also

[RASCONNSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85))

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasDialFunc](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc)

[RasDialFunc2](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc2)

[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa)

[RasEnumEntries](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumentriesa)

[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa)

[RasGetErrorString](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeterrorstringa)

[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)