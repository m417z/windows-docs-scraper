# _NDIS_NIC_SWITCH_CAPABILITIES structure

## Description

The **NDIS_NIC_SWITCH_CAPABILITIES** structure specifies the capabilities of a NIC switch on the network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_CAPABILITIES** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_CAPABILITIES** structure, the driver must set the **Revision** member of **Header** to one of the following values:

#### NDIS_NIC_SWITCH_CAPABILITIES_REVISION_3

Added the RSS interface members for NDIS 6.60.

**Note** Revision 3 of this structure is supported only on Windows Server 2016 and later versions of Windows Server.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_CAPABILITIES_REVISION_3.

#### NDIS_NIC_SWITCH_CAPABILITIES_REVISION_2

Added the single root I/O virtualization (SR-IOV) interface members for NDIS 6.30.

**Note** Revision 2 of this structure is supported only on Windows Server 2012 and later versions of Windows Server.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_CAPABILITIES_REVISION_2.

#### NDIS_NIC_SWITCH_CAPABILITIES_REVISION_1

Original version for NDIS 6.20.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_CAPABILITIES_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `NdisReserved1`

Reserved for NDIS.

### `NumTotalMacAddresses`

A ULONG value that contains the total number of media access control (MAC) addresses that the network adapter supports.

**Note** Drivers must set this member to zero for revision 2 and later revisions of this structure.

### `NumMacAddressesPerPort`

A ULONG value that contains the number of MAC addresses that are supported for each port.

**Note** Drivers must set this member to zero for revision 2 and later revisions of this structure.

### `NumVlansPerPort`

A ULONG value that contains the number of VLANs that are supported for each port.

**Note** Drivers must set this member to zero for revision 2 and later revisions of this structure.

### `NdisReserved2`

Reserved for NDIS.

### `NdisReserved3`

Reserved for NDIS.

### `NicSwitchCapabilities`

A ULONG value that contains a bitwise OR of the following flags that specify the capabilities of the NIC switch:

#### NDIS_NIC_SWITCH_CAPS_RSS_ON_PF_VPORTS_SUPPORTED

**Note** This flag is supported in Windows Server 2016 and later. It was introduced in NDIS 6.60.

Specifies that the NIC supports VMMQ for PF VPorts.

#### NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_INDIRECTION_TABLE_SUPPORTED

**Note** This flag is supported in Windows Server 2016 and later. It was introduced in NDIS 6.60.

If set to **1**, specifies that the NIC is able to maintain per-PF VPort indirection tables.

#### NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_HASH_FUNCTION_SUPPORTED

**Note** This flag is supported in Windows Server 2016 and later. It was introduced in NDIS 6.60.

If set to **1**, specifies that the NIC supports setting a different hash function per PF VPort. If this flag is set, **NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_HASH_KEY_SUPPORTED** must be set as well.

#### NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_HASH_TYPE_SUPPORTED

**Note** This flag is supported in Windows Server 2016 and later. It was introduced in NDIS 6.60.

If set to **1**, specifies that the NIC supports setting different hash types per PF VPort.

#### NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_HASH_KEY_SUPPORTED

**Note** This flag is supported in Windows Server 2016 and later. It was introduced in NDIS 6.60.

If set to **1**, specifies that the NIC supports setting a different hash secret key per PF VPort. This flag must be set if **NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_HASH_FUNCTION_SUPPORTED** is set.

#### NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_INDIRECTION_TABLE_SIZE_RESTRICTED

**Note** This flag is supported in Windows Server 2016 and later. It was introduced in NDIS 6.60.

If set to **1**, specifies that the NIC has a limitation on indirection table size for PF VPorts. This flag forces the issuer of an RSS OID to use a per-PF VPort indirection table size equal to the number of VPort queues rounded up to the next power of two. This only applies to PF VPorts and does not apply to VF VPorts. This flag can be combined with the **NDIS_NIC_SWITCH_CAPS_ASYMMETRIC_QUEUE_PAIRS_FOR_NONDEFAULT_VPORT_SUPPORTED** flag (different PF VPorts can have different numbers of queues). This flag prevents VMMQ users from performing fine-grained queue steering.

#### NDIS_NIC_SWITCH_CAPS_NIC_SWITCH_WITHOUT_IOV_SUPPORTED

**Note** This flag is supported in Windows Server 2016 and later.

