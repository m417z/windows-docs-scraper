# MprAdminIsDomainRasServer function

## Description

The
[MprAdminIsDomainRasServer](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserversetinfo) function returns information regarding whether the given machine is registered as the remote access server in the domain.

## Parameters

### `pszDomain` [in]

The domain in which you want to query the remote access server.

### `pszMachine` [in]

The name of the remote access server.

### `pbIsRasServer` [out]

Returns **TRUE** if the machine is registered in the domain, otherwise it returns **FALSE**.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_DS_SERVER_DOWN** | pszDomain is invalid. |
| **ERROR_NOT_FOUND** | pszMachine is invalid. |
| **ERROR_DS_OPERATIONS_ERROR** | User is a non-domain user. |
| **ERROR_NO_SUCH_DOMAIN** | Function executed on a machine not joined to any domain. |

## Remarks

This function must be executed only on a machine joined to a domain.

#### Examples

The follow example code shows the use of the [MprAdminIsDomainRasServer](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserversetinfo) and **MprAdminEstablishDomainRasServer** functions.

```cpp
#include <windows.h>
#include <stdio.h>
#include "mprapi.h"
#pragma comment(lib, "mprapi.lib")

int __cdecl main(){

    // The domain and RAS machine names being queried. These MUST be changed before using this sample code.
    PWCHAR pszDomain = L"YourDomainName.com";
    PWCHAR pszMachine = L"YourRASMachine";

    BOOL bIsRegistered = FALSE;
    DWORD dwRes = ERROR_SUCCESS;
    MPR_SERVER_HANDLE phMprServer;

    // Make sure RRAS is running on the remote server
    dwRes = MprAdminServerConnect(pszMachine, &phMprServer);
    if(dwRes != ERROR_SUCCESS){
        wprintf (L"RRAS is not running on %s.\n", pszMachine);
        return dwRes;
    }

    // Close RRAS handle. It's not needed.
    MprAdminServerDisconnect(&phMprServer);

    // Check to see if pszMachine is a RAS server for the domain
    dwRes = MprAdminIsDomainRasServer (pszDomain, pszMachine, &bIsRegistered);
    if (dwRes != ERROR_SUCCESS){
        //
        // Handle errors here
        //
       return dwRes;
    }

    if (bIsRegistered == TRUE){
        wprintf (L"The RRAS Server on %s is already registered in domain %s.\n", pszMachine, pszDomain);
        return ERROR_SUCCESS;
    }

    wprintf (L"The RRAS Server on %s is NOT registered in domain %s. Registering now...\n", pszMachine, pszDomain);
    dwRes = MprAdminEstablishDomainRasServer (pszDomain, pszMachine, TRUE);
    if (dwRes != ERROR_SUCCESS){
        //
        // Handle errors here
        //
        return dwRes;
    }
    return ERROR_SUCCESS;
}

```

## See also

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)