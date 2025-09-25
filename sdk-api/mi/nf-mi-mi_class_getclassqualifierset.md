# MI_Class_GetClassQualifierSet function

## Description

Gets the qualifier set that is associated with the specified class object.

## Parameters

### `self` [in]

A pointer to the class from which to get the qualifier set.

### `qualifierSet` [out, optional]

A pointer to the variable to receive the returned class qualifier set. This parameter is optional. The memory associated with the qualifier set is valid until the class object is deleted. When you have finished using the class qualifier set, delete the class object by calling the [MI_Class_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_class_delete) function.

## Return value

This function returns MI_INLINE MI_Result.