This flag, introduced with NDIS 6.60, specifies that a NIC switch can be created without the use of SR-IOV. This flag allows for separating a NIC switch from the \*SRIOV keyword, meaning that a NIC switch can be created via [OID_NIC_SWITCH_CREATE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-switch) even if \*SRIOV = 0.

For more information about reporting NIC switch capabilities for NDIS 6.60 and later miniport drivers, see [Determining NIC Switch Capabilities](https://learn.microsoft.com/windows-hardware/drivers/network/determining-nic-switch-capabilities).

#### NDIS_NIC_SWITCH_CAPS_VLAN_SUPPORTED

This flag specifies that the NIC switch supports hardware packet filtering based on the virtual local area network (VLAN) identifier (ID).

**Note** This flag should be set only if the NIC switch supports VLAN ID filtering on individual SR-IOV virtual ports (VPorts).

#### NDIS_NIC_SWITCH_CAPS_PER_VPORT_INTERRUPT_MODERATION_SUPPORTED

This flag specifies that the NIC switch can support interrupt moderation configuration on individual VPorts.

#### NDIS_NIC_SWITCH_CAPS_ASYMMETRIC_QUEUE_PAIRS_FOR_NONDEFAULT_VPORT_SUPPORTED

This flag specifies that the NIC switch can configure a different number of queue pairs for each nondefault VPort. This means that each nondefault VPort can be configured asymmetrically to have a different number of queue pairs.

If this flag is not set, all nondefault VPorts must be configured symmetrically to have the same number of queue pairs.

Regardless of whether this flag is set, the NIC switch must support the ability to set the number of queue pairs on the default VPort. These may differ from the number of queue-pairs that are set on the nondefault VPorts.

**Note** A queue pair consists of a transmit queue and receive queue. Queue pairs associated with the default VPort are configured at the time of switch creation through an OID method request of [OID_NIC_SWITCH_CREATE_SWITCH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-switch).
One or more queue pairs are configured on a nondefault VPort through an OID method request of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).

