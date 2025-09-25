# PCONNECT_CLIENT callback function

## Description

The router manager calls the
**ConnectClient** function when a client connects to an interface on which the routing protocol is running.

The [PCONNECT_CLIENT](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) type defines a pointer to this callback function. *ConnectClient* is a placeholder for the application-defined function name.

## Parameters

### `InterfaceIndex` [in]

Specifies the index of the interface on which the client is connecting.

### `ClientAddress` [in]

Pointer to the address (such as the IP address) of the connecting client.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value should be one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true: <br><br>The *InterfaceIndex* parameter is invalid, for example, no interface exists with that index. |

## See also

[DisconnectClient](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pdisconnect_client)