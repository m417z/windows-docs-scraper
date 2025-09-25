# _WHEA_GENERIC_ERROR_BLOCKSTATUS structure

## Description

The WHEA_GENERIC_ERROR_BLOCKSTATUS union indicates what kind of error data is reported in a generic error status block.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.UncorrectableError`

The generic error status block is reporting uncorrectable error data.

### `DUMMYSTRUCTNAME.CorrectableError`

The generic error status block is reporting correctable error data.

### `DUMMYSTRUCTNAME.MultipleUncorrectableErrors`

The generic error status block is reporting multiple uncorrectable errors.

### `DUMMYSTRUCTNAME.MultipleCorrectableErrors`

The generic error status block is reporting multiple correctable errors.

### `DUMMYSTRUCTNAME.ErrorDataEntryCount`

The number of [WHEA_GENERIC_ERROR_DATA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_data_entry_v2) structures that are contained in the generic error status block.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `AsULONG`

A ULONG representation of the contents of the WHEA_GENERIC_ERROR_BLOCKSTATUS union.

## Remarks

A WHEA_GENERIC_ERROR_BLOCKSTATUS union is contained within the [WHEA_GENERIC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error) structure.

## See also

[WHEA_GENERIC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error)

[WHEA_GENERIC_ERROR_DATA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_data_entry_v2)