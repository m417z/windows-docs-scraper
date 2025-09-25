# MprInfoBlockSet function

## Description

The
**MprInfoBlockSet** creates a new header that is identical to an existing header with a specified block modified.

## Parameters

### `lpHeader` [in]

Pointer to the header in which to modify the specified block.

### `dwInfoType` [in]

Specifies the type of block to change. The types available depend on the transport:
[IP](https://learn.microsoft.com/windows/desktop/RRAS/ip-information-types-for-router-information-blocks) or
[IPX](https://learn.microsoft.com/windows/desktop/RRAS/ipx-information-types-for-router-information-blocks).

### `dwItemSize` [in]

Specifies the size of each item in the block's new data.

### `dwItemCount` [in]

Specifies the number of items of size *dwItemSize* to be copied as the new data for the block.

### `lpItemData` [in]

Pointer to the new data for the block. This should point to a buffer with a size (in bytes) equal to the product of *dwItemSize* and *dwItemCount*.

### `lplpNewHeader` [out]

Pointer to a pointer variable that, on successful return, points to the new header.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One (or more) required parameters is **NULL**, or no block of type *dwInfoType* exists in the header. |
| **Other** | The call failed. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the error message that corresponds to the returned error code. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprInfo Functions and Information Headers](https://learn.microsoft.com/windows/desktop/RRAS/understanding-mprinfo-functions-and-information-headers)

[MprInfoBlockAdd](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockadd)

[MprInfoBlockRemove](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockremove)