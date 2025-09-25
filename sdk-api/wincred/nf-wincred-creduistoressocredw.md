# CredUIStoreSSOCredW function

## Description

The **CredUIStoreSSOCredW** function stores a single logon credential.

## Parameters

### `pszRealm` [in]

Pointer to a **null**-terminated string that specifies the realm. If this parameter is **NULL**, the default realm is used.

### `pszUsername` [in]

Pointer to a **null**-terminated string that specifies the user's name.

### `pszPassword` [in]

Pointer to a **null**-terminated string that specifies the user's password. When you have finished using the password, clear the password from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `bPersist` [in]

Boolean value that specifies whether the credentials are persisted. If this value is **TRUE**, the credentials are persisted. If this value is **FALSE**, the credentials are not persisted.

## Return value

The return value is a **DWORD**. A return value of ERROR_SUCCESS indicates the function was successful.

## See also

[CredUIReadSSOCredW](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduireadssocredw)