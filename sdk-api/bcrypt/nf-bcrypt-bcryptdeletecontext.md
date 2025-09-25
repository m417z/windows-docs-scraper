# BCryptDeleteContext function

## Description

[**BCryptDeleteContext** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **BCryptDeleteContext** function deletes an existing CNG configuration context.

## Parameters

### `dwTable` [in]

Identifies the configuration table to delete the context from. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | Delete the context from the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to delete.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

**BCryptDeleteContext** can be called only in user mode.