# MgmGetProtocolOnInterface function

## Description

The
**MgmGetProtocolOnInterface** function retrieves the protocol ID of the multicast routing protocol that owns the specified interface.

## Parameters

### `dwIfIndex` [in]

Specifies the index of the interface for which to retrieve the protocol ID.

### `dwIfNextHopAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

### `pdwIfProtocolId` [in, out]

On input, the client must supply a pointer to a **DWORD**-sized memory location.

On output, *pdwIfProtocolId* receives the ID of the protocol on the interface specified by *dwIfIndex*.

### `pdwIfComponentId` [in, out]

On input, the client must supply a pointer to a **DWORD** value.

On output, *pdwIfComponentId* receives the component ID for the instance of the protocol on the interface. This parameter is used with *pdwIfProtocolId* to uniquely identify an instance of a routing protocol.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_NOT_FOUND** | The specified interface was not found by the multicast group manager. |

## See also

[MgmReleaseInterfaceOwnership](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmreleaseinterfaceownership)

[MgmTakeInterfaceOwnership](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmtakeinterfaceownership)