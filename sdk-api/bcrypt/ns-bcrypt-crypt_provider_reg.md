# CRYPT_PROVIDER_REG structure

## Description

The **CRYPT_PROVIDER_REG** structure is used to contain registration information for a CNG provider.

## Members

### `cAliases`

Contains the number of elements in the **rgpszAliases** array. If the provider has no aliases, this member will be zero and the **rgpszAliases** member will be **NULL**.

### `rgpszAliases`

An array of null-terminated Unicode strings that contains the aliases of the provider. If the provider has no aliases, this member will contain **NULL** and the **cAliases** member will contain zero.

### `pUM`

A pointer to a [CRYPT_IMAGE_REG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_image_reg) structure that contains the registration information for the user mode provider. If this member is **NULL**, the provider is not registered for user mode.

### `pKM`

A pointer to a [CRYPT_IMAGE_REG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_image_reg) structure that contains the registration information for the kernel mode provider. If this member is **NULL**, the provider is not registered for kernel mode.