# RASDIALFUNC callback function

## Description

The
**RasDialFunc** callback function is called by the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function when a change of state occurs during a RAS connection process.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

### `unnamedParam3`

#### - dwError [in]

Specifies the error that has occurred, or zero if no error has occurred.

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) calls
**RasDialFunc** with *dwError* set to zero upon entry to each connection state. If an error occurs within a state,
**RasDialFunc** is called again with a nonzero *dwError* value.

#### - rasconnstate [in]

Specifies the
[RASCONNSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85)) enumerator value that indicates the state the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) remote access connection process is about to enter.

#### - unMsg [in]

Specifies the type of event that has occurred. Currently, the only event defined is WM_RASDIALEVENT.

## Remarks

A
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) connection operation is suspended during a call to a
**RasDialFunc** callback function. For that reason, the
**RasDialFunc** implementation should generally return as quickly as possible. There are two exceptions to that rule. Asynchronous (slow) devices such as modems often have time-out periods measured in seconds rather than milliseconds; a slow return from a
**RasDialFunc** function is generally not a problem. The prompt return requirement also does not apply when *dwError* is nonzero, indicating that an error has occurred. It is safe, for example, to put up an error dialog box and wait for user input.

The
**RasDialFunc** implementation should not depend on the order or occurrence of particular
[RASCONNSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85)) connection states, because this may vary between platforms.

Do not call the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function from within a
**RasDialFunc** callback function. Call the
[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa),
[RasEnumEntries](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumentriesa),
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa),
[RasGetErrorString](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeterrorstringa), and
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa) functions from within the callback function. For example, calling
**RasGetConnectStatus** from within a callback function would be useful to determine the name and type of the connecting device.

**Note** For convenience,
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa) can be called from within a
**RasDialFunc** callback function. However, much of the hang-up processing occurs after the
**RasDialFunc** callback function has returned.

**Note** **RasDialFunc** is a placeholder for the application-defined or library-defined function name.

## See also

[RASCONNSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85))

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasDialFunc1](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc1)

[RasDialFunc2](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasdialfunc2)

[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa)

[RasEnumEntries](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumentriesa)

[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa)

[RasGetErrorString](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeterrorstringa)

[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)