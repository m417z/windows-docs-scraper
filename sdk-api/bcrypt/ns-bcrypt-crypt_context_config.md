# CRYPT_CONTEXT_CONFIG structure

## Description

The **CRYPT_CONTEXT_CONFIG** structure contains configuration information for a CNG context.

## Members

### `dwFlags`

A set of flags that determine the options for the configuration context. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_EXCLUSIVE** | Restricts the set of cryptographic functions in an interface to those that the current CNG context is specifically registered to support. <br><br>If this flag is set, then any attempts to resolve a given function will succeed only if one of the following is true:<br><br>* The function exists within the current CNG context.<br>* The function exists in some interface in the default context, and an instance of that same interface also exists within the current CNG context. |
| **CRYPT_OVERRIDE** | Indicates that this entry in the enterprise-wide configuration table should take precedence over any and all corresponding entries in the local-machine configuration table for this context. This flag only applies to entries in the enterprise-wide configuration table. Without this flag, local machine configuration entries take precedence. |

### `dwReserved`

## See also

[BCryptConfigureContext](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptconfigurecontext)

[BCryptCreateContext](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptcreatecontext)

[BCryptQueryContextConfiguration](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptquerycontextconfiguration)