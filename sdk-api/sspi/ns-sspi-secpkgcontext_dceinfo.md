# SecPkgContext_DceInfo structure

## Description

The **SecPkgContext_DceInfo** structure contains authorization data used by DCE services. The
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function uses this structure.

## Members

### `AuthzSvc`

Specifies the authorization service used. For DCE use only.

### `pPac`

Pointer to package-specific authorization data.

## See also

[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa)