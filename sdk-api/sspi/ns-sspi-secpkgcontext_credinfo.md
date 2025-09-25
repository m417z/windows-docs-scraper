# SecPkgContext_CredInfo structure

## Description

Specifies the type of credentials used to create a client context.

## Members

### `CredClass`

A value of the [SECPKG_CRED_CLASS](https://learn.microsoft.com/windows/desktop/api/sspi/ne-sspi-secpkg_cred_class) enumeration that indicates the type of credentials.

### `IsPromptingNeeded`

A nonzero value indicates that the application must prompt the user for credentials. All other values indicate that the application does not need to prompt the user.

## See also

[SpQueryContextAttributes](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spquerycontextattributesfn)