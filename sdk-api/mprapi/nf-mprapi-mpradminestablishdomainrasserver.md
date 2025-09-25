# MprAdminEstablishDomainRasServer function

## Description

The
[MprAdminEstablishDomainRasServer](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserversetinfo) function establishes the given machine as a Remote Access Server in the domain. This function must be executed only on a machine joined to a domain.

## Parameters

### `pszDomain` [in]

The domain in which you want the server to be advertised.

### `pszMachine` [in]

The name of the RAS server.

### `bEnable` [in]

A **BOOL** that is **TRUE** if the RAS server should be advertised in the domain. Otherwise, it is **FALSE**.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_DS_SERVER_DOWN** | pszDomain is invalid. |
| **ERROR_NOT_FOUND** | pszMachine is invalid. |
| **ERROR_DS_OPERATIONS_ERROR** | User is a non-domain user. |
| **ERROR_NO_SUCH_DOMAIN** | Function executed on a machine not joined to any domain. |

## See also

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)