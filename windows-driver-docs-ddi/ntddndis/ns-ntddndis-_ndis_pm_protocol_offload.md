# _NDIS_PM_PROTOCOL_OFFLOAD structure

## Description

The **NDIS_PM_PROTOCOL_OFFLOAD** structure specifies parameters for a low power protocol offload to a
network adapter.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_PM_PROTOCOL_OFFLOAD** structure. The driver sets the **Type** member to NDIS_OBJECT_TYPE_DEFAULT.

To indicate the version of the **NDIS_PM_PROTOCOL_OFFLOAD** structure, set the **Revision** member of **Header** to one of the following values:

#### NDIS_PM_PROTOCOL_OFFLOAD_REVISION_2

Added the **Dot11RSNRekeyParametersV2** structure for NDIS 6.84.

Set the **Size** member to NDIS_SIZEOF_NDIS_PM_PROTOCOL_OFFLOAD_REVISION_2.

#### NDIS_PM_PROTOCOL_OFFLOAD_REVISION_1

Original version for NDIS 6.20 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_PM_PROTOCOL_OFFLOAD_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `Priority`

A ULONG value that contains the priority of the protocol offload. If an overlying driver adds a
higher priority protocol offload when there are no resources that are available for more protocol offloads, NDIS
might remove a lower priority protocol offload to free resources. Miniport drivers should ignore this
member. Protocol drivers can provide any value within the predefined range. The following values are
predefined:

#### NDIS_PM_PROTOCOL_OFFLOAD_PRIORITY_LOWEST

Specifies the lowest priority protocol offload.

#### NDIS_PM_PROTOCOL_OFFLOAD_PRIORITY_NORMAL

Specifies a normal priority protocol offload.

#### NDIS_PM_PROTOCOL_OFFLOAD_PRIORITY_HIGHEST

Specifies the highest priority protocol offload.

### `ProtocolOffloadType`

An
[NDIS_PM_PROTOCOL_OFFLOAD_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_pm_protocol_offload_type) value that contains the type of protocol offload.

### `FriendlyName`

An
[NDIS_PM_COUNTED_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_counted_string) structure
that contains the user-readable description of the low power protocol offload.

### `ProtocolOffloadId`

A ULONG value that contains an NDIS-provided value that identifies the offloaded protocol. Before
NDIS sends the
[OID_PM_ADD_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-add-protocol-offload) OID
request down to the underlying NDIS drivers or completes the request to the overlying driver, NDIS sets
**ProtocolOffloadId** to a value that is unique among the protocol offloads on a network adapter.

### `NextProtocolOffloadOffset`

A ULONG value that contains an offset, in bytes. The
**NextProtocolOffloadOffset** member of each **NDIS_PM_PROTOCOL_OFFLOAD** structure in a list is set to
the offset (from the beginning of the OID request
InformationBuffer) of the next **NDIS_PM_PROTOCOL_OFFLOAD** structure in the list. If
**NextProtocolOffloadOffset** is zero, the current structure is the last structure in the list.

### `ProtocolOffloadParameters`

A union that contains the following member structures:

### `ProtocolOffloadParameters.IPv4ARPParameters`

A structure that contains IPv4 ARP parameters. This structure contains the following
members:

### `ProtocolOffloadParameters.IPv4ARPParameters.Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `ProtocolOffloadParameters.IPv4ARPParameters.RemoteIPv4Address`

A **UCHAR** array that contains an optional IPv4 address. This address represents the Source Protocol
Address (SPA) field of the ARP request.

If the incoming ARP request has an SPA value that matches this IPv4 address, the network adapter sends an ARP
response when it is in a low power state. If this member is zero, the network adapter should respond to ARP
requests from any remote IPv4 address.

For more information about the ARP protocol, see RFC 826.

### `ProtocolOffloadParameters.IPv4ARPParameters.HostIPv4Address`

A **UCHAR** array that contains the IPv4 address. When it sends the ARP response, the network adapter uses this
member for the SPA field of the response.

### `ProtocolOffloadParameters.IPv4ARPParameters.MacAddress`

A **UCHAR** array that contains a media access control (MAC) address. The network adapter uses this MAC address
for the Source Hardware Address (SHA) field of the ARP response packet that it generates.

**Note** When it sends an ARP response, the network adapter must always use this MAC address in the
ARP payload. However, it should use the current MAC address of the network adapter as the source address in the
MAC header.

