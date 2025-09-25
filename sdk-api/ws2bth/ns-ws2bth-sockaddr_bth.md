# SOCKADDR_BTH structure

## Description

The
**SOCKADDR_BTH** structure is used in conjunction with Bluetooth socket operations, defined by address family AF_BTH.

## Members

### `addressFamily`

Address family of the socket. This member is always AF_BTH.

### `btAddr`

Address of the target Bluetooth device. When used with the
[bind](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-bind) function, must be zero or a valid local radio address. If zero, a valid local Bluetooth device address is assigned when the
[connect](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-connect) or
[accept](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-accept) function is called. When used with the **connect** function, a valid remote radio address must be specified.

### `serviceClassId`

Service Class Identifier of the socket. When used with the [bind](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-bind) function, *serviceClassId* is ignored. Also ignored if the port is specified. For the [connect](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-connect) function, specifies the unique Bluetooth service class ID of the service to which it wants to connect. If the peer device has more than one port that corresponds to the service class identifier, the **connect** function attempts to connect to the first valid service; this mechanism can be used without prior SDP queries.

### `port`

RFCOMM channel associated with the socket. See Remarks.

## Remarks

When used with the [bind](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-bind) function on client applications, the **port** member must be zero to enable an appropriate local endpoint to be assigned. When used with **bind** on server applications, the **port** member must be a valid port number or BT_PORT_ANY; ports automatically assigned using BT_PORT_ANY may be queried subsequently with a call to the [getsockname](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-getsockname) function. The valid range for requesting a specific RFCOMM port is 1 through 30.

When using the [connect](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-connect) function when **serviceClassId** is not provided, the port should directly specify the remote port number to which a **connect** operation is requested. Using the **port** member instead of the **serviceClassId** member requires the application to perform its own service (SDP) search before attempting the **connect** operation.

## See also

[Bluetooth
and bind](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-bind)

[Bluetooth
and getsockname](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-getsockname)

[Bluetooth and
accept](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-accept)

[Bluetooth and
connect](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-connect)