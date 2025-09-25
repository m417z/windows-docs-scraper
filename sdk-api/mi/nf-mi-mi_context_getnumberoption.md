# MI_Context_GetNumberOption function

## Description

Gets the numeric option that the client sets, based on the operation name.

## Parameters

### `context` [in]

A pointer to the request context.

### `name` [in]

The name of the option to get.

### `value` [out, optional]

A pointer to the returned option value. This parameter is optional.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.