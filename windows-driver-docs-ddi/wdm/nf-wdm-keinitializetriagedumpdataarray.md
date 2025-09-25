# KeInitializeTriageDumpDataArray function

## Description

The **KeInitializeTriageDumpDataArray** function initializes a triage dump data block array.

## Parameters

### `KtriageDumpDataArray`

 A pointer to a [**KTRIAGE_DUMP_DATA_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ktriage_dump_data_array) structure that is the data block array. It is assumed that the caller has already obtained exclusive write to _KtriageDumpDataArray_. The array must be allocated from non-paged memory.

### `Size`

Specifies the size, in bytes, of the uninitialized triage dump data array.

## Return value

This function returns NTSTATUS.

## Remarks

## See also

[*KeAddTriageDumpDataBlock*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keaddtriagedumpdatablock)

[*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine)