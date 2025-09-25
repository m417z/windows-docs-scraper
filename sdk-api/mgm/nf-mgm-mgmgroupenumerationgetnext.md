# MgmGroupEnumerationGetNext function

## Description

The
**MgmGroupEnumerationGetNext** function retrieves the next set of group entries. The information that is returned by this function is a list of groups joined and the sources requested, if any.

The groups are not returned in any particular order.

## Parameters

### `hEnum` [in]

Handle to the enumeration that was obtained from a previous call to
[MgmGroupEnumerationStart](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationstart).

### `pdwBufferSize` [in, out]

On input, *pdwBufferSize* is a pointer to a **DWORD**-sized memory location that contains the size, in bytes, of the buffer pointed to by *pbBuffer*.

On output, if the return value is ERROR_INSUFFICIENT_BUFFER, *pdwBufferSize* receives the minimum size that the buffer pointed to by *pbBuffer* must be to hold a group entry; otherwise the value of *pdwBufferSize* remains unchanged.

### `pbBuffer` [in, out]

On input, the client must supply a pointer to a buffer.

On output, *pbBuffer* contains one or more group entries. Each group entry is a
[SOURCE_GROUP_ENTRY](https://learn.microsoft.com/windows/desktop/api/mgm/ns-mgm-source_group_entry) structure.

### `pdwNumEntries` [in, out]

On input, the client must supply a pointer to a **DWORD** value.

On output, *pdwNumEntries* receives the number of groups in *pbBuffer*.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INSUFFICIENT_BUFFER** | The specified buffer is too small to hold even one group. The client should check the value of *pdwBufferSize* for the minimum buffer size required to retrieve one group. |
| **ERROR_INVALID_PARAMETER** | Invalid handle to an enumeration. |
| **ERROR_MORE_DATA** | More groups are available. |
| **ERROR_NO_MORE_ITEMS** | No more groups are available. Zero or more groups were returned; check the value of *pdwNumEntries* to verify how many groups were returned. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory to complete this operation. |

## See also

[MgmGroupEnumerationEnd](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationend)

[MgmGroupEnumerationStart](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationstart)

[SOURCE_GROUP_ENTRY](https://learn.microsoft.com/windows/desktop/api/mgm/ns-mgm-source_group_entry)