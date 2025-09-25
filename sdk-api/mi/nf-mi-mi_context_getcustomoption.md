# MI_Context_GetCustomOption function

## Description

Retrieves an option set by the client.

## Parameters

### `context` [in]

A pointer to the request context.

### `name`

A pointer to the name of the option to get.

### `valueType` [out, optional]

A pointer to the option value type. This parameter is optional.

### `value` [out, optional]

A pointer to the option value. This parameter is optional.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.