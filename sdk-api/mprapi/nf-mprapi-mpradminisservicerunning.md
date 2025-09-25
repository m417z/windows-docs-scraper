# MprAdminIsServiceRunning function

## Description

The
**MprAdminIsServiceRunning** function checks whether the RRAS service is running on a specified server if the calling process has access.

## Parameters

### `lpwsServerName` [in]

A pointer to a **null**-terminated Unicode string that specifies the name of the server to query. If this parameter is **NULL**, the function queries the local machine.

## Return value

The return value is one of the following Boolean values.

| Value | Meaning |
| --- | --- |
| **TRUE** | The service is running on the specified server. |
| **FALSE** | The service is not running on the specified server and/or the calling process does not have access to the RRAS service. |

## Remarks

This function returns **FALSE** if the RRAS service is running, but the calling process does not have sufficient privileges to access the service. If the access rights of the calling process on the server are unknown, it is recommended that [MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect) is called prior to calling this function. Doing so will determine if the process has the required access rights to the server.

## See also

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)