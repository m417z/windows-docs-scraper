# MI_OperationOptions_SetCustomOption function

## Description

Sets a custom option for the operation.

## Parameters

### `options` [in, out]

A pointer to a [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `optionName`

A null-terminated string that represents the name of the option to set.

### `optionValueType` [in]

Option type.

### `optionValue` [in]

New option value.

### `mustComply`

Boolean value where **MI_TRUE** means that the option must be complied with.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.