# RAS_STATS structure

## Description

The
**RAS_STATS** structure stores the statistics for a single-link RAS connection, or for one of the links in a multilink RAS connection.

## Members

### `dwSize`

Specifies the version of the structure. Set this member to sizeof(**RAS_STATS**) before using the structure in a function call.

### `dwBytesXmited`

The number of bytes transmitted through this connection or link.

### `dwBytesRcved`

The number of bytes received through this connection or link.

### `dwFramesXmited`

The number frames transmitted through this connection or link.

### `dwFramesRcved`

The number of frames received through this connection or link.

### `dwCrcErr`

The number of cyclic redundancy check (CRC) errors on this connection or link.

### `dwTimeoutErr`

The number of timeout errors on this connection or link.

### `dwAlignmentErr`

The number of alignment errors on this connection or link.

### `dwHardwareOverrunErr`

The number of hardware overrun errors on this connection or link.

### `dwFramingErr`

The number of framing errors on this connection or link.

### `dwBufferOverrunErr`

The number of buffer overrun errors on this connection or link.

### `dwCompressionRatioIn`

The compression ratio for the data being received on this connection or link.

**Note** This element is only valid for a single link connection or a single link in a multilink connection.

### `dwCompressionRatioOut`

The compression ratio for the data being transmitted on this connection or link.

**Note** This element is only valid for a single link connection or a single link in a multilink connection.

### `dwBps`

The speed of the connection or link, in bits per second.

For a single-link connection and for individual links in a multilink connection, this speed is negotiated at the time the connection or link is established.

For multilink connections, this speed is equal to the sum of the speeds of the individual links. For multilink connections, this speed varies as links are added or deleted.

This speed is not equal to the throughput of the connection or link. To calculate the average throughput, divide the number of bytes transmitted (**dwBytesXmited**) and received (**dwBytesRcved**) by the amount of time the connection or link has been up (**dwConnectDuration**).

### `dwConnectDuration`

The amount of time, in milliseconds, that the connection or link has been connected.

## See also

[RasClearConnectionStatistics](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasclearconnectionstatistics)

[RasClearLinkStatistics](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasclearlinkstatistics)

[RasGetConnectionStatistics](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectionstatistics)

[RasGetLinkStatistics](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetlinkstatistics)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Structures](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-structures)