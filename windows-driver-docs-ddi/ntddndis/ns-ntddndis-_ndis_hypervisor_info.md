# _NDIS_HYPERVISOR_INFO structure

## Description

**Important**

Starting with Windows 10 Version 1703, NDIS_HYPERVISOR_INFO is deprecated and should not be used. Drivers are encouraged to move away from it, as it may not be available in future versions of the operating system.

Drivers should instead follow a hypervisor's instructions to query hypervisor presence and capabilities. For example, Hyper-V's instructions are documented in the [Top-Level Functional Specification](https://learn.microsoft.com/virtualization/hyper-v-on-windows/reference/tlfs).

The **NDIS_HYPERVISOR_INFO** structure contains information about the hypervisor that is present on the
system.

## Members

### `Header`

The type, revision, and size of the **NDIS_HYPERVISOR_INFO** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_HYPERVISOR_INFO** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_HYPERVISOR_INFO_REVISION_1

Original version for NDIS 6.20.

Set the **Size** member to NDIS_SIZEOF_HYPERVISOR_INFO_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of the following flag.

#### NDIS_HYPERVISOR_INFO_FLAG_HYPERVISOR_PRESENT

Specifies that a hypervisor is present on the system.

### `PartitionType`

An
[NDIS_HYPERVISOR_PARTITION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_hypervisor_partition_type) enumeration value that specifies the partition type that is running
on the hypervisor.

## Remarks

The **NDIS_HYPERVISOR_INFO** structure specifies the hypervisor information that is returned by the
[NdisGetHypervisorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgethypervisorinfo) function.

NDIS drivers pass this structure to the
**NdisGetHypervisorInfo** function.

## See also

[NDIS_HYPERVISOR_PARTITION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_hypervisor_partition_type)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisGetHypervisorInfo Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgethypervisorinfo)