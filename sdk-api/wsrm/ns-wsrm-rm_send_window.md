# RM_SEND_WINDOW structure

## Description

The **RM_SEND_WINDOW** structure specifies the Reliable Multicast send window. This structure is used with the [RM_RATE_WINDOW_SIZE](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-rm-socket-options) socket option.

## Members

### `RateKbitsPerSec`

Transmission rate for the send window, in kilobits per second.

### `WindowSizeInMSecs`

Window size for the send window, in milliseconds.

### `WindowSizeInBytes`

Window size for the session, in bytes.

## Remarks

Any combination of the three available members may be set for a given socket option call. For example, one, any two, or all three members may be specified during a [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function call. Regardless of settings, Windows enforces the following ratio: **TransmissionRate** == (**WindowSizeBytes**/**WindowSizeMSecs**) * 8. As such, setting any two parameters effectively sets the third to ensure optimum performance.

The combination of these members can affect the resources used on a PGM sender's computer. For example, a large transmission rate value combined with a large window size results in more required buffer space.

## See also

[IPPROTO_RM Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-rm-socket-options)

[Reliable Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/reliable-multicast-programming--pgm-)

[Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)