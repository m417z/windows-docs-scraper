# MgmGetMfe function

## Description

The
**MgmGetMfe** function retrieves a specific MFE.

## Parameters

### `pimm` [in]

Pointer to a
[MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe) structure that specifies the MFE to retrieve. The information to be returned is indicated by the **dwSource** and **dwGroup** members of the
**MIB_IPMCAST_MFE** structure.

### `pdwBufferSize` [in, out]

On input, *pdwBufferSize* is a pointer to a **DWORD**-sized memory location that contains the size, in bytes, of the buffer pointed to by *pbBuffer*.

On output, if the return value is ERROR_INSUFFICIENT_BUFFER, *pdwBufferSize* receives the minimum size the buffer pointed to by *pbBuffer* must be to hold the MFE; otherwise the value of *pdwBufferSize* remains unchanged.

### `pbBuffer` [in, out]

On input, the client must supply a pointer to a buffer.

On output, *pbBuffer* contains the specified MFE. The MFE is a
[MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe) structure.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INSUFFICIENT_BUFFER** | The specified buffer is too small to hold the MFE. The client should check the value of *pdwBufferSize* for the minimum buffer size required to retrieve the MFE. |
| **ERROR_NOT_FOUND** | The specified MFE was not found. |

## See also

[MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe)

[MgmGetFirstMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetfirstmfe)

[MgmGetNextMfe](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetnextmfe)