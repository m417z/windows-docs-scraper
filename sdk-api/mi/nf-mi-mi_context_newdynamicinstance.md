# MI_Context_NewDynamicInstance function

## Description

Creates a new dynamic instance (weakly typed instance without a class declaration) of a class.

## Parameters

### `context` [in]

A pointer to the request context.

### `className` [in]

The name of the new class.

### `flags`

The create flags (include class meta type).

### `instance`

A pointer to a new instance upon successful return.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## Remarks

To add elements, call the [MI_Instance_AddElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_addelement) function. When you have finished using the instance, delete it with the [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.

## See also

[MI_Instance_AddElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_addelement)

[MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete)