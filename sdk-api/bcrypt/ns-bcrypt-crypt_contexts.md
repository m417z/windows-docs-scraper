# CRYPT_CONTEXTS structure

## Description

The **CRYPT_CONTEXTS** structure contains a set of CNG configuration context identifiers.

## Members

### `cContexts`

Contains the number of elements in the **rgpszContexts** array.

### `rgpszContexts`

An array of pointers to null-terminated Unicode strings that contain the identifiers of the contexts contained in this set. The **cContext** member contains the number of elements in this array.

## See also

[BCryptEnumContexts](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptenumcontexts)