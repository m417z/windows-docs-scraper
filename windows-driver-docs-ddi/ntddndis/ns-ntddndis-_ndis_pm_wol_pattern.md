# _NDIS_PM_WOL_PATTERN structure

## Description

The **NDIS_PM_WOL_PATTERN** structure defines a wake-on-LAN (WOL) pattern.

## Members

### `Header`

The type, revision, and size of the **NDIS_PM_WOL_PATTERN** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_PM_WOL_PATTERN** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_PM_WOL_PATTERN_REVISION_2

Revisions made to the [NDIS_PM_WOL_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_pm_wol_packet) enumeration for NDIS 6.30.

Set the **Size** member to NDIS_SIZEOF_NDIS_PM_WOL_PATTERN_REVISION_2.

#### NDIS_PM_WOL_PATTERN_REVISION_1

Original version for NDIS 6.20.

Set the **Size** member to NDIS_SIZEOF_NDIS_PM_WOL_PATTERN_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `Priority`

A ULONG value that contains the priority of the WOL pattern. If an overlying driver adds a higher
priority WOL pattern when there are no resources that are available for more WOL patterns, NDIS might remove a
lower priority WOL pattern to free resources. Miniport drivers should ignore this member. A protocol
driver can specify any priority that is within the predefined range. The following values are
predefined:

#### NDIS_PM_WOL_PRIORITY_LOWEST

Specifies the lowest priority WOL pattern.

#### NDIS_PM_WOL_PRIORITY_NORMAL

Specifies a normal priority WOL pattern.

#### NDIS_PM_WOL_PRIORITY_HIGHEST

Specifies the highest priority WOL pattern.

### `WoLPacketType`

An
[NDIS_PM_WOL_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_pm_wol_packet) enumeration value that
specifies the type of the WOL packet.

### `FriendlyName`

An
[NDIS_PM_COUNTED_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_counted_string) structure
that contains the user-readable description of the WOL packet.

### `PatternId`

A ULONG value that contains an NDIS-provided value that identifies the WOL pattern. Before NDIS
sends the
[OID_PM_ADD_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-add-wol-pattern) OID request down
to the underlying NDIS drivers or completes the request to the overlying driver, NDIS sets
**PatternId** to a value that is unique among the WOL patterns on a network adapter.

### `NextWoLPatternOffset`

A ULONG value that contains an offset, in bytes. The
**NextWoLPatternOffset** member of each NDIS_PM_WOL_PATTERN structure in a list is set to the offset
(from the beginning of the OID request
**InformationBuffer**) of the next NDIS_PM_WOL_PATTERN structure in the list. If
**NextWoLPatternOffset** is zero, the current structure is the last structure in the list.

### `WoLPattern`

A union that contains the following member structures.

### `WoLPattern.IPv4TcpSynParameters`

A structure that contains IPv4 TCP SYN information. This structure contains the following
members:

### `WoLPattern.IPv4TcpSynParameters.Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `WoLPattern.IPv4TcpSynParameters.IPv4SourceAddress`

The IPv4 source address in the TCP SYN packet.

### `WoLPattern.IPv4TcpSynParameters.IPv4DestAddress`

The IPv4 destination address in the TCP SYN packet.

### `WoLPattern.IPv4TcpSynParameters.TCPSourcePortNumber`

The TCP source port number in the TCP SYN packet.

### `WoLPattern.IPv4TcpSynParameters.TCPDestPortNumber`

The TCP destination port number in the TCP SYN packet.

### `WoLPattern.IPv6TcpSynParameters`

A structure that contains IPv6 TCP SYN information. This structure contains the following
members:

### `WoLPattern.IPv6TcpSynParameters.Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `WoLPattern.IPv6TcpSynParameters.IPv6SourceAddress`

The IPv6 source address in the TCP SYN packet.

### `WoLPattern.IPv6TcpSynParameters.IPv6DestAddress`

The IPv6 destination address in the TCP SYN packet.

### `WoLPattern.IPv6TcpSynParameters.TCPSourcePortNumber`

The TCP source port in the TCP SYN packet.

### `WoLPattern.IPv6TcpSynParameters.TCPDestPortNumber`

The TCP destination port in the TCP SYN packet.

### `WoLPattern.EapolRequestIdMessageParameters`

A structure that contains 802.1X EAPOL request identity message parameters. This structure
contains the following members:

### `WoLPattern.EapolRequestIdMessageParameters.Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `WoLPattern.WoLBitMapPattern`

A structure that specifies a WOL bitmap pattern. For more information about bitmap patterns, see
the Remarks section. The structure has the following members:

### `WoLPattern.WoLBitMapPattern.Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `WoLPattern.WoLBitMapPattern.MaskOffset`

The offset, in bytes, for a mask buffer from the beginning of the NDIS_PM_WOL_PATTERN
structure.

The mask specifies which bytes in incoming packets should be matched against the bitmap pattern.
Each bit in the bitmask corresponds to a byte in the pattern. If a bit is zero, the corresponding
byte in the incoming packet should not be pattern-matched. If the bit is one, the network adapter compares the
byte to the incoming packet with the byte specified in the pattern.

### `WoLPattern.WoLBitMapPattern.MaskSize`

The size, in bytes, of the mask.

### `WoLPattern.WoLBitMapPattern.PatternOffset`

The offset, in bytes, for a pattern buffer from the beginning of the NDIS_PM_WOL_PATTERN
structure.

### `WoLPattern.WoLBitMapPattern.PatternSize`

The size, in bytes, of the pattern.

### `_WOL_PATTERN`

## Remarks

The NDIS_PM_WOL_PATTERN structure is used in the
[OID_PM_ADD_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-add-wol-pattern) and
[OID_PM_WOL_PATTERN_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-wol-pattern-list) OID
requests.

An upper-layer driver can specify a generic WOL pattern with the
**WoLBitMapPattern** member. A bitmap pattern is specified as a sequence of
bytes and a mask bitmap. Each bit in the mask corresponds to a byte in the pattern, and specifies whether
the corresponding byte in the incoming packet should be matched against the corresponding byte in the
pattern. If all the bytes compared by the network adapter match, the packet is a match and the network adapter should generate a
wake-up event.

An upper-layer driver can specify a zero-filled, or
*unspecified*, IPv4 address and TCP port values in the
**IPv4TcpSynParameters** member structure. If the NDIS_PM_WOL_IPV4_DEST_ADDR_WILDCARD_ENABLED flag is
set in the
**EnabledWoLPacketPatterns** member of the NDIS_PM_PARAMETERS, the network adapter must use the unspecified address
or port value to match any source or destination IPv4 address or TCP port value in the IPv4 TCP SYN
packet.

Similarly, an upper layer driver can specify an unspecified
IPv6 address and TCP port values in the
**IPv6TcpSynParameters** member structure. If the NDIS_PM_WOL_IPV6_DEST_ADDR_WILDCARD_ENABLED flag is
set in the
**EnabledWoLPacketPatterns** member of the NDIS_PM_PARAMETERS, the network adapter must use the unspecified address
or port value to match any source or destination IPv6 address or TCP port value in the IPv4 TCP SYN
packet.

The upper layer driver sets the NDIS_PM_WOL_IPV4_DEST_ADDR_WILDCARD_ENABLED and
NDIS_PM_WOL_IPV6_DEST_ADDR_WILDCARD_ENABLED flags by issuing a set request of the
[OID_PM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-parameters) OID.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PM_COUNTED_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_counted_string)

[NDIS_PM_WOL_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_pm_wol_packet)

[OID_PM_ADD_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-add-wol-pattern)

[OID_PM_WOL_PATTERN_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-wol-pattern-list)