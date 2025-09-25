# MI_OperationOptions_GetString function

## Description

Gets a custom string option.

## Parameters

### `options` [in]

[MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `optionName`

A null-terminated string that represents the name of the option.

### `value`

Returned option value.

### `index` [out, optional]

Returned zero-based index of the option.

### `flags` [out, optional]

Returned option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_OperationOptions_SetString](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operationoptions_setstring)