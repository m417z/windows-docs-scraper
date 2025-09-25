# MprAdminInterfaceGetCredentialsEx function

## Description

Use the
**MprAdminInterfaceGetCredentialsEx** function to retrieve extended credentials information for the specified interface. Use this function to retrieve credentials information used for Extensible Authentication Protocols (EAPs).

## Parameters

### `hMprServer` [in]

Handle to a router. This handle is obtained from a previous call to
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface. This handle is obtained from a previous call to
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is returned in the *lplpbBuffer* parameter. Acceptable values for *dwLevel* include 0 or 1, as listed in the following table.

| Value | Structure Format |
| --- | --- |
| 0 | Windows 2000 Server: [MPR_CREDENTIALSEX_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_0) |
| 1 | Windows Server 2003 or later: [MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1) |

A value of 1 indicates the information is a pre-shared key for the interface, which is in an encrypted format.

### `lplpbBuffer` [out]

On successful completion, a pointer to a
[MPR_CREDENTIALSEX_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_0) or [MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1) structure. The *dwLevel* parameter indicates the type of structure.
Free the memory occupied by this structure with
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

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

## See also

[MPR_CREDENTIALSEX_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_0)

[MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1)

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceGetCredentials](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetcredentials)

[MprAdminInterfaceSetCredentialsEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetcredentialsex)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)