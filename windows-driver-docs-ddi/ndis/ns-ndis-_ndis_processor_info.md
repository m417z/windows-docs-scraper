# _NDIS_PROCESSOR_INFO structure

## Description

The **NDIS_PROCESSOR_INFO** structure specifies information about a processor in the local
computer.

## Members

### `CpuNumber`

The CPU number that is assigned to the processor. The value is in the range from zero through the
number of active CPUs minus one.

### `PhysicalPackageId`

The physical package ID of the processor. The value is in the range from zero through the number
in the
**NumPhysicalPackages** member of the
[NDIS_SYSTEM_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_system_processor_info) structure minus one.

### `CoreId`

The core ID of the processor. The value is in the range from zero through the number in the
**NumCoresPerPhysicalPackage** member of the NDIS_SYSTEM_PROCESSOR_INFO structure minus one.

### `HyperThreadID`

The hyper-threading ID of the processor. The value is in the range from zero through the number in
the
**MaxHyperThreadingCpusPerCore** member of the NDIS_SYSTEM_PROCESSOR_INFO structure minus one.

## Remarks

The NDIS_PROCESSOR_INFO structure is used in the
[NDIS_SYSTEM_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_system_processor_info) structure.

## See also

[NDIS_PROCESSOR_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_processor_info_ex)

[NDIS_SYSTEM_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_system_processor_info)