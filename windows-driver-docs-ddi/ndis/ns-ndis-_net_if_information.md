# _NET_IF_INFORMATION structure

## Description

The NET_IF_INFORMATION structure provides NDIS with information about a registered network
interface.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
interface information structure (NET_IF_INFORMATION). The provider sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_OBJECT_REVISION_1, and the
**Size** member to NDIS_SIZEOF_NET_IF_INFORMATION_REVISION_1.

### `Flags`

Flags that provide information about the interface that this structure describes. These flags are
combined with a bitwise OR operation. If none of the flags applies, set this member to zero. The
following flag values are defined:

#### NIIF_HARDWARE_INTERFACE

Set if the network interface is for hardware.

#### NIIF_FILTER_INTERFACE

Set if the network interface is for a filter module.

#### NIIF_NDIS_RESERVED1

Reserved for NDIS.

#### NIIF_NDIS_RESERVED2

Reserved for NDIS.

#### NIIF_NDIS_RESERVED3

Reserved for NDIS.

### `PhysicalLocation`

The physical location for the hardware that is associated with an interface specified in a
[NET_PHYSICAL_LOCATION](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_physical_location_lh) structure.

### `WanTunnelType`

The tunnelIfEncapsMethod (from
RFC 2667) for WAN devices. If the WAN tunnel type is unknown, set this
member to NIIF_WAN_TUNNEL_TYPE_UNKNOWN.

### `PortNumber`

The NDIS port number for the interface.

### `AccessType`

A
[NET_IF_ACCESS_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_access_type) NDIS network interface
access type.

### `DirectionType`

A
[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type) NDIS network
interface direction type.

### `ConnectionType`

A
[NET_IF_CONNECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_connection_type) NDIS network
interface connection type.

### `ifConnectorPresent`

A Boolean value that indicates if a connector is present. Set this value to **TRUE** if there is a
physical adapter or **FALSE** if there is no physical adapter.

### `PhysAddressLength`

The length, in bytes, of the physical address or MAC address. This length is the length of the
byte arrays that are located at the offsets that the
**PhysAddressOffset** and
**PermanentPhysAddressOffset** members specify.

### `PhysAddressOffset`

The offset of the current physical address, in bytes, from the beginning of this structure. The
current physical address is an array of bytes. The length of the array is specified in the
**PhysAddressLength** member. The current physical address is the same value that the
[OID_802_3_CURRENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-current-address) OID
returns.

### `PermanentPhysAddressOffset`

The offset of the permanent physical address, in bytes, from the beginning of this structure. The
permanent physical address is an array of bytes. The length of the array is specified in the
**PhysAddressLength** member. The permanent physical address is the same value that the
[OID_802_3_PERMANENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-permanent-address) OID
returns.

### `FriendlyNameLength`

The length, in bytes, of the friendly name for the interface that this structure describes. This
length is the length of the WCHAR array that is located at the offset in the
**FriendlyNameOffset** member.

### `FriendlyNameOffset`

The offset of the beginning of the friendly name, in bytes, from the beginning of this structure.
This name should include the name of the manufacturer, the product, and the version of the interface
hardware and software. The name is specified as an array of WCHAR values. The
**FriendlyNameLength** member specifies the length of the array.

### `InterfaceGuid`

The GUID that is associated with the interface. The interface provider generates the interface
GUID for the interface. The provider can call the
[ExUuidCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exuuidcreate) routine to create the GUID. The
interface GUID should be associated with the
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value that is assigned to the interface.
If the provider retains information about the interface in persistent storage, it should save the GUID
and reuse the GUID when it reregisters the interface after the computer restarts.

### `NetworkGuid`

The GUID that is associated with the network that the interface belongs to. If the interface
provider cannot provide the network GUID, it can pass a zero GUID. In this case, NDIS will register the
interface in the default network of the primary compartment.

### `SupportedStatistics`

The statistics that the interface supports. For more information, see the
**SupportedStatistics** member of the
[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes) structure .

### `MediaType`

The
**NdisMedium***Xxx* type that the interface supports. For more information, see
[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium).

### `PhysicalMediumType`

The physical medium type for the interface. For more information, see
[OID_GEN_PHYSICAL_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-physical-medium)

## Remarks

A network interface provider initializes a NET_IF_INFORMATION structure to provide NDIS with
information about a registered interface. To register an interface, a provider passes a pointer to a
NET_IF_INFORMATION structure to the
[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface) function.

The interface provider should allocate enough memory for the structure and the arrays that the
**PhysAddressOffset**,
**PermanentPhysAddressOffset**, and
**FriendlyNameOffset** members specify. The provider must provide the values for the arrays after the
structure and set the offset members to identify the location of the arrays.

## See also

[ExUuidCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exuuidcreate)

[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium)

[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NET_IF_ACCESS_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_access_type)

[NET_IF_CONNECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_connection_type)

[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type)

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[NET_PHYSICAL_LOCATION](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_physical_location_lh)

[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface)

[OID_802_3_CURRENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-current-address)

[OID_802_3_PERMANENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-permanent-address)

[OID_GEN_PHYSICAL_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-physical-medium)

[OID_GEN_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-statistics)