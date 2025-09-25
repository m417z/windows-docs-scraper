# PGET_NEIGHBORS callback function

## Description

The router manager calls the
*GetNeighbors* function to obtain the querier for the network attached through the specified interface.

The [PGET_NEIGHBORS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) type defines a pointer to this callback function. *GetNeighbors* is a placeholder for the application-defined function name.

## Parameters

### `InterfaceIndex` [in]

Specifies the index of the interface on which the routing protocol should provide the querier.

### `NeighborList` [in]

Pointer to an array **DWORD** variables. The routing protocol should fill in this array with the address of the querier.

If the local computer is the querier for the network attached through the specified interface, the routing protocol need not fill in this variable. Instead, the routing protocol should set the value pointed to by *NeighborListSize* to zero. Also, the routing protocol should add **MRINFO_QUERIER_FLAG** to the flags returned in the *InterfaceFlags* parameter.

### `NeighborListSize` [in, out]

On input, pointer to a **DWORD** variable.

On output, the routing protocol fills this variable with the length, in bytes, of the address returned in the *NeighborList* parameter.

### `InterfaceFlags` [out]

Receives one or more of the following flags. The flags describe the relationship of the local computer to other computers on the network attached through the specified interface.

**MRINFO_TUNNEL_FLAG**
**MRINFO_PIM_FLAG**
**MRINFO_DOWN_FLAG**
**MRINFO_DISABLED_FLAG**
**MRINFO_QUERIER_FLAG**
**MRINFO_LEAF_FLAG**

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The routing protocol could not complete the request. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the buffer pointed to by *NeighborList* is not large enough to hold the address. The required size is returned in the **DWORD** variable pointed to by the *NeighborListSize* parameter. |
| **ERROR_INVALID_PARAMETER** | The *InterfaceIndex* parameter is invalid (for example, no interface exists with that index). |

## Remarks

Only multicast routing protocols are required implement this function. Non-multicast routing protocols should pass **NULL** as the pointer value for this function in
[MPR_ROUTING_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics)

## See also

[GetMfeStatus](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_mfe_status)