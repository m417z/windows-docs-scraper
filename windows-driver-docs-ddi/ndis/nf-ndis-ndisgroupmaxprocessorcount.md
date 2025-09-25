# NdisGroupMaxProcessorCount function

## Description

The
**NdisGroupMaxProcessorCount** function determines the maximum number of processors in a specified
processor group.

## Parameters

### `Group`

A USHORT value that identifies a processor group in the local computer system.

## Return value

**NdisGroupMaxProcessorCount** returns a ULONG value for the maximum number of processors that are
included in the group that is specified in the
*Group* parameter. The number of processors is a zero-based value.

If the
*Group* parameter is ALL_PROCESSOR_GROUPS,
**NdisGroupMaxProcessorCount** returns the maximum number of processors in the local computer.

## Remarks

An NDIS driver might call the
**NdisGroupMaxProcessorCount** function during initialization before it allocates resources.

**Note** NDIS 6.20 and later drivers should not use the
[NdisSystemProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemprocessorcount) function
because it only returns the processor count for processor group 0.

The processor count can change at runtime on SKUs that support hot-add functionality for CPUs. To
obtain an active processor count, call the
[NdisGroupActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupactiveprocessorcount) function.

## See also

[NdisGroupActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupactiveprocessorcount)

[NdisSystemProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemprocessorcount)