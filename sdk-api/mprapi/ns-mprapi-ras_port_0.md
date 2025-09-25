# RAS_PORT_0 structure

## Description

The
**RAS_PORT_0** structure contains general information regarding a specific RAS port, such as port condition and port name. For more detailed information about a specific port, such as line speed or errors, see
[RAS_PORT_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_1).

## Members

### `hPort`

Handle to the port.

### `hConnection`

Handle to the connection.

### `dwPortCondition`

[RAS_PORT_CONDITION](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-ras_port_condition) structure.

### `dwTotalNumberOfCalls`

Specifies the cumulative number of calls this port has serviced.

### `dwConnectDuration`

Specifies the duration of the current connection, in seconds.

### `wszPortName`

Specifies the port name.

### `wszMediaName`

Specifies the media name.

### `wszDeviceName`

Specifies the device name.

### `wszDeviceType`

Specifies the device type.

## See also

[RAS
Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[RAS_PORT_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_1)

[RAS_PORT_CONDITION](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-ras_port_condition)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)