# IFEntry structure

## Description

[This structure may be altered or unavailable in future versions of Windows.]

Describes a TCP/IP interface in accord with
the Simple Network Management Protocol, version 2, (SNMPv2) standard for Management Information Base for network management
of TCP/IP networks (MIB-II), as specified in the Internet Engineering Task Force (IETF) Request for Comments
[(RFC) 1213](https://www.ietf.org/rfc/rfc1213.txt) on pages 16 through 23.

## Members

### `if_index`

A value between 1 and the number of network interfaces present on this system, regardless of
their current state, that uniquely identifies this interface and persists across reinitialization
of the network management system.

### `if_type`

The interface type according to
the physical or link protocol(s) immediately below the network layer in the protocol
stack. The following table lists the possible values of this **if_type**
member enumerated on pages 18 and 19 of
[RFC 1213](https://www.ietf.org/rfc/rfc1213.txt).

| Value | Meaning |
| --- | --- |
| 1 | other (that is, none of the following) |
| 2 | regular1822 |
| 3 | hdh1822 |
| 4 | ddn-x25 |
| 5 | rfc877-x25 |
| 6 | Ethernet-csmacd |
| 7 | iso88023-csmacd |
| 8 | iso88024-tokenBus |
| 9 | iso88025-tokenRing |
| 10 | iso88026-man |
| 11 | starLan |
| 12 | proteon-10Mbit |
| 13 | proteon-80Mbit |
| 14 | hyperchannel |
| 15 | fddi |
| 16 | lapb |
| 17 | sdlc |
| 18 | ds1 (T-1) |
| 19 | e1 (European equiv. of T-1) |
| 20 | basicISDN |
| 21 | primaryISDN (proprietary serial) |
| 22 | propPointToPointSerial |
| 23 | ppp |
| 24 | softwareLoopback |
| 25 | eon (CLNP over IP [11]) |
| 26 | Ethernet-3Mbit |
| 27 | nsip (XNS over IP) |
| 28 | slip (generic SLIP) |
| 29 | ultra (ULTRA technologies) |
| 30 | ds3 (T-3) |
| 31 | sip (SMDS) |
| 32 | frame-relay(32) |

Include the Ipifcons.h header file from the Microsoft SDK for flag constants supporting these and additional IP interface types.

When you examine the value of the **if_type** member, you may also want to define and test for an additional constant that identifies a "loopback" interface: `#define IF_TYPE_LOOPBACK 0`

### `if_mtu`

The size, in bytes, of the largest datagram that can be sent or received on the interface.
For interfaces that are used to transmit network datagrams, this is the size of the largest
network datagram that can be sent on the interface.

### `if_speed`

An estimate of the interface's current bandwidth, in bits per second. For interfaces that do not
vary in bandwidth or for which no accurate estimation can be made, this member contains the nominal bandwidth.

### `if_physaddrlen`

The length, in bytes, of the address contained in the **if_physaddr** member.
For interfaces such as serial ports that do not have an address of this kind, the **if_physaddrlen** member is zero.

### `if_physaddr`

The interface's address at the protocol layer immediately below the network layer in the protocol stack.
For interfaces such as serial ports that do not have an address of this kind, the **if_physaddr**
member contains an empty string.

### `if_adminstatus`

The desired state of the interface; one of the following values specified on page 20 of
[RFC 1213](https://www.ietf.org/rfc/rfc1213.txt).

| Value | Meaning |
| --- | --- |
| 1 | Up; ready to pass packets. |
| 2 | Down. |
| 3 | In a test state, such that no operational packets can be passed. |

### `if_operstatus`

The actual current operational state of the interface; one of the following values specified on page 20 of
[RFC 1213](https://www.ietf.org/rfc/rfc1213.txt).

| Value | Meaning |
| --- | --- |
| 1 | Up; ready to pass packets. |
| 2 | Down. |
| 3 | In a test state, such that no operational packets can be passed. |

### `if_lastchange`

The time, in hundredths of a second, since the network management portion of the system was last
reinitialized, at which this interface entered its actual current operational
state. If the current state was entered prior to the last reinitialization of
the local network management subsystem, this member is set to zero.

### `if_inoctets`

The total number of bytes received on this interface, including framing characters.

### `if_inucastpkts`

The number of subnetwork unicast packets delivered to a higher-layer protocol.

### `if_innucastpkts`

The number of non-unicast (subnetwork broadcast or subnetwork multicast)
packets delivered to a higher-layer protocol.

### `if_indiscards`

The number of inbound packets that have been discarded to free up memory resources
or for other similar reason not related to any error that would prevent their being
deliverable to a higher-layer protocol.

### `if_inerrors`

The number of inbound packets that have contained errors that prevent them from being
deliverable to a higher-layer protocol.

### `if_inunknownprotos`

The number of inbound packets that have been discarded because of an unknown or
unsupported protocol.

### `if_outoctets`

The total number of bytes transmitted out of the interface, including framing characters.

### `if_outucastpkts`

The total number of packets that higher-level protocols have requested be transmitted
to a subnetwork unicast address, including those that were discarded or not sent.

### `if_outnucastpkts`

The total number of packets that higher-level protocols have requested be
transmitted to a non-unicast (subnetwork broadcast or subnetwork
multicast) address, including those that were discarded or not sent.

### `if_outdiscards`

The number of outbound packets that have been discarded to free up
memory resources or for other similar reasons not related to any
error that would prevent their being transmitted.

### `if_outerrors`

The number of outbound packets that could not be transmitted because of errors.

### `if_outqlen`

The current number of packets in the output packet queue.

### `if_descrlen`

The size, in bytes, not counting any terminating null character, of the interface
description text contained in the **if_descr** member.

### `if_descr`

A text string that contains information about this interface,
including the manufacturer's name, product name, and hardware version.
If the string is not included, the size of the buffer is 1 byte.

## Remarks

Because of its variable-length **if_descr** member,
the **IFEntry** structure does not have a fixed size.
For purposes of allocating memory to contain an actual instance of the structure,
a reasonably safe buffer size can be computed as follows:

`maxIFEntryLen = sizeof(IFEntry) + MAX_ADAPTER_DESCRIPTION_LENGTH + 1;`

## See also

[IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex)

[Management Information Base
Reference](https://learn.microsoft.com/previous-versions/windows/desktop/mib/management-information-base-reference)