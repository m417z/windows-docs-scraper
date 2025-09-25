# KeGetCurrentProcessorNumber function

## Description

The **KeGetCurrentProcessorNumber** routine returns the system-assigned number of the current processor on which the caller is running.

## Return value

**KeGetCurrentProcessorNumber** returns a ULONG value that represents the processor on which the caller is currently running.

## Remarks

**KeGetCurrentProcessorNumber** can be called to debug spin lock usage on SMP machines during driver development. A driver also might call **KeGetCurrentProcessorNumber** if it maintained some per-processor data and attempted to reduce cache-line contention.

The number of processors in an SMP machine is a zero-based value.

Windows 7 and later versions of Windows support processor groups. Drivers that are designed to handle information about processor groups should use the [KeGetCurrentProcessorNumberEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kegetcurrentprocessornumberex) routine, which specifies a processor group, instead of **KeGetCurrentProcessorNumber**, which does not. However, the implementation of **KeGetCurrentProcessorNumber** in Windows 7 and later versions of Windows provides compatibility for drivers that were written for earlier versions of Windows. In this implementation, **KeGetCurrentProcessorNumber** returns the group-relative processor number if the caller is running on a processor in group 0, which is compatible with the behavior of this routine in earlier versions of Windows that do not support processor groups. If the caller is running on a processor in any group other than group 0, this routine returns a number that is less than the number of processors in group 0. This behavior ensures that the return value is less than the return value of the [KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount) routine.

If the call to **KeGetCurrentProcessorNumber** occurs at IRQL <= APC_LEVEL, a processor switch can occur between instructions. Consequently, callers of **KeGetCurrentProcessorNumber** usually run at IRQL >= DISPATCH_LEVEL.

## See also

[KeGetCurrentProcessorNumberEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kegetcurrentprocessornumberex)

[KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount)