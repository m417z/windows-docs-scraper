# CredIsProtectedA function

## Description

 The **CredIsProtected** function specifies whether the specified credentials are encrypted by a previous call to the [CredProtect](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credprotecta) function.

## Parameters

### `pszProtectedCredentials` [in]

A pointer to a null-terminated string that specifies the credentials to test.

### `pProtectionType` [out]

A pointer to a value from the [CRED_PROTECTION_TYPE](https://learn.microsoft.com/windows/desktop/api/wincred/ne-wincred-cred_protection_type) enumeration that specifies whether the credentials specified in the *pszProtectedCredentials* parameter are protected.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**.

For extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

> [!NOTE]
> The wincred.h header defines CredIsProtected as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).