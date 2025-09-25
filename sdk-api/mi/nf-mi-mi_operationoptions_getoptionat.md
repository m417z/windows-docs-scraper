# MI_OperationOptions_GetOptionAt function

## Description

Gets a previously added option value based on the specified index.

## Parameters

### `options` [in]

MI_OperationOptions structure.

### `index`

Zero-based index of the option.

### `optionName`

Returned option name.

### `value` [out]

Returned option value.

### `type` [out]

Returned option type.

### `flags` [out, optional]

Returned option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.