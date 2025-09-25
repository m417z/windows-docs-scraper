# _NDIS_SWITCH_NIC_PARAMETERS structure

## Description

The **NDIS_SWITCH_NIC_PARAMETERS** structure specifies the configuration parameters for a network adapter (NIC) that is connected to a Hyper-V extensible switch port.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_NIC_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_NIC_PARAMETERS** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_NIC_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to **NDIS_SIZEOF_NDIS_SWITCH_NIC_PARAMETERS_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. The following flag value is defined.

| Value | Meaning |
| --- | --- |
| **NDIS_SWITCH_NIC_FLAGS_NIC_INITIALIZING** | This flag is set when the [OID_SWITCH_NIC_CREATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-create) OID is issued for the first time in the lifetime of a VM NIC object. If this flag is set:<br><br>* A Hyper-V Extensible Switch extension can optionally reduce the value of the **MTU** member in the **NDIS_SWITCH_NIC_PARAMETERS** structure if it needs to reserve headroom for encapsulation before it passes the OID down the stack. The extension will not be able to reserve encapsulation headroom for any other type of NIC.<br>* The extension should not increase the **MTU** value.<br><br>This flag will be set only if the **NicType** member is **NdisSwitchNicTypeSynthetic**. |

### `NicName`

 An NDIS_SWITCH_NIC_NAME value that specifies the unique internal name of the network adapter that is connected to an extensible switch port.

For more information, see the Remarks section.

### `NicFriendlyName`

 An NDIS_SWITCH_NIC_FRIENDLYNAME value that specifies the user-friendly description of the network adapter.

### `PortId`

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port to which the network adapter is connected.

### `NicIndex`

An NDIS_SWITCH_NIC_INDEX value that specifies the index of the network adapter that is connected to the extensible switch port specified by the **PortId** member.