### `ProtocolOffloadParameters.IPv6NSParameters`

A structure that contains IPv6 Neighbor Solicitation (NS) parameters. This structure contains the
following members:

### `ProtocolOffloadParameters.IPv6NSParameters.Flags`

A **ULONG** value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `ProtocolOffloadParameters.IPv6NSParameters.RemoteIPv6Address`

A **UCHAR** array that contains an optional IPv6 address. This address represents the Source Address
field in the IPv6 header of the NS message.

If the incoming NS message has a Source Address value that matches this IPv6 address, the network adapter
sends a neighbor advertisement (NA) message when it is in a low power state. If this member is zero,
the network adapter should respond to NS messages from any remote IPv6 address.

For more information about IPv6 NS and NA messages, see [RFC 4861](https://go.microsoft.com/fwlink/p/?linkid=268370).

### `ProtocolOffloadParameters.IPv6NSParameters.SolicitedNodeIPv6Address`

A **UCHAR** array that contains the solicited node IPv6 address. For more information about this
type of IPv6 address, see Multicast IPv6 Addresses.

### `ProtocolOffloadParameters.IPv6NSParameters.MacAddress`

A **UCHAR** array that contains the MAC address. When it sends the NA message, the network adapter uses this array
for the target link-layer address (TLLA) field of the NA message.

**Note** When it sends an NA message, the network adapter must always use this MAC address in the
TLLA field of the NA message. However, it should use the current MAC address of the network adapter as the source
address in the MAC header.

### `ProtocolOffloadParameters.IPv6NSParameters.TargetIPv6Addresses`

A **UCHAR** array that contains one or two IPv6 addresses. If it contains only one address, that address is stored in the first element in the array, and the second element is filled with zeros.

Miniport drivers must consume all addresses in the array.

These addresses represent the Target Address field of an NS message. If one of these addresses
matches the Target Address field of an incoming NS message, the network adapter sends an NA message in
response.

### `ProtocolOffloadParameters.Dot11RSNRekeyParameters`

A structure that contains IEEE 802.11i Robust Security Network (RSN) handshake parameters. This
structure contains the following members:

### `ProtocolOffloadParameters.Dot11RSNRekeyParameters.Flags`

A **ULONG** value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `ProtocolOffloadParameters.Dot11RSNRekeyParameters.KCK`

A **UCHAR** array that contains an IEEE 802.11 key confirmation key (KCK).

### `ProtocolOffloadParameters.Dot11RSNRekeyParameters.KEK`

A **UCHAR** array that contains an IEEE 802.11 key encryption key (KEK).

### `ProtocolOffloadParameters.Dot11RSNRekeyParameters.KeyReplayCounter`

A **ULONGLONG** value that contains a replay counter.

### `_PROTOCOL_OFFLOAD_PARAMETERS`

### `ProtocolOffloadParameters.Dot11RSNRekeyParametersV2`

A structure that contains V2 IEEE 802.11i Robust Security Network (RSN) handshake parameters. Available in NDIS 6.84 and later. This structure contains the following members:

### `ProtocolOffloadParameters.Dot11RSNRekeyParametersV2.Flags`

### `ProtocolOffloadParameters.Dot11RSNRekeyParametersV2.KeyReplayCounter`

### `ProtocolOffloadParameters.Dot11RSNRekeyParametersV2.AuthAlgo`

### `ProtocolOffloadParameters.Dot11RSNRekeyParametersV2.KCKLength`

### `ProtocolOffloadParameters.Dot11RSNRekeyParametersV2.KEKLength`

### `ProtocolOffloadParameters.Dot11RSNRekeyParametersV2.KCK`

### `ProtocolOffloadParameters.Dot11RSNRekeyParametersV2.KEK`

## Remarks

The **NDIS_PM_PROTOCOL_OFFLOAD** structure is used in the
[OID_PM_ADD_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-add-protocol-offload) and
[OID_PM_PROTOCOL_OFFLOAD_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-protocol-offload-list) OIDs.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PM_COUNTED_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_counted_string)

[NDIS_PM_PROTOCOL_OFFLOAD_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_pm_protocol_offload_type)

[OID_PM_ADD_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-add-protocol-offload)

[OID_PM_PROTOCOL_OFFLOAD_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-protocol-offload-list)