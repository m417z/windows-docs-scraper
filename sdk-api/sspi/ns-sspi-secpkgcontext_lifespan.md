# SecPkgContext_Lifespan structure

## Description

The **SecPkgContext_Lifespan** structure indicates the life span of a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function uses this structure.

## Members

### `tsStart`

Time at which the context was established.

### `tsExpiry`

Time at which the context will expire.

## Remarks

It is recommended that the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) always return these values in local time.

## See also

[QueryContextAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa)