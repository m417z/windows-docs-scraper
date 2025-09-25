## Description

KeGetCurrentProcessorIndex returns the index of the processor that the caller is running on.

## Return value

KeGetCurrentProcessorIndex returns the system wide index of the logical processor the caller is running on.

## Remarks

KeGetCurrentProcessorIndex is similar to KeGetCurrentProcessorNumber but rather than returning a PROCESSOR_NUMBER structure or a group relative index KeGetCurrentProcessorIndex behaves as if all the processors on the system were numbered 0..N-1 and returns a value between 0 and N-1 inclusive. The index is not guaranteed to be less than the result of KeQueryActiveProcessorCount but will be less than the result of KeQueryActiveProcessorCountEx(ALL_PROCESSOR_GROUPS).

## See also

[KeGetCurrentProcessorNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kegetcurrentprocessornumber)

[KeGetCurrentProcessorNumberEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kegetcurrentprocessornumberex)

[KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount)

[KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex)