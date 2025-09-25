# BCRYPT_INIT_AUTH_MODE_INFO macro

## Syntax

```cpp
void BCRYPT_INIT_AUTH_MODE_INFO(
    BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO _AUTH_INFO_STRUCT_
);
```

## Description

The **BCRYPT_INIT_AUTH_MODE_INFO** macro initializes a [BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_authenticated_cipher_mode_info) structure for use in calls to [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) and [BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt) functions.

## Parameters

### `_AUTH_INFO_STRUCT_`

The BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO structure to initialize.