# NdisGetHypervisorInfo function

## Description

**Important**

Starting with Windows 10 Version 1703, NdisGetHypervisorInfo is deprecated and should not be used. Drivers are encouraged to move away from it, as it may not be available in future versions of the operating system.

Drivers should instead follow a hypervisor's instructions to query hypervisor presence and capabilities. For example, Hyper-V's instructions are documented in the [Top-Level Functional Specification](https://learn.microsoft.com/virtualization/hyper-v-on-windows/reference/tlfs).

The **NdisGetHypervisorInfo** function returns information about the hypervisor that is present on the system.

## Parameters

### `HypervisorInfo` [in, out]

A pointer to a caller-allocated [NDIS_HYPERVISOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_hypervisor_info) structure that
contains information about the hypervisor that is present on the system.

## Return value

**NdisGetHypervisorInfo** can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The size of the input parameter buffer was too small. |

## Remarks

NDIS miniport drivers call the
**NdisGetHypervisorInfo** function to determine whether a hypervisor is present on the system.

When the **NdisGetHypervisorInfo** function returns, the *HypervisorInfo* parameter contains a pointer to an [NDIS_HYPERVISOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_hypervisor_info) structure. This structure contains information about whether a hypervisor is present, along with the partition type from which this function was called. The **NDIS_HYPERVISOR_INFO** structure provides this information in the following way:

* If a hypervisor is present, the **NDIS_HYPERVISOR_INFO_FLAG_HYPERVISOR_PRESENT**
  flag is set in the **Flags** member.
* If the Microsoft hypervisor is present, the **PartitionType** member is set to one of the following values:

  + If the **NdisGetHypervisorInfo** function was called from the management operating system that runs in the Hyper-V parent partition, the **PartitionType** member is set to **NdisHypervisorPartitionTypeMsHvParent**.
  + If the **NdisGetHypervisorInfo** function was called from the guest operating system that runs in the Hyper-V child partition, the **PartitionType** member is set to **NdisHypervisorPartitionMsHvChild**.
* If another vendor's hypervisor is present, the **PartitionType** member is set to **NdisHypervisorPartitionTypeUnknown**.

**Note** A driver must initialize the
**Header** member of the [NDIS_HYPERVISOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_hypervisor_info) structure before it calls the **NdisGetHypervisorInfo** function.

## See also

[NDIS_HYPERVISOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_hypervisor_info)