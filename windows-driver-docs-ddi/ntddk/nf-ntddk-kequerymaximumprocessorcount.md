# KeQueryMaximumProcessorCount function (ntddk.h)

## Description

The **KeQueryMaximumProcessorCount** routine returns the maximum number of processors.

## Return value

**KeQueryMaximumProcessorCount** returns the maximum number of processors as a ULONG value.

## Remarks

The value returned by the **KeQueryMaximumProcessorCount** routine does not change at runtime.

If your code uses an array of buffers, one buffer for each processor, you must decide whether to have a statically sized array based on **KeQueryMaximumProcessorCount** or a dynamically sized array based on [KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount).

To optimize based on the number of processors, you need a resizable structure for Windows Server 2008. In this case, use **KeQueryActiveProcessorCount**.

If you are not optimizing and if the data structures that result from using maximum processor count are relatively small, a resizable structure is not necessary. In this case, use **KeQueryMaximumProcessorCount** to determine size for a static array.

Windows 7 and later versions of Windows support processor groups. Drivers that are designed to handle information about processor groups should use the [KeQueryMaximumProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerymaximumprocessorcountex) routine, which specifies a processor group, instead of **KeQueryMaximumProcessorCount**, which does not. However, the implementation of **KeQueryMaximumProcessorCount** in Windows 7 and later versions of Windows provides compatibility for drivers that were written for earlier versions of Windows, which do not support processor groups. In this implementation, **KeQueryMaximumProcessorCount** returns the maximum number of logical processors that can be in group 0.

## See also

[KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount)

[KeQueryMaximumProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerymaximumprocessorcountex)