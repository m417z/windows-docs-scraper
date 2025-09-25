# PMIB_SET callback function

## Description

The
**MibSet** function passes a SNMP MIB-style Set Request to the routing protocol.

## Parameters

### `InputDataSize` [in]

Specifies the size of the data for the Set Request.

### `InputData` [in]

Pointer to a buffer that specifies the data for the Set Request.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The routing protocol could not complete the request. |
| **ERROR_INVALID_PARAMETER** | The size or content of the data is inappropriate for the request. |

## See also

[MibGet](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_get)

[MibGetFirst](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_get_first)

[MibGetNext](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_get_next)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)