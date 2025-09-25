# MgmGetMfeStats function

## Description

The
**MgmGetMfeStats** function retrieves the statistics for a specific MFE. The statistics returned include the packets received, bytes received, and the packets forwarded on each outgoing interface.

## Parameters

### `pimm` [in]

Pointer to a
[MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe) structure that specifies the MFE for which to retrieve statistics. The information to be returned is indicated by the **dwSource** and **dwGroup** members of the
**MIB_IPMCAST_MFE** structure.

### `pdwBufferSize` [in, out]

On input, *pdwBufferSize* is a pointer to a **DWORD**-sized memory location that contains the size, in bytes, of the buffer pointed to by *pbBuffer*.

On output, if the return value is ERROR_INSUFFICIENT_BUFFER, *pdwBufferSize* receives the minimum size the buffer pointed to by *pbBuffer* must be to hold the set of MFE statistics; otherwise the value of *pdwBufferSize* remains unchanged.

### `pbBuffer` [in, out]

On input, the client must supply a pointer to a buffer.

On output, *pbBuffer* contains the specified set of MFE statistics.

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
| **ERROR_INSUFFICIENT_BUFFER** | The specified buffer is too small for the statistics for even one MFE. The client should check the value of *pdwBufferSize* for the minimum buffer size required to retrieve statistics for one MFE. |
| **ERROR_NOT_FOUND** | The specified MFE was not found. |

## Remarks

The MFE statistics are returned in either an [MIB_IPMCAST_MFE_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats) or [MIB_IPMCAST_MFE_STATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats_ex_xp) structure determined by the *dwFlags* parameter.

## See also

[MIB_IPMCAST_MFE_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats)

[MIB_IPMCAST_MFE_STATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats_ex_xp)

[MgmGetFirstMfeStats](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetfirstmfestats)

[MgmGetNextMfeStats](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetnextmfestats)