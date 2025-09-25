# MI_Instance_AddElement function

## Description

Adds a new property to a dynamic instance (supported only by dynamic instances whose schema may be extended at run time).

## Parameters

### `self` [in, out]

Instance to which the element will be added.

### `name`

A null-terminated string that represents the name of the new element.

### `value` [in, optional]

Element value.

### `type`

Element type.

### `flags`

Flags of the new element that can be a combination of the following flag values.

#### MI_FLAG_KEY (0x00001000)

Element is a key.

#### MI_FLAG_IN (0x00002000)

Parameter is of type In and is passed into a method.

#### MI_FLAG_OUT (0x00004000)

Parameter is of type Out and is returned from a method.

#### MI_FLAG_REQUIRED (0x00008000)

Parameter is required.

#### MI_FLAG_STREAM (0x00100000)

Method parameter will be streamed back to the client from the provider.

#### MI_FLAG_BORROW (0x40000000)

Used while adding and setting properties on an [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) to indicate that the instance will not copy the value. The value must stay valid until the instance is deleted.

#### MI_FLAG_ADOPT (0x80000000)

Used while adding and setting properties on an [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) to indicate that the instance will adopt the pointer and will be responsible for deleting it.

#### MI_FLAG_NULL (0x20000000)

Element value is **Null**.

#### MI_FLAG_ANY (0x0000007F)

Bitmask used to filter out other flags.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## See also

[MI_Instance_ClearElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clearelement)

[MI_Instance_GetElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_getelement)

[MI_Instance_SetElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_setelement)