# _NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES structure

## Description

The **NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES** structure specifies the hardware-assisted attributes of the network adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES.

To indicate the version of the **NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES** structure, set the
**Revision** member to one of the following values:

#### NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES_REVISION_3

Added various members for NDIS 6.30.

Set the
**Size** member to NDIS_SIZEOF_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES_REVISION_3.

#### NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES_REVISION_2

Added the
**HardwareReceiveFilterCapabilities**,
**CurrentReceiveFilterCapabilities**,
**HardwareNicSwitchCapabilities**, and
**CurrentNicSwitchCapabilities** members for NDIS 6.20.

Set the
**Size** member to NDIS_SIZEOF_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES_REVISION_2.

#### NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES_REVISION_1

Original version for NDIS 6.1.

Set the
**Size** member to NDIS_SIZEOF_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES_REVISION_1.

### `HDSplitAttributes`

A pointer to an
[NDIS_HD_SPLIT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_hd_split_attributes) structure
that represents the header-data split capabilities that the network adapter provides. If the network adapter does not support the header-data split feature, set
**HDSplitAttributes** to **NULL**.

### `HardwareReceiveFilterCapabilities`

A pointer to an
[NDIS_RECEIVE_FILTER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_capabilities) structure. This structure specifies the hardware receive
filtering capabilities of the network adapter. This value can be **NULL** if the network adapter does not
support receive filtering.

**Warning** If this member is not set to NULL, the **CurrentReceiveFilterCapabilities** member must not be set to **NULL**.

### `CurrentReceiveFilterCapabilities`

A pointer to an NDIS_RECEIVE_FILTER_CAPABILITIES structure. This structure specifies the receive
filtering capabilities that are currently enabled on the network adapter. This value can be **NULL** if the
network adapter does not support receive filtering.

**Warning** If this member is not set to NULL, the **HardwareReceiveFilterCapabilities** member must not be set to **NULL**.

### `HardwareNicSwitchCapabilities`

A pointer to an
[NDIS_NIC_SWITCH_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_capabilities) structure. This structure specifies the hardware NIC switch
capabilities of the network adapter. This value can be **NULL** if the network adapter does not support
NIC switch features or receive filtering.

**Warning** If this member is not set to NULL, the **CurrentNicSwitchCapabilities** member must not be set to **NULL**.

### `CurrentNicSwitchCapabilities`

A pointer to an [NDIS_NIC_SWITCH_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_capabilities) structure. This structure specifies the NIC switch
capabilities that are currently enabled on the network adapter. This value can be **NULL** if the network adapter does not support NIC switch features or receive filtering.

**Warning** If this member is not set to NULL, the **HardwareNicSwitchCapabilities** member must not be set to **NULL**.

### `HardwareSriovCapabilities`

A pointer to an [NDIS_SRIOV_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_capabilities) structure. This structure specifies the single root I/O virtualization (SR-IOV) capabilities of the network adapter hardware. This value can be **NULL** if the network adapter does not support SR-IOV.

For more information on SR-IOV, see [Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov-).

**Note** If this member is not set to NULL, the **CurrentSriovCapabilities**, **HardwareNicSwitchCapabilities**, and **CurrentNicSwitchCapabilities** members must not be set to **NULL**.

### `CurrentSriovCapabilities`

A pointer to an [NDIS_SRIOV_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_capabilities) structure. This structure specifies the SR-IOV capabilities that are currently enabled on the network adapter. This value can be **NULL** if the network adapter does not support SR-IOV.

**Note** If this member is not set to NULL, the **HardwareSriovCapabilities**, **HardwareNicSwitchCapabilities**, and **CurrentNicSwitchCapabilities** members must not be set to **NULL**.

### `HardwareQosCapabilities`

A pointer to an [NDIS_QOS_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_capabilities) structure. This structure specifies the hardware capabilities that the network adapter supports for NDIS quality of service (QoS) over the IEEE 802.1 Data Center Bridging (DCB) interface. This value can be **NULL** if the network adapter does not support NDIS QoS hardware capabilities for DCB.

For more information, see [NDIS QoS for Data Center Bridging](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-qos-for-data-center-bridging).

**Note** If this member is not set to NULL, the **CurrentQosCapabilities** member must not be set to **NULL**.

### `CurrentQosCapabilities`

A pointer to an [NDIS_QOS_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_capabilities) structure. This structure specifies the hardware capabilities that are currently enabled on the network adapter for NDIS QoS over the DCB interface. This value can be **NULL** if the network adapter does not support NDIS QoS hardware capabilities for DCB.

If the adapter supports NDIS QoS capabilities but those capabilities are disabled, the miniport driver must set all members of the [NDIS_QOS_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_capabilities) structure (with the exception of the **Header** member) to zero.

**Note** If this member is not set to NULL, the **HardwareQosCapabilities** member must not be set to **NULL**.

### `HardwareGftOffloadCapabilities`

### `CurrentGftOffloadCapabilities`

## Remarks

To register the hardware-assisted capabilities of the underlying network adapter, the miniport driver calls the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function. The driver passes
an initialized **NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES**
structure to the *MiniportAttributes* parameter of this function.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_HD_SPLIT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_hd_split_attributes)

[NDIS_NIC_SWITCH_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_capabilities)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_QOS_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_capabilities)

[NDIS_RECEIVE_FILTER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_capabilities)

[NDIS_SRIOV_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_capabilities)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)