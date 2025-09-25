# MI_OperationOptions_SetString function

## Description

Sets a custom string option.

## Parameters

### `options` [in, out]

A pointer to a [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `optionName`

A null-terminated string that represents the name of the option.

### `value`

A null-terminated string that represents the new value for the option.

### `flags`

Option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_OperationOptions_GetString](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operationoptions_getstring)