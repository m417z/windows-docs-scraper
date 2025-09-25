# _KTRIAGE_DUMP_DATA_ARRAY structure

## Description

Specifies an array of memory locations and lengths (ranges) to be preserved in crash dump files.

## Members

### `List`

A pointer to a [**LIST_ENTRY**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that represents the entry to be added in the array.

### `NumBlocksUsed`

### `NumBlocksTotal`

### `DataSize`

### `MaxDataSize`

### `ComponentNameBufferLength`

### `ComponentName`

### `Blocks`

## Remarks

A driver initializes this structure by calling [**KeInitializeTriageDumpDataArray**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetriagedumpdataarray) function. A driver provides a pointer to a structure of this type when it calls the [**KeAddTriageDumpDataBlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keaddtriagedumpdatablock) function.

## See also

[*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine)