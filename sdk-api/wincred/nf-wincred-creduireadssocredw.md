# CredUIReadSSOCredW function

## Description

The **CredUIReadSSOCredW** function retrieves the user name for a single logon credential.

## Parameters

### `pszRealm` [in]

Pointer to a **null**-terminated string that specifies the realm. If this parameter is **NULL**, the default realm is used.

### `ppszUsername` [out]

Pointer to a pointer to a **null**-terminated string. When you have finished using the string, free *ppszUsername* by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

The return value is a **DWORD**. The following table lists the possible values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **ERROR_NOT_FOUND** | The credential was not found. |

## See also

[CredUIStoreSSOCredW](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduistoressocredw)