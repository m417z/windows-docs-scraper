# MI_Instance_IsA function

## Description

Determines if the instance *self* is an instance of the class given by *classDecl*.

## Parameters

### `self` [in]

Instance to compare.

### `classDecl` [in]

Class declaration to compare.

### `flag` [out]

Returned value that is set to **MI_TRUE** if *self* is an instance of *classDecl* or if the actual class of the instance inherits from the specified class. Otherwise, it is set to **MI_FALSE**.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.