# AUTHENTICATION_INFO structure

## Description

Describes security authentication information for content access.

## Members

### `dwSize`

Type: **DWORD**

Size of the structure, in bytes.

### `atAuthenticationType`

Type: **[AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-auth_type)**

Flag to describe the type of authentication. For a list of possible values, see the [AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-auth_type) enumerated type.

### `pcwszUser`

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string containing the user name.

### `pcwszPassword`

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string containing the password for  **pcwszUser**.