For more information, see [Symmetric and Asymmetric Assignment of Queue Pairs](https://learn.microsoft.com/windows-hardware/drivers/network/symmetric-and-asymmetric-assignment-of-queue-pairs).

#### NDIS_NIC_SWITCH_CAPS_VF_RSS_SUPPORTED

This flag specifies that queue pairs from nondefault VPorts that are attached to a PCI Express (PCIe) Virtual Function (VF) can be used for receive side scaling (RSS). The VF miniport driver runs in the guest operating system of a Hyper-V child partition.

If this flag is set, the miniport driver supports RSS on a VF and can use one or more of the queue pairs from the nondefault VPort for RSS.

**Note** Starting with Windows Server 2012, only one nondefault VPort can be attached to a VF.

#### NDIS_NIC_SWITCH_CAPS_SINGLE_VPORT_POOL

This flag specifies that the nondefault VPorts can be created in a non-reserved manner from the VPort pool on the network adapter. This allows available nondefault VPorts to be created and assigned on an as-needed basis to the PF and allocated VFs. If the network adapter supports the virtual machine queue (VMQ) interface, nondefault VPorts that are assigned to the PF can also be used for VM receive queues.

**Note** The default VPort is always reserved for assignment to the PF.

If this flag is set, available nondefault VPorts are created and assigned to the PF and allocated VFs. However, this mechanism does not reserve nondefault VPorts for VF creation and assignment. As a result, situations may occur where a VF may not be assigned a VPort if the pool has been exhausted of available VPorts.

**Note** If a VF cannot be assigned a VPort, packet traffic over the VF occurs over the SR-IOV synthetic data path. For more information about this data path, see [SR-IOV Data Paths](https://learn.microsoft.com/windows-hardware/drivers/network/sr-iov-data-paths).

If this flag is not set, the creation and assignment of nondefault VPorts is reserved for VF assignment. Additional nondefault VPorts can be created and assigned to the PF.

For more information about VMQ, see [Virtual Machine Queue (VMQ)](https://learn.microsoft.com/windows-hardware/drivers/network/virtual-machine-queue-architecture).

For more information about VPorts, see [Managing Virtual Ports](https://learn.microsoft.com/windows-hardware/drivers/network/managing-virtual-ports).

### `MaxNumSwitches`

A ULONG value that specifies the maximum number of switches that can be created on the network adapter's PCI Express (PCIe) Physical Function (PF).

**Note** Starting with Windows Server 2012, Windows only supports the default NIC switch on the network adapter. Therefore, this member must always be set to one.

### `MaxNumVPorts`

A ULONG value that specifies the maximum number of VPorts that can be created on a network adapter. This includes the default VPort that is always attached to the PF.

**Note** The NIC switch must support at least (**MaxNumVFs** + 1) VPorts.

### `NdisReserved4`

Reserved for NDIS.

### `MaxNumVFs`

A ULONG value that specifies the maximum number of VFs that can be created on the NIC switch.

**Note** Depending on the available hardware resources on the network adapter, the miniport driver can set the **MaxNumVFs** member to a value that is less than its ***NumVFs**
keyword. For more information about this keyword, see [Standardized INF Keywords for SR-IOV](https://learn.microsoft.com/windows-hardware/drivers/network/standardized-inf-keywords-for-sr-iov).

### `MaxNumQueuePairs`

A ULONG value that specifies the maximum number of queue pairs that can be assigned to all VPorts. This includes the default VPort that is attached to the PF.

**Note** This value must be greater than or equal to the value of **MaxNumVPorts**.

### `NdisReserved5`

Reserved for NDIS.

### `NdisReserved6`

Reserved for NDIS.

### `NdisReserved7`

Reserved for NDIS.

### `MaxNumQueuePairsPerNonDefaultVPort`

A ULONG value that specifies the maximum number of queue pairs that can be assigned to a nondefault VPort.

This value is specified in powers of 2, and provides for asymmetric configuration and assignment of queue pairs to VPorts. For more information, see [Symmetric and Asymmetric Assignment of Queue Pairs](https://learn.microsoft.com/windows-hardware/drivers/network/symmetric-and-asymmetric-assignment-of-queue-pairs).

### `NdisReserved8`

Reserved for NDIS.

### `NdisReserved9`

Reserved for NDIS.

### `NdisReserved10`

Reserved for NDIS.

### `NdisReserved11`

Reserved for NDIS.

### `NdisReserved12`

Reserved for NDIS.

### `MaxNumMacAddresses`

A ULONG value that specifies the maximum number of unicast MAC address filters that are available on the NIC switch.

**Note** This value must be greater than or equal to the value of **MaxNumVPorts**. This enables each VPort (including the default VPort) to be configured to have at least one unicast MAC address filter.

### `NdisReserved13`

Reserved for NDIS.

### `NdisReserved14`

Reserved for NDIS.

### `NdisReserved15`

Reserved for NDIS.

### `NdisReserved16`

Reserved for NDIS.

### `NdisReserved17`

Reserved for NDIS.

### `MaxNumRssCapableNonDefaultPFVPorts`

A ULONG value that specifies the maximum number of RSS-capable non-default PFVPorts.

### `NumberOfIndirectionTableEntriesForDefaultVPort`

A ULONG value that specifies the number of indirection table entries for the default VPort.

### `NumberOfIndirectionTableEntriesPerNonDefaultPFVPort`

A ULONG value that specifies the number of indirection table entries for each non-default PFVPort.

### `MaxNumQueuePairsForDefaultVPort`

A ULONG value that specifies the maximum number of queue pairs that can be assigned to the default VPort.

This value is specified in powers of 2, and provides for asymmetric configuration and assignment of queue pairs to VPorts. For more information, see [Symmetric and Asymmetric Assignment of Queue Pairs](https://learn.microsoft.com/windows-hardware/drivers/network/symmetric-and-asymmetric-assignment-of-queue-pairs).

## Remarks

 The **NDIS_NIC_SWITCH_CAPABILITIES** structure is used in the
members of the following structures:

* The **HardwareNicSwitchCapabilities** and
  **CurrentNicSwitchCapabilities** members of the
  [NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes) structure.
* The
  **NicSwitchCapabilities** member of the
  [NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) and
  [NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structures.

OID query requests of [OID_NIC_SWITCH_CURRENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-current-capabilities) and
[OID_NIC_SWITCH_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-hardware-capabilities) return an **NDIS_NIC_SWITCH_CAPABILITIES** structure.

## See also

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport)

[OID_NIC_SWITCH_CURRENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-current-capabilities)

[OID_NIC_SWITCH_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-hardware-capabilities)