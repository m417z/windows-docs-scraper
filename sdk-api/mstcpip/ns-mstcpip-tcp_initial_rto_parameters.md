## Description

Specifies data used by the [SIO_TCP_INITIAL_RTO](https://learn.microsoft.com/windows/win32/winsock/sio-tcp-initial-rto) IOCTL to configure initial retransmission timeout (RTO) parameters to be used on the socket. The Windows TCP/IP stack will honor the values in this struct's members for subsequent connection attempts.

## Members

### `Rtt`

Supplies the initial round trip time (RTT) estimate in milliseconds. This value is used to compute the retransmission timeout.

### `MaxSynRetransmissions`

Supplies the maximum number of retransmissions that will be attempted before the connection setup fails. The retransmission behavior for TCP is documented in IETF RFC 793 and 2988.

* Use one of the *unspecified* defines **TCP_INITIAL_RTO_UNSPECIFIED_RTT** and **TCP_INITIAL_RTO_UNSPECIFIED_MAX_SYN_RETRANSMISSIONS** to allow the system to pick up administrator-configured settings for the parameter left unspecified.
* You can choose system defaults for any of these fields, and supply those values using the default defines **TCP_INITIAL_RTO_DEFAULT_RTT** and **TCP_INITIAL_RTO_DEFAULT_MAX_SYN_RETRANSMISSIONS**.
* You can use the define **TCP_INITIAL_RTO_NO_SYN_RETRANSMISSIONS** to set the number of SYN retransmissions for a TCP socket to 0 (in other words, the TCP SYN shouldn't be retransmitted).

## Remarks

## See also

[SIO_TCP_INITIAL_RTO](https://learn.microsoft.com/windows/win32/winsock/sio-tcp-initial-rto)