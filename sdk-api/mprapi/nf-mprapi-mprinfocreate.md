# MprInfoCreate function

## Description

The
**MprInfoCreate** function creates a new information header.

## Parameters

### `dwVersion` [in]

Specifies the version of the information header structure to be created. The only value currently supported is RTR_INFO_BLOCK_VERSION, as declared in Mprapi.h.

### `lplpNewHeader` [out]

Pointer to the allocated and initialized header.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *lplpNewHeader* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | The requested memory allocation could not be completed. |
| **Other** | The call failed. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the error message that corresponds to the returned error code. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprInfo Functions and Information Headers](https://learn.microsoft.com/windows/desktop/RRAS/understanding-mprinfo-functions-and-information-headers)