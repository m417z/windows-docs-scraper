## Description

The **KeGetProcessorNumberFromIndex** routine converts a systemwide processor index to a group number and a group-relative processor number.

## Parameters

### `ProcIndex` [in]

A systemwide processor index. If a multiprocessor system contains a total of *n* logical processors, valid processor indexes range from 0 to *n*-1.

### `ProcNumber` [out]

A pointer to a caller-allocated [**PROCESSOR_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number) structure into which the routine writes the group number and group-relative processor number of the processor that is identified by *ProcIndex*.

## Return value

**KeGetProcessorNumberFromIndex** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The *ProcIndex* parameter value is not a valid processor index. |

## Remarks

This routine accepts as input a processor index that identifies the processor across the entire multiprocessor system. The output value is a **PROCESSOR_NUMBER** structure that identifies a processor by its group number and its processor number within the group.

For example, if a multiprocessor system contains two groups, and each group contains 64 logical processors, the processor numbers in each group range from 0 to 63, but the systemwide processor indexes range from 0 to 127.

To obtain the total number of active logical processors in the system, call the [KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex) routine.

The [KeGetProcessorIndexFromNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kegetprocessorindexfromnumber) routine converts a group number and a group-relative processor number to a systemwide processor index.

### Examples

The following code example uses the **KeQueryActiveProcessorCountEx** and **KeGetProcessorNumberFromIndex** routines to enumerate all active logical processors in the system:

```cpp
ULONG Count;
ULONG ProcIndex;
PROCESSOR_NUMBER ProcNumber;

Count = KeQueryActiveProcessorCountEx(ALL_PROCESSOR_GROUPS);
for (ProcIndex = 0; ProcIndex < Count; ProcIndex += 1)
{
    KeGetProcessorNumberFromIndex(ProcIndex, &ProcNumber);

    // Do something with the contents of ProcNumber.
    ...
}
```

The constant value ALL_PROCESSOR_GROUPS is defined in Winnt.h and Ntdef.h.

## See also

[KeGetProcessorIndexFromNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kegetprocessorindexfromnumber)

[KeQueryActiveProcessorCountEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactiveprocessorcountex)

[**PROCESSOR_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number)