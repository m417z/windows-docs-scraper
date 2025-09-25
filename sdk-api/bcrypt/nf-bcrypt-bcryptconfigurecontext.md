# BCryptConfigureContext function

## Description

[**BCryptConfigureContext** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **BCryptConfigureContext** function sets the configuration information for an existing CNG context.

## Parameters

### `dwTable` [in]

Identifies the configuration table that the context exists in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | The context exists in the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to set the configuration information for.

### `pConfig` [in]

The address of a [CRYPT_CONTEXT_CONFIG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_context_config) structure that contains the new context configuration information.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

**BCryptConfigureContext** can be called only in user mode.

## See also

[CRYPT_CONTEXT_CONFIG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_context_config)