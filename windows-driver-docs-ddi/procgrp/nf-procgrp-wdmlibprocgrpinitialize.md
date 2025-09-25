# WdmlibProcgrpInitialize function

## Description

The **WdmlibProcgrpInitialize** function initializes the Processor Group (ProcGrp) compatibility library.

## Remarks

This function initializes the ProcGrp library. Call this function before calling any of the other functions in the ProcGrp library. The library implements wrapper functions that have the same names as the following processor-group **Ke*Xxx*** routines in Windows 7:

[KeGetCurrentProcessorNumberEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kegetcurrentprocessornumberex)

[KeGetProcessorIndexFromNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kegetprocessorindexfromnumber)

[KeGetProcessorNumberFromIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessornumberfromindex)

[KeQueryActiveGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactivegroupcount)

[KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex)

[KeQueryGroupAffinity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerygroupaffinity)

[KeQueryMaximumProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerymaximumprocessorcount)

[KeQueryMaximumProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerymaximumprocessorcountex)

[KeQueryMaximumGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerymaximumgroupcount)

[KeSetSystemAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemaffinitythreadex)

[KeSetSystemGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemgroupaffinitythread)

[KeRevertToUserAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttouseraffinitythreadex)

[KeRevertToUserGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttousergroupaffinitythread)

[KeSetTargetProcessorDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettargetprocessordpcex)

For more information about the ProcGrp library, see [Processor Group Compatibility Library](https://learn.microsoft.com/windows-hardware/drivers/ddi/).