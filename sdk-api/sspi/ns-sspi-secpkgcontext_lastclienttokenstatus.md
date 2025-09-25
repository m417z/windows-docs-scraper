# SecPkgContext_LastClientTokenStatus structure

## Description

Specifies whether the token from the most recent call to the [InitializeSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) function is the last token from the client.

## Members

### `LastClientTokenStatus`

A value of the [SECPKG_ATTR_LCT_STATUS](https://learn.microsoft.com/windows/desktop/api/sspi/ne-sspi-secpkg_attr_lct_status) enumeration that indicates the status of the token returned by the most recent call to [InitializeSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta).

## See also

[SECPKG_ATTR_LCT_STATUS](https://learn.microsoft.com/windows/desktop/api/sspi/ne-sspi-secpkg_attr_lct_status)