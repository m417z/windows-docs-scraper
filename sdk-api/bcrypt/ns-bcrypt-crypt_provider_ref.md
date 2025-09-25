# CRYPT_PROVIDER_REF structure

## Description

The **CRYPT_PROVIDER_REF** structure contains information about a cryptographic interface that a provider supports.

## Members

### `dwInterface`

The identifier of the interface that this reference applies to. This will be one of the [CNG Interface Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-interface-identifiers).

### `pszFunction`

A pointer to a null-terminated Unicode string that identifies the algorithm or function that the reference applies to. This can be one of the standard [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) or the identifier for another registered algorithm.

### `pszProvider`

A pointer to a null-terminated Unicode string that contains the name of the provider.

### `cProperties`

The number of elements in the **rgpProperties** array. If the algorithm or function has no properties, then this member will be zero.

### `rgpProperties`

An array of [CRYPT_PROPERTY_REF](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_property_ref) structure pointers that contain the properties for this algorithm or function. The **cProperties** member contains the number of elements in this array.

### `pUM`

A pointer to a [CRYPT_IMAGE_REF](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_image_ref) structure that contains information about the user mode provider module. If this information was not requested or the provider is not registered as a user mode provider, this member will be **NULL**.

### `pKM`

A pointer to a [CRYPT_IMAGE_REF](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_image_ref) structure that contains information about the kernel mode provider module. If this information was not requested or the provider is not registered as a kernel mode provider, this member will be **NULL**.

## See also

[BCryptResolveProviders](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptresolveproviders)

[CRYPT_PROVIDER_REFS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_provider_refs)