# MprInfoBlockFind function

## Description

The
**MprInfoBlockFind** function locates a specified block in an information header, and retrieves information about the block.

## Parameters

### `lpHeader` [in]

Specifies the header in which to locate the block.

### `dwInfoType` [in]

Specifies the type of block to locate. The types available depend on the transport:
[IP](https://learn.microsoft.com/windows/desktop/RRAS/ip-information-types-for-router-information-blocks) or
[IPX](https://learn.microsoft.com/windows/desktop/RRAS/ipx-information-types-for-router-information-blocks).

### `lpdwItemSize` [out]

Pointer to a **DWORD** variable that receives the size of each item in the located block's data. This parameter is optional. If this parameter is **NULL**, the item size is not returned.

### `lpdwItemCount` [out]

Pointer to a **DWORD** variable that receives the number of items of size *dwItemSize* contained in the block's data. This parameter is optional. If this parameter is **NULL**, the item count is not returned.

### `lplpItemData` [out]

Pointer to a pointer that, on successful return, points to the data for the located block. This parameter is optional. If this parameter is **NULL**, the data is not returned.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *lpInfoHeader* parameter is **NULL**. |
| **ERROR_NOT_FOUND** | No block of type *dwInfoType* exists in the header. |
| **Other** | The call failed. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the error message that corresponds to the returned error code. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprInfo Functions and Information Headers](https://learn.microsoft.com/windows/desktop/RRAS/understanding-mprinfo-functions-and-information-headers)