# MprAdminMIBServerConnect function

## Description

The
**MprAdminMIBServerConnect** function establishes a connection to the router being administered. This call should be made before any other calls to the server. The handle returned by this function is used in subsequent MIB calls.

## Parameters

### `lpwsServerName` [in]

Pointer to a Unicode string that specifies the name of the remote server. If the caller specifies **NULL** for this parameter, the function returns a handle to the local server.

### `phMibServer` [out]

Pointer to a handle variable. This variable receives a handle to the server.

## Return value

If the function succeeds, the return value is NO_ERROR.

## See also

[MprAdminMIBServerDisconnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverdisconnect)

[Router Management MIB Functions](https://learn.microsoft.com/windows/desktop/RRAS/mib-functions)

[Router Management MIB Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-mib-reference)