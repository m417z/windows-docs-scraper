# MI_Context_GetCustomOptionCount function

## Description

Gets the number of custom options available to the provider.

## Parameters

### `context` [in]

A pointer to the request context.

### `count` [out, optional]

A pointer to the returned number of options. This parameter is optional.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

These options are passed by the client, possibly through the [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

## See also

[MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions)