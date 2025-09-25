# NdisGroupActiveProcessorCount function

## Description

The
**NdisGroupActiveProcessorCount** function returns the number of processors that are currently active in
a specified group.

## Parameters

### `Group`

A USHORT value that identifies a processor group in the local computer system.

## Return value

**NdisGroupActiveProcessorCount** returns a ULONG value for the number of processors that are active
in the group that is specified in the
*Group* parameter. The number of processors is a zero-based value.

If the
*Group* parameter is ALL_PROCESSOR_GROUPS,
**NdisGroupActiveProcessorCount** returns the number of active processors in the local computer.

## Remarks

An NDIS driver might call the
**NdisGroupActiveProcessorCount** function during initialization before it allocates resources.

The processor count that
[NdisGroupActiveProcessorMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupactiveprocessormask) returns can change at runtime on SKUs that support hot-add
functionality for CPUs.

**Note** NDIS drivers should not use the
[NdisSystemProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemprocessorcount) function
to retrieve the number of processors that are currently active. Also, NDIS 6.20 drivers should not use
the
[NdisSystemActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemactiveprocessorcount) function because it only returns the processor count and provides
the affinity mask as an out parameter, for processor group 0.

To obtain an active affinity mask, call the
[NdisGroupActiveProcessorMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupactiveprocessormask) function.

To obtain the maximum number of processors in a group, call the
[NdisGroupMaxProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupmaxprocessorcount) function.

## See also

[NdisGroupActiveProcessorMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupactiveprocessormask)

[NdisGroupMaxProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupmaxprocessorcount)

[NdisSystemActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemactiveprocessorcount)

[NdisSystemProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemprocessorcount)