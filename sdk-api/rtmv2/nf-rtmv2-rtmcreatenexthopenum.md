# RtmCreateNextHopEnum function

## Description

The
**RtmCreateNextHopEnum** enumerates the next hops in the next-hop list.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `EnumFlags` [in]

Specifies which next hops to include in the enumeration. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_ENUM_NEXT** | Enumerate next hops starting at the specified address/mask length (such as 10/8). The enumeration continues to the end of the next hop list. |
| **RTM_ENUM_RANGE** | Enumerate next hops in the specified range specified by the address/mask length (such as 10/8). |
| **RTM_ENUM_START** | Enumerate next hops starting at 0/0. Specify **NULL** for *NetAddress*. |

### `NetAddress` [in]

Pointer to an
[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address) structure that contains the starting address of the enumeration. Specify **NULL** if *EnumFlags* contains RTM_ENUM_START.

### `RtmEnumHandle` [out]

On input, *RtmEnumHandle* is a pointer to **NULL**.

On output, *RtmEnumHandle* receives a pointer to a handle to the enumeration. Use this handle in all subsequent calls to
[RtmGetEnumNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumnexthops),
[RtmReleaseNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthops), and
[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter contains incorrect information. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |

## Remarks

If *EnumFlags* contains RTM_ENUM_RANGE, use *NetAddress* to specify the range of the routing table to enumerate. For example, if a client sets *NetAddress* to 10/8, next hops in the range 10.0.0.0/8 to 10.255.255.255/32 are returned.

When the enumeration handle is no longer required, release it by calling
[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle).

## See also

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)

[RtmGetEnumNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumnexthops)

[RtmReleaseNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthops)