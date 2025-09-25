# _NDIS_SWITCH_PORT_PROPERTY_SECURITY structure

## Description

The **NDIS_SWITCH_PORT_PROPERTY_SECURITY** structure specifies a security policy property for a Hyper-V extensible switch port.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_PROPERTY_SECURITY** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to **NDIS_OBJECT_TYPE_DEFAULT**. To specify the version of the **NDIS_SWITCH_PORT_PROPERTY_SECURITY** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_PROPERTY_SECURITY_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to **NDIS_SIZEOF_NDIS_SWITCH_PROPERTY_SECURITY_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `AllowMacSpoofing`

A **BOOLEAN** value that, if set to **TRUE**, specifies that the port is allowed to send packets with a source media access control (MAC) address that is different from its permanent MAC address. The port's permanent MAC address is configured through an object identifier (OID) set request of [OID_SWITCH_NIC_CREATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-create).

### `AllowIeeePriorityTag`

A **BOOLEAN** value that, if set to **TRUE**, specifies that the port must preserve the 802.1Q priority information in a packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure when the packet is forwarded to the port. The port must preserve the priority information only if the **PreservePriority** member is set in the [NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info) union of the out-of-band data of the packet's **NET_BUFFER_LIST** structure.

### `VirtualSubnetId`

A UINT32 value that specifies the network virtualization **VirtualSubnetId** that is configured on the port. If network virtualization is not configured on the port, the value will be 0. The [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)'s [NDIS_NET_BUFFER_LIST_VIRTUAL_SUBNET_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_net_buffer_list_virtual_subnet_info) out-of-band data contains the **VirtualSubnetId**, which is populated with the traffic's virtual subnet membership.

### `AllowTeaming`

A **BOOLEAN** value that, if set to **TRUE**, specifies that teaming failover for the port is allowed, such that the port can send packets with a source media access control (MAC) address that is different than its **PermanentMacAddress**, but equal to the MAC address currently in use by another port that is connected to the same virtual machine. The port's permanent MAC address is configured through an object identifier (OID) set request of [OID_SWITCH_NIC_CREATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-create)/[OID_SWITCH_NIC_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-updated).

### `DynamicIPAddressLimit`

A UINT32 value that specifies the maximum number of dynamic IP addresses that can be learned for the port.

## Remarks

The **NDIS_SWITCH_PORT_PROPERTY_SECURITY** structure is used in the following OID set requests:

* [OID_SWITCH_PORT_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-add)
* [OID_SWITCH_PORT_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-update)

The **NDIS_SWITCH_PORT_PROPERTY_SECURITY** structure follows the [NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters) structure in the buffer that is associated with these OID set requests. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this buffer.

Port properties, such as **NDIS_SWITCH_PORT_PROPERTY_SECURITY**, are enforced by the extensible switch extension that is installed as a forwarding extension. This type of extension enforces its own rules for forwarding packets, OIDs, and status indications through the extensible switch driver stack. There can be only one forwarding extension per each instance of an extensible switch.

For more information on forwarding extensions, see [Forwarding Extensions](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-extensions).

**Note** If a forwarding extension is not installed, the extensible switch interface enforces the port property itself.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info)

[NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[OID_SWITCH_NIC_CREATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-create)

[OID_SWITCH_PORT_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-add)

[OID_SWITCH_PORT_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-update)