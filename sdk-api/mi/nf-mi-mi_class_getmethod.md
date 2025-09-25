# MI_Class_GetMethod function

## Description

Gets details of a method based on the method name.

## Parameters

### `self` [in]

A pointer to the class object from which the method information is to be retrieved.

### `name` [in]

The name of the method to be retrieved.

### `qualifierSet` [out, optional]

A pointer to the variable to receive the returned method qualifier set. This parameter is optional. The memory associated with the qualifier set is valid until the class object is deleted. When you have finished using the class qualifier set, delete the class object by calling the [MI_Class_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_class_delete) function. If this information is not needed, pass **NULL** for this parameter.

### `parameterSet` [out, optional]

A pointer to a variable to receive the returned parameter set. The parameter set also contains the return type and return type qualifier set. This parameter is optional. The memory associated with the parameter set is valid until the class object is deleted. When you have finished using the parameter set, delete the class object by calling the [MI_Class_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_class_delete) function. If this information is not needed, pass **NULL** for this parameter.

### `index` [out, optional]

A pointer to a variable to receive the returned index of the specified method. This parameter is optional.

## Return value

This function returns MI_INLINE MI_Result.