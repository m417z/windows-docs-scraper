# RtmCreateDestEnum function

## Description

The
**RtmCreateDestEnum** function starts an enumeration of the destinations in the routing table. A client can enumerate destinations for one or more views, or for all views.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `TargetViews` [in]

Specifies the set of views to use when creating the enumeration. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_VIEW_MASK_ANY** | Return destinations from all views. This is the default value. |
| **RTM_VIEW_MASK_UCAST** | Return destinations from the unicast view. |
| **RTM_VIEW_MASK_MCAST** | Return destinations from the multicast view. |

### `EnumFlags` [in]

Specifies which destinations to include in the enumeration. Two sets of flags are used; use one flag from each set (for example, use RTM_ENUM_ALL_DESTS and RTM_ENUM_START).

| Constant | Meaning |
| --- | --- |
| **RTM_ENUM_ALL_DESTS** | Return all destinations. |
| **RTM_ENUM_OWN_DESTS** | Return destinations for which the client owns the best route to a destination in any of the specified views. |

| Constant | Meaning |
| --- | --- |
| **RTM_ENUM_NEXT** | Enumerate destinations starting at the specified address/mask length (such as 10/8). The enumeration continues to the end of the routing table. |
| **RTM_ENUM_RANGE** | Enumerate destinations in the range specified by the address/mask length (such as 10/8). |
| **RTM_ENUM_START** | Enumerate destinations starting at 0/0. Specify **NULL** for *NetAddress*. |

### `NetAddress` [in]

Pointer to an
[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address) structure that contains the starting address of the enumeration. Specify **NULL** if *EnumFlags* contains RTM_ENUM_START.

### `ProtocolId` [in]

Specifies the protocol identifier used to determine the best route information returned by the
[RtmGetEnumDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumdests) function. The *ProtocolID* is not part of the search criteria. The routing table manager uses this identifier to determine which route information to return (for example, if a client specifies the RIP protocol identifier, the best RIP route is returned, even if a non-RIP route is the best route to the destination).

Specify RTM_BEST_PROTOCOL to return a route regardless of which protocol owns it. Specify RTM_THIS_PROTOCOL to return the best route for the calling protocol.

### `RtmEnumHandle` [out]

On input, *RtmEnumHandle* is a pointer to **NULL**.

On output, *RtmEnumHandle* receives a pointer to a handle to the enumeration. Use this handle in all subsequent calls to
[RtmGetEnumDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumdests),
[RtmReleaseDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasedests), and
[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter contains incorrect information. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |
| **ERROR_NOT_SUPPORTED** | One or more of the specified views is not supported. |

## Remarks

If *EnumFlags* contains RTM_ENUM_RANGE, use *NetAddress* to specify the range of the routing table to enumerate. For example, if a client sets *NetAddress* to 10/8, destinations in the range 10.0.0.0/8 to 10.255.255.255/32 are returned.

When the enumeration handle is no longer required, release it by calling
[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle).

For sample code using this function, see
[Enumerate All Destinations](https://learn.microsoft.com/windows/desktop/RRAS/enumerate-all-destinations).

## See also

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)

[RtmGetEnumDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumdests)

[RtmReleaseDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasedests)