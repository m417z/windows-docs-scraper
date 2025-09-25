# NdisSystemActiveProcessorCount function

## Description

The
**NdisSystemActiveProcessorCount** function returns the number of currently active processors in the
local computer.

## Parameters

### `ActiveProcessors`

A pointer to a
[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)-typed variable that receives a bitmap
that represents the set of currently active processors. In a hot-add environment, this bitmap can change
during runtime.

## Return value

**NdisSystemActiveProcessorCount** returns the number of currently active processors in the local
computer.

## Remarks

An NDIS driver might call the
**NdisSystemActiveProcessorCount** function during initialization before it allocates resources.

**NdisSystemActiveProcessorCount** is similar to the
[KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount) function.

**Note** NDIS drivers should not use
[NdisSystemProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemprocessorcount) to
retrieve the number of currently active processors,

**Note** **NdisSystemActiveProcessorCount** might not map processors to the bits in the returned
[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity) value consecutively. and
**NdisSystemActiveProcessorCount** might not return the same bitmap every time that it is
called.

The value that
**NdisSystemActiveProcessorCount** returns can change at runtime on SKUs that support hot-add CPU
functionality.

The Windows Server 2008 Enterprise operating system and the Windows Server 2008 Datacenter operating
system support
[dynamic hardware
partitioning](https://learn.microsoft.com/windows-hardware/drivers/kernel/dynamic-hardware-partitioning-architecture). As part of dynamic hardware partitioning, Windows Server 2008 supports hot-add
operations for CPUs at runtime. In a hot-add CPU environment, the number of processors might not remain
constant during runtime.

## See also

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)

[KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount)

[NdisGroupActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgroupactiveprocessorcount)

[NdisSystemProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissystemprocessorcount)