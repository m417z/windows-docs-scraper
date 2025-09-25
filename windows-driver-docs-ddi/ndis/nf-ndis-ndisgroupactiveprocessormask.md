# NdisGroupActiveProcessorMask function

## Description

The
**NdisGroupActiveProcessorMask** function returns the currently active processor mask for the specified
group.

## Parameters

### `Group`

A USHORT value that identifies a processor group in the local computer system.

## Return value

**NdisGroupActiveProcessorMask** returns the currently active processor mask for the specified group
as a
**KAFFINITY** bitmap. In an environment that allows for hot-add functionality, this bitmap can change
during runtime.

## Remarks

An NDIS driver might call the
**NdisGroupActiveProcessorMask** function during initialization before it allocates resources.

The
**KAFFINITY** value that
**NdisGroupActiveProcessorMask** returns can change at runtime on SKUs that support hot-add
functionality for CPUs.

**Note** NDIS drivers should not use the
[NdisSystemProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemprocessorcount) function
to retrieve the number of currently active processors. Also, NDIS 6.20 and later drivers should not use
the
[NdisSystemActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemactiveprocessorcount) function because it only returns the processor count and provides
the affinity mask as an out parameter, for processor group 0.

To obtain an active processor count, call the
[NdisGroupActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupactiveprocessorcount) function.

## See also

[NdisGroupActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupactiveprocessorcount)

[NdisSystemActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemactiveprocessorcount)

[NdisSystemProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemprocessorcount)