# IPSNMPInfo structure

## Description

[This structure may be altered or unavailable in future versions of Windows.]

Implements part of the Management Information Base (MIB-II)
information group for the Internet Protocol (IP) as specified in the
Internet Engineering Task Force (IETF) Request for Comments [(RFC) 2011](https://www.ietf.org/rfc/rfc2011.txt).

## Members

### `ipsi_forwarding`

Indicates whether this entity is acting as an IP router that forwards datagrams
not addressed to it. IP routers forward datagrams but IP hosts do not, except for datagrams
source-routed through the host.

### `ipsi_defaultttl`

The default value for the Time-To-Live (TTL) field of the IP header of datagrams
that originate at this entity, inserted whenever the transport layer protocol
does not supply a TTL value.

### `ipsi_inreceives`

The total number of input datagrams received from interfaces by this
entity, including those received in error.

### `ipsi_inhdrerrors`

The number of input datagrams discarded because of errors in their IP headers. Such errors include bad
checksums, version-number mismatch, other format errors, time-to-live
exceeded and errors discovered in processing the IP options, but not including invalid destination addresses.

### `ipsi_inaddrerrors`

The number of input datagrams discarded because the IP address in the
destination field of their IP header was not valid for this entity. This includes
invalid addresses such as 0.0.0.0, addresses of unsupported Classes
such as Class E, and, for entities that are not IP router datagrams, includes
all addresses that are not local.

### `ipsi_forwdatagrams`

The number of input datagrams for which this entity was not their final IP
destination, so that an attempt was made to forward them. In entities that do
not act as IP routers, this counter includes only those packets that are
successfully source-routed through this entity.

### `ipsi_inunknownprotos`

The number of locally-addressed datagrams received successfully but discarded
because of an unknown or unsupported protocol.

### `ipsi_indiscards`

The number of input IP datagrams that contained nothing to prevent their
continued processing, but were discarded for run-time reasons, such as lack
of available memory or other resources. Note that this counter does not include
any datagrams discarded while awaiting reassembly.

### `ipsi_indelivers`

The total number of input datagrams successfully delivered to IP user protocols,
including ICMP.

### `ipsi_outrequests`

The total number of IP datagrams that local IP user protocols, including ICMP,
supplied to IP in requests for transmission. Note that this counter does not
include any datagrams counted in the **ipsi_forwdatagrams** member.

### `ipsi_routingdiscards`

The number of valid routing entries that were discarded for reasons such as the need
to free up memory.

### `ipsi_outdiscards`

The number of output IP datagrams for which no problem was encountered to
prevent their transmission, but that were discarded for run-time reasons such as
lack of memory or other resources. Note that this counter includes datagrams
also counted in the **ipsi_forwdatagrams** member if any
such packets were discarded in this way.

### `ipsi_outnoroutes`

The number of IP datagrams discarded because no route could be found to transmit
them to their destination. This value includes packets also counted in the
**ipsi_forwdatagrams** member that cannot be routed, and
datagrams that a host cannot route because its default routers are all down.

### `ipsi_reasmtimeout`

The maximum number of seconds that this entity holds received fragments that are
awaiting reassembly before discarding them.

### `ipsi_reasmreqds`

The number of IP fragments received at this entity that needed to be reassembled.

### `ipsi_reasmoks`

The number of IP datagrams that have been successfully reassembled at this entity.

### `ipsi_reasmfails`

The number of reassembly failures of any sort detected by the IP reassembly
algorithm. Note that this is not necessarily a count of discarded IP fragments,
because some algorithms such as that described in [RFC 815](https://www.ietf.org/rfc/rfc815.txt) do not keep track of
the number of fragments being combined.

### `ipsi_fragoks`

The number of IP datagrams that have been successfully fragmented at this entity.

### `ipsi_fragfails`

The number of IP datagrams that have been discarded because they needed to be
fragmented at this entity but could not be, because their "Don't Fragment"
flag was set or for some other reason.

### `ipsi_fragcreates`

The number of IP datagram fragments that have been generated as a result of
fragmentation at this entity.

### `ipsi_numif`

The number of interfaces on which this entity listens.

### `ipsi_numaddr`

The number of IP addresses for which this entity listens.

### `ipsi_numroutes`

The number of routes in this entity's route table.

## See also

[IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex)

[Management Information Base
Reference](https://learn.microsoft.com/previous-versions/windows/desktop/mib/management-information-base-reference)