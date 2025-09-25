# _NDIS_HYPERVISOR_PARTITION_TYPE enumeration

## Description

**Important**

Starting with Windows 10 Version 1703, NDIS_HYPERVISOR_PARTITION_TYPE is deprecated and should not be used. Drivers are encouraged to move away from it, as it may not be available in future versions of the operating system.

Drivers should instead follow a hypervisor's instructions to query hypervisor presence and capabilities. For example, Hyper-V's instructions are documented in the [Top-Level Functional Specification](https://learn.microsoft.com/virtualization/hyper-v-on-windows/reference/tlfs).

The **NDIS_HYPERVISOR_PARTITION_TYPE** enumeration identifies the current partition type that is running
on the hypervisor.

## Constants

### `NdisHypervisorPartitionTypeUnknown`

The partition type that is running on the hypervisor is not known.

**Note** This enumeration value is used to identify a partition type for a third-party hypervisor.

### `NdisHypervisorPartitionTypeMsHvParent`

The parent partition (also known as the root partition) is running
on the Microsoft hypervisor.

### `NdisHypervisorPartitionMsHvChild`

The child partition is running on
the Microsoft hypervisor.

### `NdisHypervisorPartitionTypeMax`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

For more information about Hyper-V parent and child partitions, see [Virtualized Networking Concepts and Terms](https://learn.microsoft.com/windows-hardware/drivers/network/virtualized-networking-concepts-and-terms).

## See also

[NDIS_HYPERVISOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_hypervisor_info)