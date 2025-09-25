# MI_Context_GetStringOption function

## Description

Gets the string option that the client sets, based on the operation name.

## Parameters

### `context` [in]

A pointer to the request context.

### `name` [in]

The name of the option to get.

### `value`

A pointer to the returned option value.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

The returned string does not need to be deleted. The string is valid until the provider returns the final result for this operation.