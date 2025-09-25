# KeGetCurrentProcessorNumberEx function (ntddk.h)

## Description

The **KeGetCurrentProcessorNumberEx** routine gets the processor number of the logical processor that the caller is running on.

## Parameters

### `ProcNumber` [out, optional]

A pointer to a caller-allocated buffer into which the routine writes a [PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number) structure that identifies the current logical processor. This structure contains the group number and the group-relative processor number. You can set this parameter to **NULL** if you do not need this information.

## Return value

**KeGetCurrentProcessorNumberEx** returns the systemwide processor index of the logical processor that the caller is running on.

## Remarks

If *ProcNumber* is non-**NULL**, the buffer that is pointed to by *ProcNumber* must be large enough to contain a PROCESSOR_NUMBER structure. In contrast to this structure, which contains a group number and a group-relative processor number, the return value is a processor index that identifies the processor across the entire multiprocessor system.

For example, if a multiprocessor system contains two groups, and each group contains 64 logical processors, the processor numbers in each group range from 0 to 63, but the systemwide processor indexes range from 0 to 127.

A related routine, [KeGetCurrentProcessorNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kegetcurrentprocessornumber), returns the current processor number, but this routine, unlike **KeGetCurrentProcessorNumberEx**, does not provide a group number for the processor. In Windows 7 and later versions of the Windows operating system, **KeGetCurrentProcessorNumber** returns the group-relative processor number if the caller is running on a processor in group 0, which is compatible with the behavior of this routine in earlier versions of Windows that do not support groups. However, if the caller is running on a processor in any group other than group 0, this routine returns a number that is less than the number of processors in group 0. This behavior ensures that the return value is less than the return value of the [KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount) routine. Existing drivers that call **KeGetCurrentProcessorNumber** and that use no group-oriented features run correctly in multiprocessor systems that have two or more groups. However, drivers that use any group-oriented features in Windows 7 and later versions of the Windows operating system should call **KeGetCurrentProcessorNumberEx** instead of **KeGetCurrentProcessorNumber**.

## See also

[KeGetCurrentProcessorNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kegetcurrentprocessornumber)

[KeQueryActiveProcessorCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcount)

[PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number)