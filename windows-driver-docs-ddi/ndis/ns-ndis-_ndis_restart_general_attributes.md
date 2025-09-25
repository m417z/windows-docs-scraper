# _NDIS_RESTART_GENERAL_ATTRIBUTES structure

## Description

The **NDIS_RESTART_GENERAL_ATTRIBUTES** structure defines the general restart attributes that are
associated with a miniport adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RESTART_GENERAL_ATTRIBUTES** structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_RESTART_GENERIC_ATTRIBUTES**.

To indicate the version of the **NDIS_RESTART_GENERAL_ATTRIBUTES** structure, NDIS sets the
**Revision** member to one of the following values:

#### NDIS_RESTART_GENERAL_ATTRIBUTES_REVISION_2

Added the
**MaxLookaheadSizeAccessed** member for NDIS 6.2.

NDIS sets the
**Size** member to **NDIS_SIZEOF_RESTART_GENERAL_ATTRIBUTES_REVISION_2**.

#### NDIS_RESTART_GENERAL_ATTRIBUTES_REVISION_1

Original version for NDIS 6.0 and NDIS 6.1.

NDIS sets the
**Size** member to **NDIS_SIZEOF_RESTART_GENERAL_ATTRIBUTES_REVISION_1**.

### `MtuSize`

The maximum transfer unit (MTU) size. For more information, see
[OID_GEN_MAXIMUM_FRAME_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-frame-size).

### `MaxXmitLinkSpeed`

The maximum transmit link speed of the adapter in bits per second. For more information, see
[OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed).

### `MaxRcvLinkSpeed`

The maximum receive link speed of the adapter in bits per second. For more information, see
[OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed).

### `LookaheadSize`

The lookahead size for the miniport adapter. For more information, see
[OID_GEN_CURRENT_LOOKAHEAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-lookahead).

### `MacOptions`

The medium access control (MAC) options for the miniport adapter. For more information, see
[OID_GEN_MAC_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-mac-options).

### `SupportedPacketFilters`

The packet filter flags for the miniport adapter.

### `MaxMulticastListSize`

The maximum multicast address list size for the miniport adapter. For more information, see
[OID_802_3_MAXIMUM_LIST_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-maximum-list-size).

### `RecvScaleCapabilities`

The receive side scaling (RSS) capabilities of the NIC. If the miniport adapter does not support
the RSS feature, NDIS sets
**RecvScaleCapabilities** to a pointer to an
[NDIS_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_scale_capabilities) structure that is filled with zeros. For more information about
RSS, see
[OID_GEN_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-capabilities).

### `AccessType`

A
[NET_IF_ACCESS_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_access_type) NDIS network interface
access type.

### `Flags`

Reserved.

### `ConnectionType`

A
[NET_IF_CONNECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_connection_type) NDIS network
interface connection type.

### `SupportedStatistics`

The supported statistics. For more information, see the
**SupportedStatistics** member of the
[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes) structure.

### `DataBackFillSize`

The required data backfill size, in bytes, of the driver.

### `ContextBackFillSize`

The required context backfill size, in bytes, of the driver.

### `SupportedOidList`

A list of OIDs that the miniport driver supports. For more information, see
[OID_GEN_SUPPORTED_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-supported-list).

### `SupportedOidListLength`

The size, in bytes, of the OID list that is specified in the
**SupportedOidList** member.

### `MaxLookaheadSizeAccessed`

A ULONG value for the maximum size, in bytes, of the lookahead size requirement for receive
queues. A miniport adapter that supports lookahead in VM queues splits a received packet at an offset
equal to or greater than the requested lookahead size and DMAs the lookahead data and the post-lookahead
data to separate shared memory segments.

## Remarks

NDIS passes an NDIS_RESTART_GENERAL_ATTRIBUTES structure to drivers during restart operations. For
example, when NDIS calls a miniport driver's
[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) function, NDIS passes a
pointer to an
[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure to
the miniport driver in the
**RestartAttributes** member of the
[NDIS_MINIPORT_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_restart_parameters) structure.

If the
**Oid** member in the NDIS_RESTART_ATTRIBUTES structure is
[OID_GEN_MINIPORT_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-miniport-restart-attributes), the
**Data** member of NDIS_RESTART_ATTRIBUTES contains an NDIS_RESTART_GENERAL_ATTRIBUTES structure.

## See also

[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart)

[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes)

[NDIS_MINIPORT_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_restart_parameters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_scale_capabilities)

[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes)

[NET_IF_ACCESS_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_access_type)

[NET_IF_CONNECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_connection_type)

[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type)

[OID_802_3_MAXIMUM_LIST_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-maximum-list-size)

[OID_GEN_CURRENT_LOOKAHEAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-lookahead)

[OID_GEN_MAC_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-mac-options)

[OID_GEN_MAXIMUM_FRAME_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-frame-size)

[OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed)

[OID_GEN_MINIPORT_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-miniport-restart-attributes)

[OID_GEN_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-statistics)

[OID_GEN_SUPPORTED_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-supported-list)

[OID_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-capabilities)