## Description

Specifies the data field identifiers for the [FWPS_LAYER_ALE_AUTH_CONNECT_V6](https://learn.microsoft.com/windows/win32/api/fwpsu/ne-fwpsu-fwps_builtin_layers) and **FWPS_LAYER_ALE_AUTH_CONNECT_V6_DISCARD** run-time filtering layers.

## Constants

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ALE_APP_ID`

The full path of the application.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ALE_USER_ID`

The identifier of the local user.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_LOCAL_ADDRESS_TYPE`

The local IP address type. The possible values are defined by the [NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_PROTOCOL`

The IP protocol number, as specified in RFC 1700.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_REMOTE_PORT`

The remote transport protocol port number.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ALE_REMOTE_USER_ID`

The identification of the remote user.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ALE_REMOTE_MACHINE_ID`

The identification of the remote machine.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_DESTINATION_ADDRESS_TYPE`

The destination IP address type. The possible values are defined by the [NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_LOCAL_INTERFACE`

The locally unique identifier (LUID) for the network interface associated with the local IP address.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see [Filtering condition flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_INTERFACE_TYPE`

The type of the local network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://www.iana.org/assignments/ianaiftype-mib/ianaiftype-mib).

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
*IfType* member of the **IP_ADAPTER_ADDRESSES** structure is **IF_TYPE_TUNNEL**. The tunnel type is defined
by IANA. For more information, see
[IANAifType-MIB Definitions](https://www.iana.org/assignments/ianaiftype-mib/ianaiftype-mib) and the
Windows SDK.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_INTERFACE_INDEX`

The index of the network interface, as enumerated by the network stack.

Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_SUB_INTERFACE_INDEX`

The index of the network subinterface, as enumerated by the network stack.

Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_ARRIVAL_INTERFACE`

The LUID for the network interface that is associated with the arrival IP address.

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ARRIVAL_INTERFACE_TYPE`

The type of the arrival network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://www.iana.org/assignments/ianaiftype-mib/ianaiftype-mib).

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ARRIVAL_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
*IfType* member of the **IP_ADAPTER_ADDRESSES** structure is **IF_TYPE_TUNNEL**. The tunnel type is defined
by IANA. For more information, see
[IANAifType-MIB Definitions](https://www.iana.org/assignments/ianaiftype-mib/ianaiftype-mib) and the
Windows SDK.

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ARRIVAL_INTERFACE_INDEX`

The index of the arrival network interface, as enumerated by the network stack.

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_NEXTHOP_SUB_INTERFACE_INDEX`

The index of the logical network interface that will be used to continue forwarding of the
outbound packet, as enumerated by the network stack.

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_NEXTHOP_INTERFACE`

The LUID for the network interface that is the next interface for the forwarding of the outbound
packet.

Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_NEXTHOP_INTERFACE_TYPE`

The type of the network interface that will be used to continue forwarding of the outbound packet,
as defined by the Internet Assigned Numbers Authority (IANA). For more information, see
[IANAifType-MIB Definitions](https://www.iana.org/assignments/ianaiftype-mib/ianaiftype-mib).

Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_NEXTHOP_TUNNEL_TYPE`

The encapsulation method used by a tunnel for the forwarding interface of the outbound packet, if
the
IfType member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined
by the IANA. For more information, see
[IANAifType-MIB Definitions](https://www.iana.org/assignments/ianaiftype-mib/ianaiftype-mib).

Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_NEXTHOP_INTERFACE_INDEX`

The index of the network interface that will be used to continue forwarding of the outbound
packet, as enumerated by the network stack.

Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ORIGINAL_PROFILE_ID`

The original profile identifier (network category) of the network interface. The possible network
category values are: public (1), private (2), or domain (3).

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_CURRENT_PROFILE_ID`

The current profile identifier (network category) of the network interface. The possible network
category values are: public (1), private (2), or domain (3).

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_REAUTHORIZE_REASON`

The reason for reauthorizing a previously authorized connection. For more information about
reasons for reauthorization, see the **Filtering Condition Reauthorization Flag** section in the
[Filtering condition flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags) topic.

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_PEER_NAME`

The machine name that is associated with the destination IP address.

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ORIGINAL_ICMP_TYPE`

The original ICMP type for an exchange. The ICMP type field, as specified in RFC 792.

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_INTERFACE_QUARANTINE_EPOCH`

The time that has passed since the last media state change occurred for the network interface.

Supported starting with Windows 7.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ALE_ORIGINAL_APP_ID`

The full path of the original application for proxy connections. If the application has not been proxied, then this path is identical to the **xxx_ALE_APP_ID**.

Supported starting with Windows 8.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ALE_PACKAGE_ID`

The package identifier is a security identifier (SID) that identifies the associated AppContainer process. For more information about the SID structure, see the description for the SID structure in the Microsoft Windows SDK documentation.

Supported starting with Windows 8.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ALE_SECURITY_ATTRIBUTE_FQBN_VALUE`

The fully qualified binary name (FQBN) value of the application.

Supported starting with Windows 10.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_ALE_EFFECTIVE_NAME`

This field is reserved, and should not be used.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_COMPARTMENT_ID`

The compartment that the network interface belongs to.

Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_RESERVED_0`

Reserved.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_RESERVED_1`

Reserved.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_RESERVED_2`

Reserved.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_RESERVED_3`

Reserved.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_PACKAGE_FAMILY_NAME`

Indicates that the resource is a Package Family Name string.

Supported starting with Windows Server 2022 23H2.

### `FWPS_FIELD_ALE_AUTH_CONNECT_V6_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The following macros in `fwpsu.h` are defined with **FWPS_FIELDS_ALE_AUTH_CONNECT_V6** enumeration values:

```cpp
#define FWPS_FIELD_ALE_AUTH_CONNECT_V6_ICMP_TYPE \
        FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_LOCAL_PORT

#define FWPS_FIELD_ALE_AUTH_CONNECT_V6_ICMP_CODE \
        FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_REMOTE_PORT
```

Those macros are used to access the following IPV6 data fields:

FWPS_FIELD_ALE_AUTH_CONNECT_V6_ICMP_TYPE

The ICMP type field, as specified in RFC 792.

FWPS_FIELD_ALE_AUTH_CONNECT_V6_ICMP_CODE

The ICMP code field, as specified in RFC 792.

## See also