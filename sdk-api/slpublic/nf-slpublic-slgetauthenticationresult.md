# SLGetAuthenticationResult function

## Description

Gets the authentication results.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pcbValue` [out]

Type: **UINT***

A pointer to the size, in bytes, of the authentication result.

### `ppbValue` [out]

Type: **PBYTE***

A pointer to the authentication result. When finished using the memory, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **SL_E_AUTHN_MISMATCHED_KEY**<br><br>0xC004F078 | The key used in the [SLSetAuthenticationData](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slsetauthenticationdata) function call is incorrect. |
| **SL_E_AUTHN_CANT_VERIFY**<br><br>0xC004F07A | The authentication cannot be completed. |
| **SL_E_AUTHN_CHALLENGE_NOT_SET**<br><br>0xC004F079 | The authentication data (challenge) is not set. |