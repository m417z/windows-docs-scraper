# PGET_INTERFACE_INFO callback function

## Description

The
**GetInterfaceInfo** function gets the configuration information kept by the routing protocol for a specific interface.

## Parameters

### `InterfaceIndex` [in]

Specifies the interface in the set of interfaces configured on the router.

### `InterfaceInfo` [in]

Pointer to a buffer that receives the protocol-defined configuration information associated with the interface. This information is private to the routing protocol.

### `BufferSize` [in, out]

Pointer to a **DWORD** variable.

On input: This variable specifies the size, in bytes, of the buffer provided to receive the configuration information.

On output: This variable receives the size, in bytes, of the data placed in the buffer. If the initial size was not large enough, this variable contains the size required to hold all of the data.

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
| **ERROR_CAN_NOT_COMPLETE** | The attempt to retrieve the information failed. |
| **ERROR_INVALID_PARAMETER** | The *InterfaceIndex* parameter is invalid (for example, no interface exists with that index), or the *InterfaceInfoSize* parameter is **NULL**. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the output buffer provided is not large enough to hold the requested information. The required size is returned in the **DWORD** variable pointed to by *InterfaceInfoSize*. |

## See also

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)

[SetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_interface_info)