# ICMP6_TYPE enumeration

## Description

The **ICMP6_TYPE** enumeration defines the set of Internet Control Message Protocol for IP version 6.0 (ICMPv6) message types.

## Constants

### `ICMP6_DST_UNREACH:1`

The specified destination for the message is unreachable.

### `ICMP6_PACKET_TOO_BIG:2`

The ICMPv6 packet is too large.

### `ICMP6_TIME_EXCEEDED:3`

The ICMPv6 message has timed out.

### `ICMP6_PARAM_PROB:4`

The IPv6 header is malformed or contains an incorrect value.

### `ICMP6_ECHO_REQUEST:128`

ICMPv6 echo request message.

### `ICMP6_ECHO_REPLY:129`

ICMPv6 echo reply message.

### `ICMP6_MEMBERSHIP_QUERY:130`

ICMPv6 group membership query message.

### `ICMP6_MEMBERSHIP_REPORT:131`

ICMPv6 group membership report message.

### `ICMP6_MEMBERSHIP_REDUCTION:132`

ICMPv6 group membership reduction message.

### `ND_ROUTER_SOLICIT:133`

ICMPv6 router solicitation message.

### `ND_ROUTER_ADVERT:134`

ICMPv6 router advertisement message.

### `ND_NEIGHBOR_SOLICIT:135`

ICMPv6 network neighbor solicitation message.

### `ND_NEIGHBOR_ADVERT:136`

ICMPv6 network neighbor advertisement message.

### `ND_REDIRECT:137`

ICMPv6 packet redirection message.

### `ICMP6_V2_MEMBERSHIP_REPORT:143`

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **ICMP6_TYPE** enumeration is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.