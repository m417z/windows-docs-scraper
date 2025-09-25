# MI_Application_NewInstanceFromClass function

## Description

Creates a new [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) object based on a class object.

## Parameters

### `application` [in]

A pointer to a handle returned from a call to the [MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1) function.

### `className`

A null-terminated string that represents the class name for the instance being created.

### `classObject` [in, optional]

A pointer to the class object from which to create an instance.

### `instance`

A pointer to the instance returned from this function call.

## Return value

This function returns MI_INLINE MI_Result.