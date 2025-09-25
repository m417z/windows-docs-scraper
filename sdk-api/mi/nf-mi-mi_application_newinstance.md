# MI_Application_NewInstance function

## Description

Creates a new [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) object to be passed to various MI operation APIs that require instances.

## Parameters

### `application` [in]

A pointer to a handle returned from a call to the [MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1) function.

### `className`

The class name for the instance being created.

### `classRTTI` [in, optional]

A pointer to optional run time type information for the object being created.

### `instance`

A pointer to the instance returned from this function call.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

When you have finished using the instance created by this call, delete it by calling the [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.