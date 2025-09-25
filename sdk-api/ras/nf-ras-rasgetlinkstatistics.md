# RasGetLinkStatistics function

## Description

The
**RasGetLinkStatistics** function retrieves accumulated statistics for the specified link in a RAS multilink connection.

## Parameters

### `hRasConn` [in]

Handle to the connection. Use
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa) to obtain this handle.

### `dwSubEntry` [in]

Specifies the subentry that corresponds to the link for which to retrieve statistics.

### `lpStatistics` [in, out]

Pointer to the
[RAS_STATS](https://learn.microsoft.com/windows/desktop/api/ras/ns-ras-ras_stats) structure that, on output, receives the statistics.

On input, the **dwSize** member of this structure specifies the size of
[RAS_STATS](https://learn.microsoft.com/windows/desktop/api/ras/ns-ras-ras_stats). Use sizeof(**RAS_STATS**) to obtain this size.

This parameter cannot be **NULL**.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **E_INVALID_ARG** | At least one of the following is true: the *hRasConn* parameter is zero, the *dwSubEntry* parameter is zero, the *lpStatistics* parameter is **NULL**, or the value specified by the **dwSize** member of the [RAS_STATS](https://learn.microsoft.com/windows/desktop/api/ras/ns-ras-ras_stats) structure specifies a version of the structure that is not supported by the operating system in use. |
| **ERROR_NOT_ENOUGH_MEMORY** | The function could not allocate sufficient memory to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[RasClearLinkStatistics](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasclearlinkstatistics)

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa)

[RasGetConnectionStatistics](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectionstatistics)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)