# FWPS_FIELDS_INBOUND_ICMP_ERROR_V6_ enumeration

## Description

The FWPS_FIELDS_INBOUND_ICMP_ERROR_V6 enumeration type specifies the data field identifiers for the
FWPS_LAYER_INBOUND_ICMP_ERROR_V6 and FWPS_LAYER_INBOUND_ICMP_ERROR_V6_DISCARD
[run-time filtering layers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_EMBEDDED_PROTOCOL`

The IP protocol number that is embedded in the ICMP packet, as specified in RFC 1700.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_EMBEDDED_REMOTE_ADDRESS`

The remote IP address that is embedded in the ICMP packet.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_EMBEDDED_LOCAL_ADDRESS_TYPE`

The local IP address type that is embedded in the ICMP packet. The possible condition values are
defined by the
[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_EMBEDDED_LOCAL_PORT`

The local transport protocol port number that is embedded in the ICMP packet.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_EMBEDDED_REMOTE_PORT`

The remote transport protocol port number that is embedded in the ICMP packet.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_IP_LOCAL_INTERFACE`

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) for the network interface associated with the
local IP address.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_ICMP_TYPE`

The ICMP type field, as specified in RFC 792.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_ICMP_CODE`

The ICMP code field, as specified in RFC 792.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_INTERFACE_INDEX`

The index of the local network interface, as enumerated by the network stack.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_SUB_INTERFACE_INDEX`

The LUID for the network interface that is associated with the arrival IP address

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_INTERFACE_TYPE`

The type of the local network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
**IfType** member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined
by IANA. For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066) and the
Windows SDK.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_IP_ARRIVAL_INTERFACE`

The LUID for the network interface that is associated with the arrival IP address.

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_ARRIVAL_INTERFACE_INDEX`

The index of the arrival network interface, as enumerated by the network stack.

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_ARRIVAL_INTERFACE_TYPE`

The type of the arrival network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_ARRIVAL_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
**IfType** member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined
by IANA. For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066) and the
Windows SDK.

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see
[Filtering Condition Flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_ARRIVAL_INTERFACE_PROFILE_ID`

The profile identifier (network category) of the arrival interface. The possible network category
values are: public (1), private (2), or domain (3).

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_INTERFACE_QUARANTINE_EPOCH`

The time that has passed since the last media state change occurred for the network interface.

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_COMPARTMENT_ID`

The compartment that the network interface belongs to.

**Note** Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_INBOUND_ICMP_ERROR_V6_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The following macros in
*Fwpsk.h* are defined with FWPS_FIELDS_INBOUND_ICMP_ERROR_V6 enumeration
values:

```

#if (NTDDI_VERSION >= NTDDI_WIN6SP1)

#define FWPS_FIELD_INBOUND_ICMP_ERROR_V6_LOCAL_INTERFACE_INDEX \
        FWPS_FIELD_INBOUND_ICMP_ERROR_V6_INTERFACE_INDEX

#define FWPS_FIELD_INBOUND_ICMP_ERROR_V6_ARRIVAL_SUB_INTERFACE_INDEX \
        FWPS_FIELD_INBOUND_ICMP_ERROR_V6_SUB_INTERFACE_INDEX

#define FWPS_FIELD_INBOUND_ICMP_ERROR_V6_LOCAL_INTERFACE_TYPE \
        FWPS_FIELD_INBOUND_ICMP_ERROR_V6_INTERFACE_TYPE

#define FWPS_FIELD_INBOUND_ICMP_ERROR_V6_LOCAL_TUNNEL_TYPE \
        FWPS_FIELD_INBOUND_ICMP_ERROR_V6_TUNNEL_TYPE

#endif // (NTDDI_VERSION >= NTDDI_WIN6SP1)

```

These macros are used to access the following IPV6 data fields:

FWPS_FIELD_INBOUND_ICMP_ERROR_V6_LOCAL_INTERFACE_INDEX
The index of the local network interface, as enumerated by the network stack.

> [!NOTE]
> Supported in Windows Server 2008, Windows Vista SP1, and later versions of Windows.
FWPS_FIELD_INBOUND_ICMP_ERROR_V6_ARRIVAL_SUB_INTERFACE_INDEX
The index of the logical network interface, as enumerated by the network stack.

> [!NOTE]
> Supported in Windows Server 2008, Windows Vista SP1, and later versions of Windows.
FWPS_FIELD_INBOUND_ICMP_ERROR_V6_LOCAL_INTERFACE_TYPE
The type of the local network interface, as defined by the Internet Assigned Numbers Authority (IANA). For more information, see IANAifType-MIB Definitions and the Windows SDK.

> [!NOTE]
> Supported in Windows Server 2008, Windows Vista SP1, and later versions of Windows.
FWPS_FIELD_INBOUND_ICMP_ERROR_V6_LOCAL_TUNNEL_TYPE
The encapsulation method used by a tunnel if the IfType member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined by IANA. For more information, see IANAifType-MIB Definitions and the Windows SDK.

> [!NOTE]
> Supported in Windows Server 2008, Windows Vista SP1, and later versions of Windows.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type)