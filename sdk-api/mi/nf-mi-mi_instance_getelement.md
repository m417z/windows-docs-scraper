# MI_Instance_GetElement function

## Description

Gets the value of the named element (CIM property).

## Parameters

### `self` [in]

Instance whose element value will be returned.

### `name`

A null-terminated string that represents the name of the element.

### `value` [out, optional]

Returned element value.

### `type` [out, optional]

Returned element value type.

### `flags` [out, optional]

Returned combination of the following values.

#### MI_FLAG_NULL (0x20000000)

Element value is **Null**.

#### MI_FLAG_KEY (0x0001000)

Element is a key.

#### MI_FLAG_IN (0x0002000)

The parameter is of type **In** and is passed into a method.

#### MI_FLAG_OUT (0x0004000)

The parameter is of type **Out** and is returned from a method.

### `index` [out, optional]

Returned zero-based index of the element.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_Instance_AddElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_addelement)

[MI_Instance_ClearElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clearelement)

[MI_Instance_SetElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_setelement)