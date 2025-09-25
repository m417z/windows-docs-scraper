# PSET_GLOBAL_INFO callback function

## Description

The
**SetGlobalInfo** function sets the global (as opposed to interface-specific) configuration information kept by the routing protocol. The format of this information is specific to the routing protocol.

## Parameters

### `GlobalInfo` [in]

Pointer to a buffer that specifies the protocol-defined global configuration information.

### `StructureVersion`

### `StructureSize`

### `StructureCount`

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The routing protocol could not set the configuration information. |
| **ERROR_INVALID_PARAMETER** | The *GlobalInfo* parameter is **NULL**, or one of the parameters in the configuration information is invalid. |

## See also

[GetGlobalInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_global_info)

[GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_interface_info)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)