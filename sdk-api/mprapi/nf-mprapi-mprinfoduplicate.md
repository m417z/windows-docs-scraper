# MprInfoDuplicate function

## Description

The
**MprInfoDuplicate** function duplicates an existing information header.

## Parameters

### `lpHeader` [in]

Pointer to the information header to duplicate.

### `lplpNewHeader` [out]

Pointer to a pointer variable. On successful return, this variable points to the new (duplicate) information header.

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

[MprInfoCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfocreate)