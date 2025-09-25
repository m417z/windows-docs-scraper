# MgmGetFirstMfe function

## Description

The
**MgmGetFirstMfe** function retrieves MFEs starting at the beginning of the MFE list. The function can retrieve zero, one, or more MFEs. The number of MFEs returned depends on the size of the MFEs and the size of the buffer supplied by the client when the function is called.

The data returned in the buffer is ordered first by group, and then by the sources within a group.

## Parameters

### `pdwBufferSize` [in, out]

On input, *pdwBufferSize* is a pointer to a **DWORD**-sized memory location containing the size, in bytes, of *pbBuffer*.

On output, if the return value is ERROR_INSUFFICIENT_BUFFER, *pdwBufferSize* receives the minimum size *pbBuffer* must be to hold the MFE; otherwise, the value of *pdwBufferSize* remains unchanged.

### `pbBuffer` [in, out]

On input, the client must supply a pointer to a buffer.

On output, *pbBuffer* contains one or more MFEs. Each MFE is a
[MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe) structure.

### `pdwNumEntries` [in, out]

On input, the client must supply a pointer to a **DWORD**-sized memory location.

On output, *pdwNumEntries* receives the number of MFEs contained in *pbBuffer*.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INSUFFICIENT_BUFFER** | The specified buffer is too small for even one MFE. The client should check the value of *pdwBufferSize* for the minimum buffer size required to retrieve one MFE. |
| **ERROR_MORE_DATA** | More MFEs are available. |
| **ERROR_NO_MORE_ITEMS** | No more MFEs are available. Zero or more MFEs were returned; check the value of *pdwNumEntries* to verify how many MFEs were returned. |

## Remarks

This function is used to begin sequential retrieval of MFEs; use
[MgmGetNextMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetnextmfe) to continue the retrieval process.

In general, to retrieve MFEs, first call
**MgmGetFirstMfe**. Then, call
[MgmGetNextMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetnextmfe) one or more times, until there are no more MFEs to return. Each call to
**MgmGetNextMfe** should begin after the last MFE returned by the previous call to
**MgmGetNextMfe** (or the initial call to
**MgmGetFirstMfe**). To do this, the client specifies the last source and group in the buffer returned by a previous call.

**Note** The minimum size of the buffer pointed to by *pbBuffer* is not fixed; it is different for each MFE. Use the
sizeof([MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe)) macro to determine the size of each MFE returned in the buffer.

## See also

[MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe)

[MgmGetMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetmfe)

[MgmGetNextMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetnextmfe)