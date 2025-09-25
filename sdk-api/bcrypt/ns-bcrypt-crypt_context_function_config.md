# CRYPT_CONTEXT_FUNCTION_CONFIG structure

## Description

The **CRYPT_CONTEXT_FUNCTION_CONFIG** structure contains configuration information for a cryptographic function of a CNG context.

## Members

### `dwFlags`

A set of flags that determine the options for the context function configuration. This can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **CRYPT_EXCLUSIVE** | Restricts the set of usable providers for this function to only those that this function is specifically registered to support. |

### `dwReserved`

## See also

[BCryptConfigureContextFunction](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptconfigurecontextfunction)