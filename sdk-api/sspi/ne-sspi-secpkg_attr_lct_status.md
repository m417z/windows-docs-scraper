# SECPKG_ATTR_LCT_STATUS enumeration

## Description

Indicates whether the token from the most recent call to the [InitializeSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) function is the last token from the client.

This enumeration is used in the [SecPkgContext_LastClientTokenStatus](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_lastclienttokenstatus) structure.

## Constants

### `SecPkgAttrLastClientTokenYes`

The token is the last token from the client.

### `SecPkgAttrLastClientTokenNo`

The token is not the last token from the client.

### `SecPkgAttrLastClientTokenMaybe`

It is not known whether the token is the last token from the client.

## See also

[SecPkgContext_LastClientTokenStatus](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_lastclienttokenstatus)