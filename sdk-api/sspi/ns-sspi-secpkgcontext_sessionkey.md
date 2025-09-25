# SecPkgContext_SessionKey structure

## Description

The **SecPkgContext_SessionKey** structure contains information about the session key used for the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This structure is returned by the [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function.

## Members

### `SessionKeyLength`

Size, in bytes, of the session key.

### `SessionKey`

The session key for the security context.