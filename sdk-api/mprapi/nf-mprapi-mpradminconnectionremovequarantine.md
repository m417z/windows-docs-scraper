# MprAdminConnectionRemoveQuarantine function

## Description

The
**MprAdminConnectionRemoveQuarantine** function removes quarantine filters on a dialed-in RAS client if the filters were applied as a result of Internet Authentication Service (IAS) policies.

## Parameters

### `hRasServer` [in]

Handle to the RAS server that services the connection. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hRasConnection` [in]

Handle to connection for the RAS client for which to remove the quarantine filters. Obtain this handle by calling
[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum).

Alternatively, this parameter specifies the IP address of the RAS client for which to remove the quarantine filter. The IP address should be specified as a **DWORD** in network byte order. Obtain the IP address by calling
[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum). If this parameter specifies an IP address, the *fIsIpAddress* parameter should specify a **TRUE** value.

### `fIsIpAddress` [in]

Specifies a Boolean value that indicates whether the *hRasConnection* parameter specifies the IP address of the client for which to remove the quarantine filters. If this parameter is a **TRUE** value, *hRasConnection* specifies an IP address. Otherwise, *hRasConnection* specifies a handle to a connection.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The handle to the RAS server or the handle to the RAS connection is invalid. |
| **ERROR_NOT_FOUND** | The RAS client is not in quarantine. |
| **Other** | An error from MprError.h, RasError.h, or WinError.h. |

## Remarks

If [Internet Authentication Service (IAS)](https://learn.microsoft.com/previous-versions/ms688288(v=vs.85)) policies configure regular filters, then these filters are added to the RAS client interface as a result of calling
**MprAdminConnectionRemoveQuarantine**.

## See also

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)