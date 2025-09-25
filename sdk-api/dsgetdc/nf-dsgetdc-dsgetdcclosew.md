# DsGetDcCloseW function

## Description

The **DsGetDcClose** function closes a domain controller enumeration operation.

## Parameters

### `GetDcContextHandle` [in]

Contains the domain controller enumeration context handle provided by the [DsGetDcOpen](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcopena) function.

## Return value

This function does not return a value.

## Remarks

When this function is called, *GetDcContextHandle* is invalid and cannot be used.

## See also

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[DsGetDcOpen](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcopena)

[Enumerating Domain Controllers](https://learn.microsoft.com/windows/desktop/AD/enumerating-domain-controllers)