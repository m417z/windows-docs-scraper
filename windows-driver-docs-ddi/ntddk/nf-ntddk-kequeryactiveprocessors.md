# KeQueryActiveProcessors function (ntddk.h)

## Description

The **KeQueryActiveProcessors** routine returns a bitmask of the currently active processors.

## Return value

**KeQueryActiveProcessors** returns a [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity) value that represents the set of currently active processors.

## Remarks

Callers cannot assume that **KeQueryActiveProcessors** maps processors to bits consecutively, or that the routine consistently uses the same mapping each time it is called. The only valid use for the return value is to determine the number of active processors by counting the number of bits that are set.

Callers must also be aware that the value returned by **KeQueryActiveProcessors** can change during runtime on versions of Windows that support hot-add CPU functionality.

Windows 7 and later versions of Windows support processor groups. Drivers that are designed to handle information about processor groups should use the [KeQueryGroupAffinity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerygroupaffinity) routine, which specifies a processor group, instead of **KeQueryActiveProcessors**, which does not. However, the implementation of **KeQueryActiveProcessors** in Windows 7 and later versions of Windows provides compatibility for drivers that were written for earlier versions of Windows, which do not support processor groups. In this implementation, **KeQueryActiveProcessors** returns an affinity mask that specifies the set of active logical processors in group 0.

In Windows Vista and later versions of Windows, this routine can be called at any IRQL. However, in Windows Server 2003 and earlier versions of Windows, this routine must be called at IRQL <= APC_LEVEL.

The **KeNumberProcessors** kernel variable is obsolete in Windows Vista with Service Pack 1 (SP1), Windows Server 2008, and later versions of Windows. **KeNumberProcessors** does not appear in WDK headers for WDK releases starting with Windows Vista SP1; however, the variable is still exported from the kernel, so drivers built for earlier platforms will not break

Windows Server 2008 includes support for [Dynamic Hardware Partitioning](https://learn.microsoft.com/windows-hardware/drivers/kernel/dynamic-hardware-partitioning-architecture) (DHP) in the Windows Datacenter and Enterprise Edition SKUs. As part of DHP, Windows Server 2008 supports hot adding CPUs at runtime. In a hot-add CPU environment, the number of processors may not remain constant during runtime.

Accordingly, in Windows Server 2008, code that can determine the number of processors must use **KeQueryActiveProcessors** instead of direct references to the kernel variable, **KeNumberProcessors**.

Review any code that currently references **KeNumberProcessors** to make sure that it accommodates changes to CPU count in hot-add CPU environments.

You can use the [PNPCPU](https://learn.microsoft.com/windows-hardware/drivers/devtest/pnpcpu) tool to simulate hot adding a CPU for testing purposes.

```cpp
#if (NTDDI_VERSION >= NTDDI_VISTA)
extern NTSYSAPI volatile CCHAR KeNumberProcessors;
#else
#if (NTDDI_VERSION >= NTDDI_WINXP)
extern NTSYSAPI CCHAR KeNumberProcessors;
#else
extern PCCHAR KeNumberProcessors;
#endif
#endif
```

Starting with Windows XP, **KeNumberProcessors** is an 8-bit integer value that indicates the number of processors in the platform. In earlier versions of Windows, **KeNumberProcessors** is a pointer to an 8-bit integer value that indicates the number of processors in the platform.

## See also

[KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount)

[KeQueryGroupAffinity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerygroupaffinity)