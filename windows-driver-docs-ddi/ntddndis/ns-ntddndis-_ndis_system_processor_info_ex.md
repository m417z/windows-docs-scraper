# _NDIS_SYSTEM_PROCESSOR_INFO_EX structure

## Description

The **NDIS_SYSTEM_PROCESSOR_INFO_EX** structure specifies information about the CPU topology of the local
computer.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_SYSTEM_PROCESSOR_INFO_EX structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_SYSTEM_PROCESSOR_INFO_EX_REVISION_1, and the
**Size** member to NDIS_SIZEOF_SYSTEM_PROCESSOR_INFO_EX_REVISION_1.

### `Flags`

Reserved. NDIS sets this member to zero.

### `ProcessorVendor`

The processor vendor specified as one of the values from the
[NDIS_PROCESSOR_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_processor_vendor) enumeration.

### `NumSockets`

The total number of processor physical packages (that is, sockets on the local computer
motherboard) that are in the local computer.

### `NumCores`

The total number of core processors that are in the local computer. For example, set this member
to four if there are two dual core physical packages.

### `NumCoresPerSocket`

The number of core processors that are in each physical package. For example, set this member to
two for a dual core physical package.

### `MaxHyperThreadingProcsPerCore`

The maximum number of logical processors that are in each hyper-threaded core processor. For
example, set this member to two if each hyper-threaded core processor supports two logical
processors.

### `ProcessorInfoOffset`

The offset, in bytes, from the start of the structure to an array of
[NDIS_PROCESSOR_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_processor_info_ex) structures,
with each entry describing a processor on the computer. The
**NumberOfProcessors** member contains the number of NDIS_PROCESSOR_INFO_EX structures in the array.
The
**ProcessorInfoEntrySize** member contains the size of the NDIS_PROCESSOR_INFO_EX structures in the
array.

### `NumberOfProcessors`

The number of elements in the array of NDIS_PROCESSOR_INFO_EX structures that follows this
structure.

### `ProcessorInfoEntrySize`

The size, in bytes, of elements in the array of NDIS_PROCESSOR_INFO_EX structures that follows
this structure.

## Remarks

NDIS network drivers use the NDIS_SYSTEM_PROCESSOR_INFO_EX structure in calls to the
[NdisGetProcessorInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetprocessorinformationex) function. After
**NdisGetProcessorInformationEx** returns, this structure contains information about the CPU topology
of the system.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PROCESSOR_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_processor_info_ex)

[NDIS_PROCESSOR_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_processor_vendor)

[NDIS_SYSTEM_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_system_processor_info)

[NdisGetProcessorInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetprocessorinformationex)