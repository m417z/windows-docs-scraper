# MgmGetFirstMfeStats function

## Description

The
**MgmGetFirstMfeStats** function retrieves MFE statistics starting at the beginning of the MFE list. The function can retrieve zero, one, or more sets of MFE statistics. The number of sets returned depends on the size of the entries and the size of the buffer supplied by the client when the function is called.

The data returned in the buffer is ordered first by group, and then by the sources within a group. The statistics returned include the packets received, bytes received, and packets forwarded on each outgoing interface.

## Parameters

### `pdwBufferSize` [in, out]

On input, *pdwBufferSize* is a pointer to a **DWORD**-sized memory location containing the size, in bytes, of *pbBuffer*.

On output, if the return value is ERROR_INSUFFICIENT_BUFFER, *pdwBufferSize* receives the minimum size *pbBuffer* must be to hold a set of MFE statistics; otherwise, the value of *pdwBufferSize* remains unchanged.

### `pbBuffer` [in, out]

On input, the client must supply a pointer to a buffer.

On output, *pbBuffer* contains one or more sets of MFE statistics. Each set of MFE statistics is a
[MIB_IPMCAST_MFE_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats) structure.

### `pdwNumEntries` [in, out]

On input, the client must supply a pointer to a **DWORD**-sized memory location.

On output, *pdwNumEntries* receives the number of sets of MFE statistics contained in *pbBuffer*.

### `dwFlags`

Determines the data structure returned.

| Value | Meaning |
| --- | --- |
| **MGM_MFE_STATS_0** | Include statistics corresponding to [MIB_IPMCAST_MFE_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats). |
| **MGM_MFE_STATS_1** | Include statistics corresponding to [MIB_IPMCAST_MFE_STATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats_ex_xp). |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INSUFFICIENT_BUFFER** | The specified buffer is too small for even one set of MFE statistics. The client should check the value of *pdwBufferSize* for the minimum buffer size required to retrieve one set of statistics. |
| **ERROR_MORE_DATA** | More MFE statistics are available. |
| **ERROR_NO_MORE_ITEMS** | No more MFE statistics are available. Zero or more sets of MFE statistics were returned; check the value of *pdwNumEntries* to verify how many sets of statistics were returned. |

## Remarks

This function is used to begin sequential retrieval of MFE statistics; use
[MgmGetNextMfeStats](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetnextmfestats) to continue the retrieval process.

In general, to retrieve MFE statistics, first call
**MgmGetFirstMfeStats**. Then, call
[MgmGetNextMfeStats](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetnextmfestats) one or more times, until there are no more MFEs to return. Each call to
**MgmGetNextMfeStats** should begin after the last MFE returned by the previous call to
**MgmGetNextMfeStats** (or the initial call to
**MgmGetFirstMfeStats**) To do this, the client specifies the last source and group in the buffer returned by a previous call.

The MFE statistics are returned in either an [MIB_IPMCAST_MFE_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats) or [MIB_IPMCAST_MFE_STATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats_ex_xp) structure determined by the *dwFlags* parameter.

**Note** The minimum size of the buffer pointed to by *pbBuffer* is not fixed; it is different for each set of MFE statistics. Use the
**sizeof** macro to determine the size of each set of statistics returned in the buffer.

## See also

[MIB_IPMCAST_MFE_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats)

[MIB_IPMCAST_MFE_STATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats_ex_xp)

[MgmGetMfeStats](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetmfestats)

[MgmGetNextMfeStats](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetnextmfestats)