# NdisSystemProcessorCount function

## Description

The
**NdisSystemProcessorCount** function determines whether the caller is running on a uniprocessor or
multiprocessor computer.

## Return value

**NdisSystemProcessorCount** returns the number of processors in the computer.

## Remarks

An NDIS driver can call the
**NdisSystemProcessorCount** function to retrieve the maximum number of processors in the local
computer. To retrieve the number of currently active processors, the driver must call the
[NdisSystemActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemactiveprocessorcount) function.

**NdisSystemProcessorCount** is similar to the
[KeQueryMaximumProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerymaximumprocessorcount) function.

The value that
**NdisSystemProcessorCount** returns does not change at runtime.

If your code uses an array of buffers, one buffer for each processor, you must decide whether to have
a statically sized array based on
**NdisSystemProcessorCount** or a dynamically sized array based on
[NdisSystemActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemactiveprocessorcount).

To optimize your code based on the number of processors, you must use a resizable structure. In this
case, use
[NdisSystemActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemactiveprocessorcount).

If you are not optimizing and if the data structures that result from using the maximum processor
count are relatively small, a resizable structure is not necessary. In this case, use
**NdisSystemProcessorCount** to determine the size for a static array.

## See also

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[KeQueryMaximumProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerymaximumprocessorcount)

[NdisGroupMaxProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupmaxprocessorcount)

[NdisSystemActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemactiveprocessorcount)