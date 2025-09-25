# MprInfoDelete function

## Description

The
**MprInfoDelete** function deletes an information header created using
[MprInfoCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfocreate), or retrieved by
[MprInfoBlockAdd](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockadd),
[MprInfoBlockRemove](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockremove), or
[MprInfoBlockSet](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockset).

## Parameters

### `lpHeader` [in]

Pointer to the header to be deallocated.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *lpHeader* parameter is **NULL**. |
| **Other** | The call failed. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the error message that corresponds to the returned error code. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprInfoBlockAdd](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockadd)

[MprInfoBlockRemove](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockremove)

[MprInfoBlockSet](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockset)