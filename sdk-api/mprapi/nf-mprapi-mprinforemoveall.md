# MprInfoRemoveAll function

## Description

The
**MprInfoRemoveAll** function removes all information blocks from the specified header.

## Parameters

### `lpHeader` [in]

Pointer to the information header from which to remove all information blocks.

### `lplpNewHeader` [out]

Pointer to a pointer variable. On successful return, this variable points to the information header with all information blocks removed.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Either the *lpHeader* parameter is **NULL** or the *lplpNewHeader* parameter is **NULL**. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the error message that corresponds to the returned error code. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprInfo Functions and Information Headers](https://learn.microsoft.com/windows/desktop/RRAS/understanding-mprinfo-functions-and-information-headers)

[MprInfoBlockRemove](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockremove)