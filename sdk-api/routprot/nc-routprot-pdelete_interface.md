# PDELETE_INTERFACE callback function

## Description

The
**DeleteInterface** function removes an interface from the set managed by the routing protocol.

## Parameters

### `InterfaceIndex` [in]

Specifies the interface in the set of interfaces configured on the router.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The attempt to delete the interface failed. |
| **ERROR_INVALID_PARAMETER** | The *InterfaceIndex* parameter is invalid (for example, no interface exists with that index). |

## See also

[AddInterface](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-padd_interface)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)