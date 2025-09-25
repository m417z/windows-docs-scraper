# BCryptConfigureContextFunction function

## Description

[**BCryptConfigureContextFunction** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **BCryptConfigureContextFunction** function sets the configuration information for the cryptographic function of an existing CNG context.

## Parameters

### `dwTable` [in]

Identifies the configuration table that the context exists in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | The context exists in the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to set the cryptographic function configuration information for.

### `dwInterface` [in]

Identifies the cryptographic interface to set the function configuration information for. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE** | Set the function configuration information in the list of asymmetric encryption functions. |
| **BCRYPT_CIPHER_INTERFACE** | Set the function configuration information in the list of cipher functions. |
| **BCRYPT_HASH_INTERFACE** | Set the function configuration information in the list of hash functions. |
| **BCRYPT_RNG_INTERFACE** | Set the function configuration information in the list of random number generator functions. |
| **BCRYPT_SECRET_AGREEMENT_INTERFACE** | Set the function configuration information in the list of secret agreement functions. |
| **BCRYPT_SIGNATURE_INTERFACE** | Set the function configuration information in the list of signature functions. |
| **NCRYPT_KEY_STORAGE_INTERFACE** | Set the function configuration information in the list of key storage functions. |
| **NCRYPT_SCHANNEL_INTERFACE** | Set the function configuration information in the list of Schannel functions. |
| **NCRYPT_SCHANNEL_SIGNATURE_INTERFACE** | Set the function configuration information in the list of signature suites that Schannel accepts for TLS 1.2.<br><br>**Windows Vista and Windows Server 2008:** This value is not supported. |

### `pszFunction` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the cryptographic function to set the configuration information for.

### `pConfig` [in]

The address of a [CRYPT_CONTEXT_FUNCTION_CONFIG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_context_function_config) structure that contains the new function configuration information.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

**BCryptConfigureContextFunction** can be called only in user mode.

## See also

[CRYPT_CONTEXT_FUNCTION_CONFIG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_context_function_config)