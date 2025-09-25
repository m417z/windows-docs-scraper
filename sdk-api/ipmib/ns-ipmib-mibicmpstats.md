# MIBICMPSTATS structure

## Description

The
**MIBICMPSTATS** structure contains statistics for either incoming or outgoing Internet Control Message Protocol (ICMP) messages on a particular computer.

## Members

### `dwMsgs`

Type: **DWORD**

The number of messages received or sent.

### `dwErrors`

Type: **DWORD**

The number of errors received or sent.

### `dwDestUnreachs`

Type: **DWORD**

The number of destination-unreachable messages received or sent. A destination-unreachable message is sent to the originating computer when a datagram fails to reach its intended destination.

### `dwTimeExcds`

Type: **DWORD**

The number of time-to-live (TTL) exceeded messages received or sent. A time-to-live exceeded message is sent to the originating computer when a datagram is discarded because the number of routers it has passed through exceeds its time-to-live value.

### `dwParmProbs`

Type: **DWORD**

The number of parameter-problem messages received or sent. A parameter-problem message is sent to the originating computer when a router or host detects an error in a datagram's IP header.

### `dwSrcQuenchs`

Type: **DWORD**

The number of source quench messages received or sent. A source quench request is sent to a computer to request that it reduce its rate of packet transmission.

### `dwRedirects`

Type: **DWORD**

The number of redirect messages received or sent. A redirect message is sent to the originating computer when a better route is discovered for a datagram sent by that computer.

### `dwEchos`

Type: **DWORD**

The number of echo requests received or sent. An echo request causes the receiving computer to send an echo reply message back to the originating computer.

### `dwEchoReps`

Type: **DWORD**

The number of echo replies received or sent. A computer sends an echo reply in response to receiving an echo request message.

### `dwTimestamps`

Type: **DWORD**

The number of time-stamp requests received or sent. A time-stamp request causes the receiving computer to send a time-stamp reply back to the originating computer.

### `dwTimestampReps`

Type: **DWORD**

The number of time-stamp replies received or sent. A computer sends a time-stamp reply in response to receiving a time-stamp request. Routers can use time-stamp requests and replies to measure the transmission speed of datagrams on a network.

### `dwAddrMasks`

Type: **DWORD**

The number of address mask requests received or sent. A computer sends an address mask request to determine the number of bits in the subnet mask for its local subnet.

### `dwAddrMaskReps`

Type: **DWORD**

The number of address mask responses received or sent. A computer sends an address mask response in response to an address mask request.

## Remarks

Two
**MIBICMPSTATS** structures are required to hold all the ICMP statistics for a given computer. One
**MIBICMPSTATS** structure contains the statistics for incoming ICMP messages. The other contains the statistics for outgoing ICMP messages. For this reason, the
[MIBICMPINFO](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpinfo) structure contains two
**MIBICMPSTATS** structures.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIBICMPSTATS** structure is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIBICMPINFO](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpinfo)

[MIBICMPSTATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats_ex_xpsp1)

[MIB_ICMP](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp)

[MIB_ICMP_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp_ex_xpsp1)