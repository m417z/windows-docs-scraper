# PMIB_CREATE callback function

## Description

The
**MibCreate** function passes an SNMP MIB-style Create Request to the routing protocol.

## Parameters

### `InputDataSize` [in]

Specifies the size of the data for the Create Request.

### `InputData` [in]

Pointer to a buffer that specifies the data for the Create Request.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The routing protocol could not complete the request. |
| **ERROR_INVALID_PARAMETER** | Specifies the size or content of the data is inappropriate for the request. |

## See also

[MibDelete](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_delete)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)