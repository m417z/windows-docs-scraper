# _NDIS_NET_BUFFER_LIST_8021Q_INFO structure

## Description

The NDIS_NET_BUFFER_LIST_8021Q_INFO structure specifies 802.1Q information that is associated with a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `TagHeader`

A member in the union that is contained in NDIS_NET_BUFFER_LIST_8021Q_INFO. 802.3 Ethernet
miniport drivers use
**TagHeader** to access 802.1Q information.
**TagHeader** is a bit field with the following members:

### `TagHeader.UserPriority`

Specifies 802.1p priority information that is used to establish packet priority in shared-media
802 networks. The bits in this member specify an 802.1p priority value.

### `TagHeader.CanonicalFormatId`

This member should be set to zero, which indicates that all MAC address information present in a
packet is in canonical format (that is, simplest form).

### `TagHeader.VlanId`

Identifies the VLAN that a packet belongs to. Outgoing packets are marked with the VLAN
identifier.

### `TagHeader.Reserved`

This member is reserved and should be set to zero.

### `WLanTagHeader`

A member in the union that is contained in NDIS_NET_BUFFER_LIST_8021Q_INFO. Native 802.11
miniport drivers use
**WLanTagHeader** to access 802.1Q information.
**WLanTagHeader** is a bit field with the following members:

### `WLanTagHeader.UserPriority`

Specifies 802.1p priority information that is used to establish packet priority in shared-media
802 networks. The bits in this member specify an 802.1p priority value.

### `WLanTagHeader.CanonicalFormatId`

This member should be set to zero, which indicates that all MAC address information present in a
packet is in canonical format (that is, simplest form).

### `WLanTagHeader.VlanId`

Identifies the VLAN that a packet belongs to. Outgoing packets are marked with the VLAN
identifier.

### `WLanTagHeader.WMMInfo`

A wireless multimedia (WMM) integer value that is the same as the traffic identifier (TID) fields
that appear in certain frames that are used to deliver and to control the delivery of 802.1Q Quality
of Service (QoS) data. The values 0 through 7 represent QoS user priorities (UPs) for the MAC service
data units (MSDUs). The values 8 through 15 are reserved. Therefore, the highest bit in
**WMMInfo** must be zero.

**Note** Traffic specification (TSPEC) and traffic classification (TCLAS) are not
supported.

### `WLanTagHeader.Reserved`

This member is reserved and should be set to zero.

### `Value`

A member in the union that is contained in NDIS_NET_BUFFER_LIST_8021Q_INFO.
**Value** contains a pointer value that is type-compatible with the
**NetBufferListInfo** member in the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Remarks

To retrieve or insert 802.1Q information that is associated with a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure, an NDIS driver
calls the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro and specifies
the
**Ieee8021QNetBufferListInfo** information type.

The NET_BUFFER_LIST_INFO macro returns the pointer that is specified in the
**Value** member of the NDIS_NET_BUFFER_LIST_8021Q_INFO structure. The NDIS driver can use the
**TagHeader** or
**WLanTagHeader** member of the union to access specific types of information, such as 802.1p priority
and VLAN identifier information. The
**WLanTagHeader** member provides access to the wireless multimedia (WMM) information in addition to
the information that is available through the
**TagHeader** member.

Miniport drivers that support the 802.1Q tag in hardware must use the NDIS_NET_BUFFER_LIST_8021Q_INFO
structure for transmit and receive operations:

* For transmit operations, the miniport driver must check for NDIS_NET_BUFFER_LIST_8021Q_INFO OOB data
  in the
  [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. The miniport
  driver must ensure that the hardware creates the 802.1Q tag from the NDIS_NET_BUFFER_LIST_8021Q_INFO
  specifications and insert it into the Ethernet frame.
* For receive operations, the miniport driver must remove the 802.1Q tag from the Ethernet frame and
  map the 802.1Q tag information into the NDIS_NET_BUFFER_LIST_8021Q_INFO OOB data in the NET_BUFFER_LIST
  structure before indicating the data to NDIS with the
  [NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function.

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)