# IsTokenRestricted function

## Description

The **IsTokenRestricted** function indicates whether a token contains a list of restricted [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs).

## Parameters

### `TokenHandle` [in]

A handle to an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to test.

## Return value

If the token contains a list of restricting SIDs, the return value is nonzero.

If the token does not contain a list of restricting SIDs, the return value is zero.

If an error occurs, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken) function can restrict a token by disabling SIDs, deleting privileges, and specifying a list of restricting SIDs. The **IsTokenRestricted** function checks only for the list of restricting SIDs. If a token does not have any restricting SIDs, **IsTokenRestricted** returns **FALSE**, even though the token was created by a call to **CreateRestrictedToken**.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken)