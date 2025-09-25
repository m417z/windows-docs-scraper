# FWPS_FIELDS_ALE_AUTH_RECV_ACCEPT_V4_ enumeration

## Description

The FWPS_FIELDS_ALE_AUTH_RECV_ACCEPT_V4 enumeration type specifies the data field identifiers for the FWPS_LAYER_ALE_AUTH_RECV_ACCEPT_V4 and FWPS_LAYER_ALE_AUTH_RECV_ACCEPT_V4_DISCARD
[run-time filtering layers](https://learn.microsoft.com/windows-hardware/drivers/network/run-time-filtering-layer-identifiers).

## Constants

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ALE_APP_ID`

The full path of the application.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ALE_USER_ID`

The identifier of the local user.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_LOCAL_ADDRESS_TYPE`

The local IP address type. The possible values are defined by the
[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_PROTOCOL`

The IP protocol number, as specified in RFC 1700.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_REMOTE_PORT`

The remote transport protocol port number.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ALE_REMOTE_USER_ID`

The identifier of the remote user.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ALE_REMOTE_MACHINE_ID`

The identifier of the remote machine.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_LOCAL_INTERFACE`

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) for the network interface associated with the
local IP address.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see
[Filtering Condition Flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_SIO_FIREWALL_SYSTEM_PORT`

Reserved for internal use.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_NAP_CONTEXT`

Reserved for internal use.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_INTERFACE_TYPE`

The type of the local network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
**IfType** member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined
by the IANA. For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_INTERFACE_INDEX`

The index of the arrival network interface, as enumerated by the network stack.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_SUB_INTERFACE_INDEX`

The LUID for the network interface that is associated with the arrival IP address.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_ARRIVAL_INTERFACE`

The LUID for the network interface that is associated with the arrival IP address.

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ARRIVAL_INTERFACE_TYPE`

The type of the arrival network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ARRIVAL_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
**IfType** member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined
by the IANA. For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ARRIVAL_INTERFACE_INDEX`

The index of the arrival network interface, as enumerated by the network stack.

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_NEXTHOP_SUB_INTERFACE_INDEX`

The index of the logical network interface that will be used to continue forwarding of the
outbound packet, as enumerated by the network stack.

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_NEXTHOP_INTERFACE`

The LUID for the network interface that is the next interface for the forwarding of the outbound
packet.

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_NEXTHOP_INTERFACE_TYPE`

The type of the network interface that will be used to continue forwarding of the outbound packet,
as defined by the Internet Assigned Numbers Authority (IANA). For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_NEXTHOP_TUNNEL_TYPE`

The encapsulation method used by a tunnel for the forwarding interface of the outbound packet, if
the
**IfType** member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined
by the IANA. For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_NEXTHOP_INTERFACE_INDEX`

The index of the network interface that will be used to continue forwarding of the outbound
packet, as enumerated by the network stack.

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ORIGINAL_PROFILE_ID`

The original profile identifier (network category) of the network interface. The possible network
category values are: public (1), private (2), or domain (3).

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_CURRENT_PROFILE_ID`

The current profile identifier (network category) of the network interface. The possible network
category values are: public (1), private (2), or domain (3).

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_REAUTHORIZE_REASON`

The reason for reauthorizing a previously authorized connection. For more information about
reasons for reauthorization, see
the Filtering Condition Reauthorization Flag of the
[Filtering Condition Flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags) topic.

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ORIGINAL_ICMP_TYPE`

The original ICMP type for an exchange. The ICMP type field, as specified in RFC 792.

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_INTERFACE_QUARANTINE_EPOCH`

The time that has passed since the last media state change occurred for the network interface.

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ALE_PACKAGE_ID`

The package identifier is a security identifier (SID) that identifies the associated AppContainer process. For more information about the SID structure, see the description for the SID structure in the Microsoft Windows SDK documentation.

**Note** Supported starting with Windows 8.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ALE_SECURITY_ATTRIBUTE_FQBN_VALUE`

The fully qualified binary name (FQBN) value of the application.

**Note** Supported starting with Windows 10.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_COMPARTMENT_ID`

The compartment that the network interface belongs to.

**Note** Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_PACKAGE_FAMILY_NAME`

The Package Family Name of the application.

**Note** Supported starting with Windows Server 2022 23H2.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_RESERVED_0`
Reserved.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_RESERVED_1`
Reserved.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_RESERVED_2`
Reserved.

### `FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_RESERVED_3`
Reserved.

## Remarks

In Windows Server 2008, Windows Vista SP1, and later versions of Windows, when an outbound packet is
indicated to this layer during a reauthorization call to the callout filter's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function, all arrival network
interface related fields are set to FWP_EMPTY.

The following macros in
*Fwpsk.h* are defined with FWPS_FIELDS_ALE_AUTH_RECV_ACCEPT_V4 enumeration
values:

```

#define FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ICMP_TYPE \
        FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_LOCAL_PORT

#define FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ICMP_CODE \
        FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_REMOTE_PORT

#if (NTDDI_VERSION >= NTDDI_WIN6SP1)

#define FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_LOCAL_INTERFACE_TYPE \
        FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_INTERFACE_TYPE

#define FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_LOCAL_TUNNEL_TYPE \
        FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_TUNNEL_TYPE

#define FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_LOCAL_INTERFACE_INDEX \
        FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_INTERFACE_INDEX

#define FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ARRIVAL_SUB_INTERFACE_INDEX \
        FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_SUB_INTERFACE_INDEX

#if (NTDDI_VERSION >= NTDDI_WIN7)
#define FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_SIO_FIREWALL_SOCKET_PROPERTY \
        FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_SIO_FIREWALL_SYSTEM_PORT
#endif // (NTDDI_VERSION >= NTDDI_WIN7)
#endif // (NTDDI_VERSION >= NTDDI_WIN6SP1)

```

These macros are used to access the following IPV4 data fields:

FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ICMP_TYPE
The ICMP type field, as specified in RFC 792.

FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ICMP_CODE
The ICMP code field, as specified in RFC 792.

FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_LOCAL_INTERFACE_TYPE
The type of the local network interface, as defined by the Internet Assigned Numbers Authority (IANA). For more information, see IANAifType-MIB Definitions.

> [!NOTE]
> Supported in Windows Server 2008, Windows Vista SP1, and later versions of Windows.
FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_LOCAL_TUNNEL_TYPE
The encapsulation method used by a tunnel if the IfType member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined by IANA. For more information, see IANAifType-MIB Definitions and the Windows SDK.

> [!NOTE]
> Supported in Windows Server 2008, Windows Vista SP1, and later versions of Windows.
FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_LOCAL_INTERFACE_INDEX
The index of the local network interface, as enumerated by the network stack.

> [!NOTE]
> Supported in Windows Server 2008, Windows Vista SP1, and later versions of Windows.
FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_ARRIVAL_SUB_INTERFACE_INDEX
The index of the logical network interface, as enumerated by the network stack.

> [!NOTE]
> Supported in Windows Server 2008, Windows Vista SP1, and later versions of Windows.
FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_SIO_FIREWALL_SOCKET_PROPERTY
The IP_PROTECTION_LEVEL property associated with the socket.

> [!NOTE]
> Supported starting with Windows 7.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type)