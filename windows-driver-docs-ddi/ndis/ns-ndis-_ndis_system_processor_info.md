# _NDIS_SYSTEM_PROCESSOR_INFO structure

## Description

The **NDIS_SYSTEM_PROCESSOR_INFO** structure specifies information about the CPU topology of the local
computer and the receive side scaling (RSS) processor set.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_SYSTEM_PROCESSOR_INFO structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_SYSTEM_PROCESSOR_INFO_REVISION_1, and the
**Size** member to NDIS_SIZEOF_SYSTEM_PROCESSOR_INFO_REVISION_1.

### `Flags`

Reserved. Set this member to zero.

### `ProcessorVendor`

The processor vendor specified as one of the values from the
[NDIS_PROCESSOR_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_processor_vendor) enumeration.

### `NumPhysicalPackages`

The total number of processor physical packages that are in the local computer.

### `NumCores`

The total number of core processors that are in the local computer. For example, set this member
to four if there are two dual core physical packages.

### `NumCoresPerPhysicalPackage`

The number of core processors that are in each physical package. For example, set this member to
two for a dual core physical package.

### `MaxHyperThreadingCpusPerCore`

The maximum number of logical processors that are in each hyper-threaded core processor. For
example, set this member to two if each hyper-threaded core processor supports two logical
processors.

### `RssBaseCpu`

The starting CPU number that is used for RSS.

### `RssCpuCount`

The number of processors that are used for RSS.

### `RssProcessors`

A pointer to an optional caller-provided buffer that will contain the CPU numbers of the
processors that can be used for RSS. Set this member to **NULL** if the CPU numbers are not required. To
obtain CPU numbers, this member must contain a valid pointer and the size of this buffer must be at
least
**MAXIMUM_PROCESSORS * sizeof (UCHAR)**. After the
[NdisGetProcessorInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetprocessorinformation) function returns successfully, the buffer contains CPU numbers
followed by undefined data.

### `CpuInfo`

An array of
[NDIS_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_processor_info) structures. After
the
**NdisGetProcessorInformation** function returns successfully, this array provides information for
each processor in the local computer. The number of values in the array is equal to the number of
processors in the local computer, as the
[NdisSystemActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemactiveprocessorcount) function reports.

## Remarks

NDIS network drivers use the NDIS_SYSTEM_PROCESSOR_INFO structure in calls to the
[NdisGetProcessorInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetprocessorinformation) function. After
**NdisGetProcessorInformation** returns, this structure contains information about the CPU topology of
the system and the set of processors that will be used for receive side scaling (RSS).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_processor_info)

[NDIS_PROCESSOR_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_processor_vendor)

[NDIS_SYSTEM_PROCESSOR_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_system_processor_info_ex)

[NdisGetProcessorInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetprocessorinformation)

[NdisSystemActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemactiveprocessorcount)