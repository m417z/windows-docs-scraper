## Description

Contains the Transmission Control Protocol (TCP) statistics that were collected for a socket. Version 1.0 of this structure provides additional fields.

## Members

### `State`

Contains the Transmission Control Protocol (TCP) statistics that were collected for a socket.

### `Mss`

The current maximum segment size (MSS) for the connection, in bytes.

### `ConnectionTimeMs`

The lifetime of the connection, in milliseconds.

### `TimestampsEnabled`

**TRUE** if TCP time stamps are turned on for the connection; otherwise **FALSE**.

### `RttUs`

The current estimated round-trip time for the connection, in microseconds.

### `MinRttUs`

The minimum sampled round trip time, in microseconds.

### `BytesInFlight`

The current number of sent bytes that are unacknowledged.

### `Cwnd`

The size of the current congestion window, in bytes.

### `SndWnd`

The size of the send window (SND.WND in [RFC 793](https://tools.ietf.org/html/rfc793)), in bytes.

### `RcvWnd`

 The size of the receive window (RCV.WND in [RFC 793](https://tools.ietf.org/html/rfc793)), in bytes.

### `RcvBuf`

The size of the current receive buffer, in bytes. The size of the receive buffer changes dynamically when autotuning is turned on for the receive window.

### `BytesOut`

The total number of bytes sent.

### `BytesIn`

The total number of bytes received.

### `BytesReordered`

The total number of bytes reordered.

### `BytesRetrans`

The total number of bytes retransmitted.

### `FastRetrans`

The number of calls of the Fast Retransmit algorithm.

### `DupAcksIn`

The total number of duplicate acknowledgments received.

### `TimeoutEpisodes`

The total number of retransmission timeout episodes. Each episode can consist of multiple timeouts.

### `SynRetrans`

The total number of retransmitted synchronize control flags (SYNs).

### `SndLimTransRwin`

The number of transitions into the "Receiver Limited" state from either the "Congestion Limited" or "Sender Limited" states.

### `SndLimTimeRwin`

The cumulative time, in milliseconds, spent in the "Receiver Limited" state where TCP transmission stops because the sender has filled the announced receiver window.

### `SndLimBytesRwin`

The total number of bytes sent in the "Receiver Limited" state.

### `SndLimTransCwnd`

The number of transitions into the "Congestion Limited" state from either the "Receiver Limited" or "Sender Limited" states.

### `SndLimTimeCwnd`

The cumulative time, in milliseconds, spent in the "Congestion Limited" state. When there is a retransmission timeout, it is counted in this member and not the cumulative time for some other state.

### `SndLimBytesCwnd`

The total number of bytes sent in the "Congestion Limited" state.

### `SndLimTransSnd`

The number of transitions into the "Sender Limited" state from either the "Receiver Limited" or "Congestion Limited" states.

### `SndLimTimeSnd`

The cumulative time, in milliseconds, spent in the "Sender Limited" state.

### `SndLimBytesSnd`

The total number of bytes sent in the "Sender Limited" state.

## Remarks

To get an instance of this structure, call the
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) or [LPWSPIoctl](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566296(v=vs.85)) function with the [SIO_TCP_INFO](https://learn.microsoft.com/windows/win32/winsock/sio-tcp-info)
control code. Specify 1 for the *lpvInBuffer* field to retrieve the v1 version of this structure.

## See also

[SIO_TCP_INFO](https://learn.microsoft.com/windows/win32/winsock/sio-tcp-info)

[TCPSTATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-tcpstate)