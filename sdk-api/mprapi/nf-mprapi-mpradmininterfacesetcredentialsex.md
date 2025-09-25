# MprAdminInterfaceSetCredentialsEx function

## Description

Use the
**MprAdminInterfaceSetCredentialsEx** function to set extended credentials information for an interface. Use this function to set credentials information used for Extensible Authentication Protocols (EAPs).

## Parameters

### `hMprServer` [in]

Handle to a router. This handle is obtained from a previous call to
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface. This handle is obtained from a previous call to
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is structured in the *lpbBuffer* parameter. Acceptable values for *dwLevel* include 0 or 1 as listed in the following table. A value of 1 indicates the information is a pre-shared key for the interface.

| Value | Structure Format |
| --- | --- |
| 0 | Windows 2000 Server: [MPR_CREDENTIALSEX_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_0) |
| 1 | Windows Server 2003 or later: [MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1) |

### `lpbBuffer` [in]

A pointer to a
[MPR_CREDENTIALSEX_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_0) or [MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1) structure. The *dwLevel* parameter indicates the type of structure.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_INVALID_PARAMETER** | The *lplpbBuffer* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_NOT_SUPPORTED** | The *dwLevel* value is invalid. |

## Remarks

To a delete a pre-shared key, call
[MprAdminInterfaceSetCredentials](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetcredentials) with the **dwSize** member of the [MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1) structure set to zero.

## See also

[MPR_CREDENTIALSEX_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_0)

[MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1)

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceSetCredentials](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetcredentials)

[MprAdminInterfaceSetCredentialsEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetcredentialsex)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)