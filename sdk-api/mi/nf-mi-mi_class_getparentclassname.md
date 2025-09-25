# MI_Class_GetParentClassName function

## Description

Gets the parent class name of the specified class.

## Parameters

### `self` [in]

A pointer to the class from which to retrieve the parent class name.

### `name`

A pointer to a pointer to the returned parent class name value. This string is owned by the class and does not need to be deleted. If there is no parent class, this will be **NULL**.

## Return value

This function returns MI_INLINE MI_Result.