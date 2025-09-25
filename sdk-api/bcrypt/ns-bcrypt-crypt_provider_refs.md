# CRYPT_PROVIDER_REFS structure

## Description

The **CRYPT_PROVIDER_REFS** structure contains a collection of provider references.

## Members

### `cProviders`

The number of elements in the **rgpProviders** array.

### `rgpProviders`

An array of [CRYPT_PROVIDER_REF](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_provider_ref) structure pointers that contain the provider references. The **cProviders** member contains the number of elements in this array.

## See also

[BCryptResolveProviders](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptresolveproviders)