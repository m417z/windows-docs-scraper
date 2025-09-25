# RAS_PORT_1 structure

## Description

The
**RAS_PORT_1** structure contains detailed information regarding a specific RAS port, such as line speed or errors. For more general information about a port, such as port condition or port name, see
[RAS_PORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_0).

## Members

### `hPort`

Handle to the port.

### `hConnection`

Handle to the connection.

### `dwHardwareCondition`

Specifies a
[RAS_HARDWARE_CONDITION](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-ras_hardware_condition) structure.

### `dwLineSpeed`

Specifies the line speed of the port, represented in bits per second.

### `dwBytesXmited`

Specifies the bytes transmitted on the port. This value is the number of bytes of compressed data.

### `dwBytesRcved`

Specifies the bytes received on the port. This value is the number of bytes of compressed data.

### `dwFramesXmited`

Specifies the frames transmitted on the port.

### `dwFramesRcved`

Specifies the frames received on the port.

### `dwCrcErr`

Specifies the CRC errors on the port.

### `dwTimeoutErr`

Specifies the time-out errors on the port.

### `dwAlignmentErr`

Specifies the alignment errors on the port.

### `dwHardwareOverrunErr`

Specifies the hardware overrun errors on the port.

### `dwFramingErr`

Specifies the framing errors on the port.

### `dwBufferOverrunErr`

Specifies the buffer overrun errors on the port.

### `dwCompressionRatioIn`

Specifies a percentage that indicates the degree to which data received on this connection is compressed. The ratio is the size of the compressed data divided by the size of the same data in an uncompressed state.

### `dwCompressionRatioOut`

Specifies a percentage indicating the degree to which data transmitted on this connection is compressed. The ratio is the size of the compressed data divided by the size of the same data in an uncompressed state.

## See also

[RAS
Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[RAS_HARDWARE_CONDITION](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-ras_hardware_condition)

[RAS_PORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_0)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)