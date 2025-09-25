# MgmReleaseInterfaceOwnership function

## Description

The
**MgmReleaseInterfaceOwnership** function is used by a client to relinquish ownership of an interface. When this function is called, all MFEs maintained by the multicast group manager on behalf of the client and for the specified interface are deleted.

## Parameters

### `hProtocol` [in]

Handle to the protocol obtained from a previous call to
[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol).

### `dwIfIndex` [in]

Specifies the index of the interface to release.

### `dwIfNextHopAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes:

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INVALID_PARAMETER** | Invalid handle to a client, or the interface was not found. |

## Remarks

A client must release ownership of all the interfaces it owns before deregistering itself with the
[MgmDeRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmderegistermprotocol) function.

## See also

[MgmDeRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmderegistermprotocol)

[MgmTakeInterfaceOwnership](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmtakeinterfaceownership)