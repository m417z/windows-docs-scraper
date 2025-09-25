# MI_OperationOptions_SetNumber function

## Description

Sets a custom number option value.

## Parameters

### `options` [in, out]

A pointer to a [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `optionName`

A null-terminated string that represents the name of the option to set.

### `value` [in]

New option value.

### `flags`

Option flags.

## Return value

This function returns MI_INLINE MI_Result.