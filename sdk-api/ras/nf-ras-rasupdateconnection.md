# RasUpdateConnection function

## Description

The
**RasUpdateConnection** function updates the tunnel endpoints of an Internet Key Exchange version 2 (IKEv2) connection.

## Parameters

### `hrasconn` [in]

A handle to the IKEv2 RAS connection for which the tunnel endpoints are to be changed. This can be a handle returned by the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa) function.

### `lprasupdateconn` [in]

A pointer to a [RASUPDATECONN](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd408110(v=vs.85)) structure that contains the new tunnel endpoints for the RAS connection specified by *hrasconn*.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the error codes from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

## Remarks

Note that 32-bit applications that call **RasUpdateConnection** will fail when run on a 64-bit machine. The workaround is to write a 64-bit version of the application for 64-bit machines.

## See also

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)