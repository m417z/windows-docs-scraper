# PGET_GLOBAL_INFO callback function

## Description

The
**GetGlobalInfo** function retrieves global (as opposed to interface-specific) configuration information kept by the routing protocol.

## Parameters

### `GlobalInfo` [in]

Pointer to a buffer to receive the protocol-defined global configuration information. The format of this information is specific to the routing protocol.

### `BufferSize`

### `StructureVersion`

### `StructureSize`

### `StructureCount`

#### - GlobalInfoSize [in, out]

Pointer to a **DWORD** variable.

On input this variable specifies the size, in bytes, of the buffer pointed to by the *GlobalInfo* parameter.

On output this variable receives the size, in bytes, of the data placed in the output buffer. If the initial size was not large enough, the variable contains the size required to hold all of the output data.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The routing protocol could not retrieve the global information. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the output buffer provided is not large enough to hold the requested information. The required size is returned in the **DWORD** variable pointed to by *OutputDataSize*. |
| **ERROR_INVALID_PARAMETER** | The *GlobalInfoSize* parameter is **NULL**. |

## See also

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)

[SetGlobalInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_global_info)

[SetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_interface_info)