# MprAdminGetErrorString function

## Description

The
**MprAdminGetErrorString** function returns the string associated with a router error from Mprerror.h.

## Parameters

### `dwError` [in]

Specifies the error code for a router error.

### `lplpwsErrorString` [out]

Pointer to an **LPWSTR** variable that points to the text associated with the *dwError* code on successful return. Free this memory by calling
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_MR_MID_NOT_FOUND** | The error code in *dwError* is unknown. |

## See also

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)