For more information on NDIS_SWITCH_NIC_INDEX values, see [Network Adapter Index Values](https://learn.microsoft.com/windows-hardware/drivers/network/network-adapter-index-values).

### `NicType`

An [NDIS_SWITCH_NIC_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_nic_type) value that specifies the type of the network adapter that is connected to an extensible switch port.

### `NicState`

An [NDIS_SWITCH_NIC_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_nic_state) value that specifies the current state of the network adapter.

### `VmName`

An NDIS_VM_NAME value that specifies the unique internal name of the Hyper-V child partition in which the guest operating system that exposes the network adapter is running.

The Hyper-V child partition is also known as a virtual machine (VM).

**Note** This member is valid only if the **NicType** member contains a value of **NdisSwitchNicSyntheticNic** or **NdisSwitchNicEmulatedNic.**

### `NetCfgInstanceId`

A GUID value that specifies the **NetCfgInstanceId** registry value of the
underlying network adapter.

**Note** This member is valid only if the **NicType** member is set to **NdisSwitchNicTypeExternal** or **NdisSwitchNicTypeInternal**. **NetCfgInstanceId** will not be valid until after the virtual network adapter has been initialized.

### `MTU`

A **ULONG** value that specifies the maximum transmission unit (MTU) size, in bytes, for the network adapter.

**Note** The value of this member can change during the lifetime of a VM NIC. Therefore, extensions should read this member of the **NDIS_SWITCH_NIC_PARAMETERS** structure that is passed down with the following OIDs:

* [OID_SWITCH_NIC_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-connect)
* [OID_SWITCH_NIC_UPDATED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-updated)

### `NumaNodeId`

A **USHORT** value that specifies the identifier for the preferred Non-Uniform Memory Access (NUMA) node of a CPU. On computers that support NUMA architecture, the preferred NUMA node is the CPU that has the smallest distance to the network adapter.

**Note** This member is valid only if the **NicType** member is set to **NdisSwitchNicTypeSynthetic** or **NdisSwitchNicTypeEmulated**.

### `PermanentMacAddress[NDIS_MAX_PHYS_ADDRESS_LENGTH]`

A **UCHAR** array that specifies the media access control (MAC) address as configured on the host partition for the network adapter. This can be different from the MAC address currently in use by the network adapter.

### `VMMacAddress[NDIS_MAX_PHYS_ADDRESS_LENGTH]`

A **UCHAR** array that specifies the MAC address that is configured on the network adapter inside the VM itself. The field is all zeros for non VM NICs. If *AllowMacSpoofing* (from [NDIS_SWITCH_PORT_PROPERTY_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_security)) is TRUE, this address will also be applied to the *CurrentMacAddress.*

### `CurrentMacAddress[NDIS_MAX_PHYS_ADDRESS_LENGTH]`

A **UCHAR** array that specifies the MAC address that is currently being used in the switch for the network adapter. If *AllowMacSpoofing* and *AllowTeaming* are both FALSE, then this value will be equal to *PermanentMacAddress*. If *AllowMacSpoofing* is TRUE, this value will be equal to the *VMMacAddress*. If *AllowTeaming* is TRUE and teaming failover has occurred inside the VM, the *CurrentMacAddress* will be equal to the MAC address that was failed over to the network adapter or *PermanentMacAddress* if no failover has occurred.

### `VFAssigned`

A **BOOLEAN** value that, if set to **TRUE**, specifies that the network adapter is attached to a PCI Express (PCIe) virtual function (VF). A VF is exposed by an underlying physical network adapter that supports the single root I/O virtualization (SR-IOV) interface.

For more information, see the Remarks section.

**Note** The **VFAssigned** member is valid only if the **NicType** member contains a value of **NdisSwitchNicTypeEmulated** or **NdisSwitchNicTypeSynthetic**. This member must be set to **FALSE** if the **NicType** member contains a value of **NdisSwitchNicTypeExternal** or **NdisSwitchNicTypeInternal**.

### `NdisReserved[2]`

### `VMFriendlyName`

An NDIS_VM_FRIENDLYNAME value that specifies the external name of the Hyper-V child partition that is attached to the VF. This member contains the user-friendly description of the partition.

## Remarks

OID query requests of [OID_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-array) return an [NDIS_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_array) structure that contains zero or more elements. Each element is formatted as an **NDIS_SWITCH_NIC_PARAMETERS** structure.

The **NDIS_SWITCH_NIC_PARAMETERS** structure is also used in the following OID requests:

* [OID_SWITCH_NIC_CREATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-create)
* [OID_SWITCH_NIC_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-connect)
* [OID_SWITCH_NIC_UPDATED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-updated)
* [OID_SWITCH_NIC_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-delete)
* [OID_SWITCH_NIC_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-disconnect)

**Note** The **NDIS_SWITCH_NIC_NAME**, **NDIS_SWITCH_NIC_FRIENDLYNAME**, **NDIS_VM_NAME**, and **NDIS_VM_FRIENDLYNAME** data types are type-defined by the [IF_COUNTED_STRING](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-if_counted_string_lh) structure. A string that is defined by this structure does not have to be null-terminated. However, the length of the string must be set in the **Length** member of this structure. If the string is null-terminated, the **Length** member must not include the terminating null character.

### Guidelines for the **NicType** and **NicName** Members

Based on the value **NicType** member, the format of the **NicName** member is as follows:

* If the **NicType** member is set to **NdisSwitchNicTypeExternal**, the value of the **NicName** member is the unique instance identifier (**InstanceId**) of the physical network adapter that is bound to the external network adapter. This type of network adapter is exposed in the management operating system that runs in the Hyper-V parent partition.

  The external network adapter provides a connection to the physical network interface that is available on the host. The external network adapter can be accessed by the Hyper-V parent partition and all child partitions.

  **Note** The **InstanceId** value is generated by the [Plug and Play manager](https://learn.microsoft.com/windows-hardware/drivers/install/pnp-manager) that runs in the management operating system.
* If the **NicType** member is set to **NdisSwitchNicTypeInternal**, the value of the **NicName** member is the device display name that identifies the internal network adapter. This type of network adapter is exposed in the management operating system of a Hyper-V parent partition.

  The internal network adapter can be accessed by the Hyper-V parent partition and all child partitions. However, the internal network adapter does not connect to the physical network interface that is available on the host.

  **Note** The device display name is generated by the Hyper-V WMI management layer that runs in the management operating system.
* For all other **NicType** member values, the value of the **NicName** member is uniquely assigned to the synthetic or emulated network adapter by the policy management interface.
  These types of network adapters are exposed in the guest operating system that runs is a Hyper-V child partition.

### Guidelines for the **VFAssigned** Member

A PCIe VF is created and allocated by an underlying physical adapter that supports the SR-IOV interface. After the PCIe VF is created, the virtualization stack attaches, or *assigns*, a Hyper-V child partition to the VF. The guest operating system that runs in this partition exposes a virtual machine (VM) network adapter that is attached, or *assigned* to the underlying SR-IOV physical adapter.

If the **VFAssigned** member is set to **TRUE**, packets are routed directly between the underlying SR-IOV physical network adapter and the virtual adapter. However, because the extensible switch is not involved in packet delivery, extensible switch port policies, such as access control lists (ACLs), are not applied to these packets.

The extension can remove a VF assignment by issuing an [NDIS_STATUS_SWITCH_PORT_REMOVE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-switch-port-remove-vf) status indication. This indication causes the packets to be delivered through an extensible switch port instead of directly between the VM network adapter and the SR-IOV physical adapter. This allows the extensible switch port policies to be applied to packets that are received or sent over the extensible switch port. When the extension makes the **NDIS_STATUS_SWITCH_PORT_REMOVE_VF** status indication, it specifies which extensible switch port the virtual network adapter is connected to.

For more information, see [NDIS_STATUS_SWITCH_PORT_REMOVE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-switch-port-remove-vf).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_STATUS_SWITCH_PORT_REMOVE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-switch-port-remove-vf)

[NDIS_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_array)

[NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters)

[NDIS_SWITCH_NIC_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_nic_state)

[NDIS_SWITCH_NIC_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_nic_type)

[OID_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-array)

[OID_SWITCH_NIC_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-connect)

[OID_SWITCH_NIC_CREATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-create)

[OID_SWITCH_NIC_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-delete)

[OID_SWITCH_NIC_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-disconnect)

[OID_SWITCH_NIC_SAVE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-save)

[OID_SWITCH_NIC_SAVE_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-save-complete)

[OID_SWITCH_NIC_UPDATED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-updated)