# MprInfoBlockRemove function

## Description

The
**MprInfoBlockRemove** function creates a new header that is identical to an existing header with a specified block removed.

## Parameters

### `lpHeader` [in]

Pointer to the header from which the block should be removed.

### `dwInfoType` [in]

Specifies the type of block to be removed. The types available depend on the transport:
[IP](https://learn.microsoft.com/windows/desktop/RRAS/ip-information-types-for-router-information-blocks) or
[IPX](https://learn.microsoft.com/windows/desktop/RRAS/ipx-information-types-for-router-information-blocks).

### `lplpNewHeader` [out]

Pointer to a pointer variable that receives the new header.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *lpHeader* parameter is **NULL**, or no block of type *dwInfoType* exists in the header. |
| **ERROR_NOT_ENOUGH_MEMORY** | The memory allocation required for successful execution of [MprInfoBlockRemove](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockremove) could not be completed. |
| **Other** | The call failed. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the error message that corresponds to the returned error code. |

## Remarks

After removing an information block, obtain the new size of the information header by call
[MprInfoBlockQuerySize](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockquerysize).

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprInfo Functions and Information Headers](https://learn.microsoft.com/windows/desktop/RRAS/understanding-mprinfo-functions-and-information-headers)

[MprInfoBlockAdd](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockadd)

[MprInfoBlockQuerySize](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockquerysize)