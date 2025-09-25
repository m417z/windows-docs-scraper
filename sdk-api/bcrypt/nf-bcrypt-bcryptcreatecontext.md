# BCryptCreateContext function

## Description

[**BCryptCreateContext** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **BCryptCreateContext** function creates a new CNG configuration context.

## Parameters

### `dwTable` [in]

Identifies the configuration table to create the context in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | Create the context in the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to create.

### `pConfig` [in, optional]

A pointer to a [CRYPT_CONTEXT_CONFIG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_context_config) structure that contains additional configuration data for the new context. This parameter can be **NULL** if it is not needed.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

**BCryptCreateContext** can be called only in user mode.