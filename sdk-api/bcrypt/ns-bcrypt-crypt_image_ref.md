# CRYPT_IMAGE_REF structure

## Description

The **CRYPT_IMAGE_REF** structure contains information about a CNG provider module.

## Members

### `pszImage`

A pointer to a null-terminated Unicode string that contains the name of the provider module.

### `dwFlags`

A set of flags that indicate how CNG will manage the binary image with respect to this interface. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_MIN_DEPENDENCIES** | The provider for this interface is only dependent on a minimum set of system components. This flag applies to a specific interface only and does not mean that all interfaces supported by the binary image conform to this standard. |
| **CRYPT_PROCESS_ISOLATE** | This flag is not used. |

## See also

[BCryptResolveProviders](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptresolveproviders)

[CRYPT_PROVIDER_REF](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_provider_ref)