# PDISCONNECT_CLIENT callback function

## Description

The router manager calls the
**DisconnectClient** function when a client disconnects from an interface on which the routing protocol is running.

The [PDISCONNECT_CLIENT](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) type defines a pointer to this callback function. *DisconnectClient* is a placeholder for the application-defined function name.

## Parameters

### `InterfaceIndex` [in]

Specifies the index of the interface on which the client is connecting.

### `ClientAddress` [in]

Pointer to the address (for example, the IP address) of the connecting client.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value should be one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true: <br><br>The *InterfaceIndex* parameter is invalid, for example, no interface exists with that index. |

## See also

[ConnectClient](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pconnect_client)