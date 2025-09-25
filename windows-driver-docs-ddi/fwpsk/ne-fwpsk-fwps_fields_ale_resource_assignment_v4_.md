# FWPS_FIELDS_ALE_RESOURCE_ASSIGNMENT_V4_ enumeration

## Description

The FWPS_FIELDS_ALE_RESOURCE_ASSIGNMENT_V4 enumeration type specifies the data field identifiers for
the FWPS_LAYER_ALE_RESOURCE_ASSIGNMENT_V4 and FWPS_LAYER_ALE_RESOURCE_ASSIGNMENT_V4_DISCARD
[run-time filtering layers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_ALE_APP_ID`

The full path of the application.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_ALE_USER_ID`

The identifier of the local user.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_IP_LOCAL_ADDRESS_TYPE`

The local IP address type. The possible values are defined by the
[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_IP_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_IP_PROTOCOL`

The IP protocol number, as specified in RFC 1700.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_ALE_PROMISCUOUS_MODE`

The possible values are:

* SIO_RCVALL
* SIO_RCVALL_IGMPMCAST
* SIO_RCVALL_MCAST

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_IP_LOCAL_INTERFACE`

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) for the network interface associated with the
local IP address.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see
[Filtering Condition Flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_INTERFACE_TYPE`

The type of the local network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
**IfType** member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined
by IANA. For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066) and the
Windows SDK.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_LOCAL_INTERFACE_PROFILE_ID`

The profile identifier (network category) of the network interface associated with the local IP
address. The possible network category values are: public (1), private (2), or domain (3).

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_SIO_FIREWALL_SOCKET_PROPERTY`

The IP_PROTECTION_LEVEL property associated with the local socket.

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_ALE_PACKAGE_ID`

The package identifier is a security identifier (SID) that identifies the associated AppContainer process. For more information about the SID structure, see the description for the SID structure in the Microsoft Windows SDK documentation.

**Note** Supported starting with Windows 8.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_ALE_SECURITY_ATTRIBUTE_FQBN_VALUE`

The fully qualified binary name (FQBN) value of the application.

**Note** Supported starting with Windows 10.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_COMPARTMENT_ID`

The compartment that the network interface belongs to.

**Note** Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_PACKAGE_FAMILY_NAME`

The Package Family Name of the application.

**Note** Supported starting with Windows Server 2022 23H2.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_RESERVED_0`
Reserved.

### `FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_RESERVED_1`
Reserved.

## Remarks

For the case of an implicit bind, the local address and port information might not be available. In
this situation, the FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_IP_LOCAL_ADDRESS,
FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_IP_LOCAL_ADDRESS_TYPE, and/or
**FWPS_FIELD_ALE_RESOURCE_ASSIGNMENT_V4_IP_LOCAL_PORT** data fields might be of type FWP_EMPTY.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type)