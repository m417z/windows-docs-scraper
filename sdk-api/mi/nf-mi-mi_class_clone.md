# MI_Class_Clone function

## Description

Clones an [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) object.

## Parameters

### `self` [in]

A pointer to the class to be cloned.

### `newClass`

A pointer to a pointer to the newly created class. When you have finished using this class, delete it by calling the [MI_Class_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_class_delete) function.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## Remarks

**MI_Class_Clone** may not create a whole new class; instead, it may refer to the original class. Each class can be closed independent of the other, but not all of the memory is freed until all references to the class are deleted.