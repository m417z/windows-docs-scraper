# MI_Application_NewParameterSet function

## Description

Creates a new parameter set.

## Parameters

### `application` [in]

A pointer to a handle returned from the [MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1) function.

### `classRTTI` [in, optional]

A pointer to optional run-time type information (RTTI) that defines the property set. Generally, this is **NULL** for parameter sets. If there is no RTTI, call the [MI_Instance_AddElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_addelement) function to add extra parameters. If RTTI is passed in, use the [MI_Instance_SetElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_setelement) function to set the values of the parameters.

### `instance`

A pointer to a pointer to the instance returned from this function call.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

When you have finished using the parameter set, free the instance by calling the [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.