# PMIB_GET callback function

## Description

The
**MibGet** function passes an SNMP MIB-style Get Request to the routing protocol DLL.

## Parameters

### `InputDataSize` [in]

Specifies the size of the data for the Get Request.

### `InputData` [in]

Pointer to a buffer that specifies the data for the Get Request.

### `OutputDataSize` [out]

Pointer to a **ULONG** variable:

On input: This variable contains the size of the output buffer.

On output: This variable contains the size of the data placed in the output buffer. If the initial size was not large enough, the variable contains the buffer size required to hold all of the output data.

### `OutputData` [out]

Pointer to a buffer that receives the data from the MIB entry.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The routing protocol could not complete the request. |
| **ERROR_INVALID_PARAMETER** | The size or content of the data is inappropriate for the request. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the output buffer provided is not large enough to hold the requested information. The required size is returned in the **ULONG** variable pointed to by the *OutputDataSize* parameter. |

## See also

[MibGetFirst](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_get_first)

[MibGetNext](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_get_next)

[MibSet](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_set)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)