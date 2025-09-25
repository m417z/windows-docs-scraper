# PSET_INTERFACE_INFO callback function

## Description

The
**SetInterfaceInfo** function sets the configuration of a specific interface managed by the routing protocol.

## Parameters

### `InterfaceIndex` [in]

Specifies the interface in the set of interfaces configured on the router.

### `InterfaceInfo` [in]

Pointer to a buffer that holds the protocol-defined configuration information associated with the interface. This information is private to the routing protocol.

### `StructureVersion` [in]

Specifies the version of the information structures pointed to by the *InterfaceInfo* parameter. In some cases, this is equal to the version of the routing protocol.

### `StructureSize` [in]

Specifies the size of each of the information structures pointed to by the *InterfaceInfo* parameter. Since some information structures contain variable length members, the routing protocol is not necessarily able to determine the size of the information from the version.

### `StructureCount` [in]

Specifies a count of the number of information structures pointed to by the *InterfaceInfo* parameter. This parameter is always one.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The attempt to set the interface configuration failed. |
| **ERROR_INVALID_PARAMETER** | The *InterfaceIndex* parameter is invalid (for example, no interface exists with that index), the *InterfaceInfo* parameter is **NULL**, or one of the parameters in the configuration information is invalid. |

## See also

[GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_interface_info)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)