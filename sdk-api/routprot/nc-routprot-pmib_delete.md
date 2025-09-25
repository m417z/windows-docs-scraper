# PMIB_DELETE callback function

## Description

The
**MibDelete** function passes an SNMP MIB-style Delete Request to the routing protocol.

## Parameters

### `InputDataSize` [in]

Specifies the size of the data for the Delete Request.

### `InputData` [in]

Pointer to a buffer that specifies the data for the Delete Request.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The routing protocol could not complete the request. |
| **ERROR_INVALID_PARAMETER** | The size or content of the data is inappropriate for the request. |

## See also

[MibCreate](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_create)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)