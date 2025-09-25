# MgmTakeInterfaceOwnership function

## Description

The
**MgmTakeInterfaceOwnership** function is called by a client (such as a routing protocol) when it is enabled on an interface.

Only one client can take ownership of a given interface at any time. The only exception to this rule is the IGMP. IGMP can coexist with another client on an interface.

## Parameters

### `hProtocol` [in]

Handle to the protocol obtained from a previous call to
[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol).

### `dwIfIndex` [in]

Specifies the index of the interface of which to take ownership.

### `dwIfNextHopAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ALREADY_EXISTS** | The specified interface is already owned by another routing protocol. |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INVALID_PARAMETER** | Invalid handle to a client. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory to complete this operation. |

## Remarks

A client must take ownership of an interface only after registering itself with the multicast group manager, but before it adds group membership entries.

## See also

[MgmGetProtocolOnInterface](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgetprotocoloninterface)

[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol)

[MgmReleaseInterfaceOwnership](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmreleaseinterfaceownership)