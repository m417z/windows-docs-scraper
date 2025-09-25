# ICMP4_TYPE enumeration

## Description

The **ICMP4_TYPE** enumeration defines the set of Internet Control Message Protocol (ICMP) for IP version 4.0 (IPv4) message types.

## Constants

### `ICMP4_ECHO_REPLY:0`

ICMP echo reply message.

### `ICMP4_DST_UNREACH:3`

The specified destination for the message is unreachable.

### `ICMP4_SOURCE_QUENCH:4`

ICMP source quench message.

### `ICMP4_REDIRECT:5`

ICMP redirection message.

### `ICMP4_ECHO_REQUEST:8`

ICMP echo redirection message.

### `ICMP4_ROUTER_ADVERT:9`

ICMP router advertisement message.

### `ICMP4_ROUTER_SOLICIT:10`

ICMP router solicitation message.

### `ICMP4_TIME_EXCEEDED:11`

The ICMPv6 message has timed out.

### `ICMP4_PARAM_PROB:12`

The IPv4 header is malformed or contains an incorrect value.

### `ICMP4_TIMESTAMP_REQUEST:13`

ICMP timestamp request message.

### `ICMP4_TIMESTAMP_REPLY:14`

ICMP timestamp reply message.

### `ICMP4_MASK_REQUEST:17`

ICMP mask request message.

### `ICMP4_MASK_REPLY:18`

ICMP mask reply message.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **ICMP4_TYPE** enumeration is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.