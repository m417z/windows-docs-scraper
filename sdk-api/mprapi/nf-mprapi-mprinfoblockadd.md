# MprInfoBlockAdd function

## Description

The
**MprInfoBlockAdd** function creates a new header that is identical to an existing header with the addition of a new block.

## Parameters

### `lpHeader` [in]

Pointer to the header in which to add the new block.

### `dwInfoType` [in]

Specifies the type of block to add. The types available depend on the transport:
[IPv4](https://learn.microsoft.com/windows/desktop/RRAS/ip-information-types-for-router-information-blocks), [IPv6](https://learn.microsoft.com/windows/desktop/RRAS/ipv6-information-types-for-router-information-blocks), or [IPX](https://learn.microsoft.com/windows/desktop/RRAS/ipx-information-types-for-router-information-blocks).

**Windows Server 2008:** If *dwInfoTYpe* contains [IP_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/RRAS/ip-information-types-for-router-information-blocks), *lpItemData* must point to a [INTERFACE_ROUTE_INFO](https://learn.microsoft.com/openspecs/windows_protocols/ms-rrasm/784d8544-140a-4769-b659-7d3168de9242) structure.

### `dwItemSize` [in]

Specifies the size of each item in the block to be added.

### `dwItemCount` [in]

Specifies the number of items of size *dwItemSize* to be copied as data for the new block.

### `lpItemData` [in]

Pointer to the data for the new block. The size in bytes of this buffer should be equal to the product of *dwItemSize* and *dwItemCount*.

### `lplpNewHeader` [out]

Pointer to a pointer variable that, on successful return, points to the new header.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *lpHeader*, *lplpNewHeader*, or *lpItemData* parameter is **NULL**, or a block of type *dwInfoType* already exists in the header. |
| **Other** | The call failed. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the error message that corresponds to the returned error code. |

## Remarks

After adding an information block, obtain the new size of the information header by call
[MprInfoBlockQuerySize](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockquerysize).

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprInfo Functions and Information Headers](https://learn.microsoft.com/windows/desktop/RRAS/understanding-mprinfo-functions-and-information-headers)

[MprInfoBlockQuerySize](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockquerysize)

[MprInfoBlockRemove](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoblockremove)

[MprInfoDuplicate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprinfoduplicate)