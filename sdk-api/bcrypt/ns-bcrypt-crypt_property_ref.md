# CRYPT_PROPERTY_REF structure

## Description

The **CRYPT_PROPERTY_REF** structure contains information about a CNG context property.

## Members

### `pszProperty`

A pointer to a null-terminated Unicode string that contains the name of the property.

### `cbValue`

The size, in bytes, of the **pbValue** buffer.

### `pbValue`

A pointer to a memory buffer that contains the value of the property. The format and type of this data depend on the property.

## See also

[BCryptResolveProviders](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptresolveproviders)

[CRYPT_PROVIDER_REF](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_provider_ref)