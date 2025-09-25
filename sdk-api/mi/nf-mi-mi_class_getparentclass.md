# MI_Class_GetParentClass function

## Description

Gets the parent class for the specified class.

## Parameters

### `self` [in]

A pointer to the child class.

### `parentClass`

A pointer to a pointer to the returned parent class. When you have finished using the class, deleted it by using the [MI_Class_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_class_delete) function.

## Return value

This function returns MI_INLINE MI_Result.