# NtCompareTokens function

The **NtCompareTokens** function compares two [*access tokens*](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) and determines whether they are equivalent with respect to a call to the [**AccessCheck**](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-accesscheck) function.

## Parameters

*FirstTokenHandle* \[in\]

A handle to the first access token to compare. The token must be open for **TOKEN\_QUERY** access.

*SecondTokenHandle* \[in\]

A handle to the second access token to compare. The token must be open for **TOKEN\_QUERY** access.

*Equal* \[out\]

A pointer to a variable that receives a value that indicates whether the tokens represented by the *FirstTokenHandle* and *SecondTokenHandle* parameters are equivalent.

## Return value

If the function succeeds, the function returns STATUS\_SUCCESS.

If the function fails, it returns an **NTSTATUS** error code.

## Remarks

Two access control tokens are considered to be equivalent if all of the following conditions are true:

- Every [*security identifier*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that is present in either token is also present in the other token.
- Neither or both of the tokens are restricted.
- If both tokens are restricted, every SID that is restricted in one token is also restricted in the other token.
- Every privilege present in either token is also present in the other token.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Ntseapi.h |
| DLL<br> | Ntdll.dll |

