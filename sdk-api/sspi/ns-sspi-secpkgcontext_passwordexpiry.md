# SecPkgContext_PasswordExpiry structure

## Description

The **SecPkgContext_PasswordExpiry** structure contains information about the expiration of a password or other credential used for the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This structure is returned by [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa).

## Members

### `tsPasswordExpires`

A [TimeStamp](https://learn.microsoft.com/windows/desktop/SecAuthN/timestamp) variable that indicates when the credentials for the security context expire. For password-based packages, this variable indicates when the password expires. For [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly), this variable indicates when the ticket expires.