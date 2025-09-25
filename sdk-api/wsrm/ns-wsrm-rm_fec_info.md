# RM_FEC_INFO structure

## Description

The **RM_FEC_INFO** structure specifies settings for using forward error correction (FEC) with Reliable Multicast. This structure is used with the [RM_USE_FEC](https://learn.microsoft.com/windows/desktop/WinSock/socket-options) socket option.

## Members

### `FECBlockSize`

Maximum number of packets that can be sent for any group, including original data and parity packets. Maximum and default value is 255.

### `FECProActivePackets`

Number of packets to send proactively with each group. Use this option when the network is dispersed, and upstream NAK requests would have an impact on throughput.

### `FECGroupSize`

Number of packets to be treated as one group for the purpose of computing parity packets. Group size must be a power of two. In lossy networks, keep the group size relatively small.

### `fFECOnDemandParityEnabled`

Specifies whether the sender is enabled for sending parity repair packets. When **TRUE**, receivers should only request parity repair packets.

## Remarks

The [RM_USE_FEC](https://learn.microsoft.com/windows/desktop/WinSock/socket-options) socket option notifies the Reliable Multicast sender to apply forward error correction techniques to send repair data. there are three modes of using forward error correction:

1. Pro-active parity packets only
2. OnDemand parity packets only
3. Both pro-active and OnDemand parity packets

Since the use of this structure implies the need for forward error correction, either the **FECProActivePackets** or **fFECOnDemandParityEnabled** member must be nonzero, otherwise the function call fails.

## See also

[RM_USE_FEC](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)

[Reliable Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/reliable-multicast-programming--pgm-)

[Socket
Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)