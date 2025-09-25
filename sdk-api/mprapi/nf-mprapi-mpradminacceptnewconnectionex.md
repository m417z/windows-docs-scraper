# MprAdminAcceptNewConnectionEx function

## Description

Remote Access Service (RAS) calls the
**MprAdminAcceptNewConnectionEx** function each time a new user dials in and successfully completes a RAS authentication. **MprAdminAcceptNewConnectionEx** determines whether the user is allowed to connect.

## Parameters

### `pRasConn` [in]

A pointer to a
[RAS_CONNECTION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_ex) structure that describes this connection.

## Return value

This callback function does not return a value.

## See also

[MprAdminAcceptNewConnection](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnection)

[MprAdminAcceptNewConnection2](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnection2)

[MprAdminAcceptNewConnection3](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnection3)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)