# MPR_CREDENTIALSEX_1 structure

## Description

The
**MPR_CREDENTIALSEX_1** structure contains a pre-shared key used by a demand-dial interface.

## Members

### `dwSize`

Specifies the size of the data pointed to by the **lpbCredentialsInfo** member.

### `lpbCredentialsInfo`

Pointer to the pre-shared key.

## Remarks

To a delete a pre-shared key, call
[MprAdminInterfaceSetCredentials](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetcredentials) with the **MPR_CREDENTIALSEX_1.dwSize** member set to zero.

## See also

[MprAdminInterfaceGetCredentialsEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetcredentialsex)

[MprAdminInterfaceSetCredentialsEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetcredentialsex)