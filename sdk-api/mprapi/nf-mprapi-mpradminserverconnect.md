# MprAdminServerConnect function

## Description

The
**MprAdminServerConnect** function establishes a connection to a router for the purpose of administering that router. Call this function before making any other calls to the server. Use the handle returned in subsequent calls to administer interfaces on the server.

## Parameters

### `lpwsServerName` [in, optional]

A pointer to a **null**-terminated Unicode string that specifies the name of the remote server. If this parameter is **NULL**, the function returns a handle to the local machine.

### `phMprServer` [out]

A pointer to a **HANDLE** variable that receives a handle to the server. Use this handle in subsequent calls to administer the server.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privilege. |
| **RPC_S_INVALID_BINDING** | This function was called with *phMprServer* parameter equal to **NULL**. |
| **RPC_S_UNKNOWN_IF** | The specified computer is not running the Routing and RAS service. |

## Remarks

**MprAdminIsServiceRunning** must be used to determine the status of the RRAS service on the remote server. **MprAdminServerConnect** does not query the RRAS service when establishing a connection.

## See also

[MprAdminServerDisconnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverdisconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)