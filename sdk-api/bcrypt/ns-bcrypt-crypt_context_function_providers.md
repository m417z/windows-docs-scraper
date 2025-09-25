# CRYPT_CONTEXT_FUNCTION_PROVIDERS structure

## Description

The **CRYPT_CONTEXT_FUNCTION_PROVIDERS** structure contains a set of cryptographic function providers for a CNG configuration context.

## Members

### `cProviders`

The number of elements in the **rgpszProviders** array.

### `rgpszProviders`

An array of pointers to null-terminated Unicode strings that contain the identifiers of the function providers contained in this set. The **cProviders** member contains the number of elements in this array.

## See also

[BCryptEnumContextFunctionProviders](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptenumcontextfunctionproviders)