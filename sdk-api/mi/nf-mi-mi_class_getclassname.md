# MI_Class_GetClassName function

## Description

Gets the class name of the specified class.

## Parameters

### `self` [in]

A pointer to a class from which to get the name.

### `className`

A pointer to a pointer to a returned class name value. This string is borrowed from the class object; the caller must not delete the string.

## Return value

This function returns MI_INLINE MI_Result.