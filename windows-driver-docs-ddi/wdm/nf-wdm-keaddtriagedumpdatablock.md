# KeAddTriageDumpDataBlock function

## Description

Adds a triage dump data block to a triage dump data block array.

## Parameters

### `KtriageDumpDataArray` [_Inout_]

A pointer to a [**KTRIAGE_DUMP_DATA_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ktriage_dump_data_array) structure that is the data block array. It is assumed that the caller has already obtained exclusive write to _KtriageDumpDataArray_.

### `Address`

 [_In_] A ULONG_PTR that is the starting address of the data block.

### `Size` [_In_]

The size of the data block, in bytes.

## Return value

Returns STATUS_SUCCESS if the data block was successfully added. Otherwise returns an appropriate [NTSTATUS value](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The array must have already been initialized by calling [**KeInitializeTriageDumpDataArray**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetriagedumpdataarray).

## See also

[*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine)