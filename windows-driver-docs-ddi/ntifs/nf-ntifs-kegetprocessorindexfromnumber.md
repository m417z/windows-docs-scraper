# KeGetProcessorIndexFromNumber function (ntifs.h)

## Description

The **KeGetProcessorIndexFromNumber** routine converts a group number and a group-relative processor number to a systemwide processor index.

## Parameters

### `ProcNumber` [in]

A pointer to a caller-allocated [PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number) structure that contains a group number and a group-relative processor number.

## Return value

**KeGetProcessorIndexFromNumber** returns a systemwide processor index if the call is successful. If *ProcNumber* points to an invalid **PROCESSOR_NUMBER** value, the routine returns INVALID_PROCESSOR_INDEX, which is defined in the Wdm.h header file.

## Remarks

This routine accepts as input a **PROCESSOR_NUMBER** structure that identifies a processor by its group number and its processor number within the group. The return value is a processor index that identifies the processor across the entire multiprocessor system.

For example, if a multiprocessor system contains two groups, and each group contains 64 logical processors, the processor numbers in each group range from 0 to 63, but the systemwide processor indexes range from 0 to 127.

To obtain the total number of active logical processors in the system, call the [KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex) routine and set this routine's *GroupNumber* parameter to ALL_PROCESSOR_GROUPS.

The [KeGetProcessorNumberFromIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessornumberfromindex) routine converts a systemwide processor index to a group number and a group-relative processor number.

## See also

[KeGetProcessorNumberFromIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessornumberfromindex)

[KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex)

[PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number)