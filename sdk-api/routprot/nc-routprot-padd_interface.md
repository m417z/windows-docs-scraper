# PADD_INTERFACE callback function

## Description

The
**AddInterface** function adds an interface to be managed by the routing protocol. The protocol should consider the interface to be in a disabled state. The router manager enables the interface by calling
[InterfaceStatus](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pinterface_status) with the RIS_INTERFACE_ENABLED flag.

When a user calls [MprAdminInterfaceTransportAdd](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacetransportadd), the dynamic interface manager for the transport calls the router manager (for the transport) which calls this function for each of the routing protocols associated with that transport.

## Parameters

### `InterfaceName` [in]

Pointer to a Unicode string. The string contains a name that uniquely identifies the interface in the set of interfaces configured on the router.

### `InterfaceIndex` [in]

Specifies the interface in the set of interfaces configured on the router.

### `InterfaceType` [in]

Specifies the type of the interface.

| Value | Meaning |
| --- | --- |
| **PERMANENT** | Permanent connectivity (for example, LAN, Frame Relay). |
| **DEMAND_DIAL** | Demand dial connectivity (analog, ISDN, PPTP, switched FR). |
| **LOCAL_WORKSTATION_DIAL** | Local workstation connectivity only. |
| **REMOTE_WORKSTATION_DIAL** | Remote workstation connectivity only. |

### `MediaType` [in]

Reserved for future use.

### `AccessType` [in]

Reserved for future use.

### `ConnectionType` [in]

Reserved for future use.

### `InterfaceInfo` [in]

Pointer to a buffer that specifies protocol-defined configuration information associated with the interface. This information is private to the routing protocol.

### `StructureVersion` [in]

Specifies the version of the information structures pointed to by the *InterfaceInfo* parameter. In some cases, this is equal to the version of the routing protocol.

### `StructureSize` [in]

Specifies the size of each of the information structures pointed to by the *InterfaceInfo* parameter. Since some information structures contain variable length members, the routing protocol isn't necessarily able to determine the size of the information from the version.

### `StructureCount` [in]

Specifies a count of the number of information structures pointed to by the *InterfaceInfo* parameter. This parameter is always one.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The attempt to add the interface failed. |
| **ERROR_INVALID_PARAMETER** | The *InterfaceIndex* parameter is invalid (for example, an interface with that index already exists), or one of the parameters pointed to by *InterfaceInfo* is invalid. |

## See also

[DeleteInterface](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pdelete_interface)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)