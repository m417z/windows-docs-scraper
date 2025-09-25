# MgmSetMfe function

## Description

The
**MgmSetMfe** function changes the upstream neighbor for an MFE. An MFE contains the information about which interface is receiving and which interfaces are forwarding multicast data.

## Parameters

### `hProtocol` [in]

Handle to the protocol obtained from a previous call to
[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol).

### `pmimm` [in]

Pointer to a
[MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe) structure that specifies the MFE to change. Specify the new neighbor in the **dwUpstreamNeighbor** member.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INVALID_PARAMETER** | Invalid handle to a client. |
| **ERROR_NOT_FOUND** | The specified MFE was not found. |

## See also

[MIB_IPMCAST_MFE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe)