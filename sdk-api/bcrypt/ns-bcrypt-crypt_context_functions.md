# CRYPT_CONTEXT_FUNCTIONS structure

## Description

The **CRYPT_CONTEXT_FUNCTIONS** structure contains a set of cryptographic functions for a CNG configuration context.

## Members

### `cFunctions`

The number of elements in the **rgpszFunctions** array.

### `rgpszFunctions`

An array of pointers to null-terminated Unicode strings that contain the identifiers of the cryptographic functions contained in this set. The **cFunctions** member contains the number of elements in this array.

## See also

[BCryptEnumContextFunctions](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptenumcontextfunctions)