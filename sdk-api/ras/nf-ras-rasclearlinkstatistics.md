# RasClearLinkStatistics function

## Description

The
**RasClearLinkStatistics** functions clears any accumulated statistics for the specified link in a RAS multilink connection.

## Parameters

### `hRasConn` [in]

Handle to the connection. Use
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa) to obtain this handle.

### `dwSubEntry` [in]

Specifies the subentry that corresponds to the link for which to clear statistics.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The *hRasConn* parameter does not specify a valid connection. |
| **ERROR_INVALID_PARAMETER** | The *dwSubEntry* parameter is zero. |
| **ERROR_NO_CONNECTION** | RAS could not find a connected port that corresponds to the value in the *dwSubEntry* parameter. |
| **ERROR_NOT_ENOUGH_MEMORY** | The function could not allocate sufficient memory to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[RasClearConnectionStatistics](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasclearconnectionstatistics)

[RasGetLinkStatistics](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetlinkstatistics)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)