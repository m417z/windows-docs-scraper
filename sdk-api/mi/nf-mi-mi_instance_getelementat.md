# MI_Instance_GetElementAt function

## Description

Gets the value of the element (CIM property) at the specified index.

## Parameters

### `self` [in]

Instance whose element value will be returned.

### `index`

Zero-based index of the element

### `name`

A pointer to a null-terminated string containing the returned element name.

### `value` [out, optional]

Returned element value.

### `type` [out, optional]

Returned element type.

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

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance)

[MI_Instance_ClearElementAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clearelementat)

[MI_Instance_GetElementCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_getelementcount)

[MI_Instance_SetElementAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_setelementat)