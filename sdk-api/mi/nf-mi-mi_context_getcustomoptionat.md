# MI_Context_GetCustomOptionAt function

## Description

Retrieves an option at a particular index that was set by the client.

## Parameters

### `context` [in]

A pointer to the request context.

### `index` [in]

The index of the option being retrieved. The index is zero based.

### `name`

A pointer to a pointer to the returned name or the retrieved option.

### `valueType` [out, optional]

A pointer to the returned option type. This parameter is optional.

### `value` [out, optional]

A pointer to the returned option value. This parameter is optional.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Note that the index used does not relate to the order in which the client may have created the options.