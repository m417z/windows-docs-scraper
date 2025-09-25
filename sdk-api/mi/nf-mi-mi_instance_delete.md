# MI_Instance_Delete function

## Description

Deletes an instance that was created on the heap or cloned from another instance.

## Parameters

### `self` [in, out]

Instance to be released.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Instances created with the [MI_Instance_Clone](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clone), [MI_Application_NewInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newinstance), [MI_Context_NewInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_newinstance), [MI_Context_NewDynamicInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_newdynamicinstance), [MI_Context_NewParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_newparameters), and [MI_Utilities_CimErrorFromErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_utilities_cimerrorfromerrorcode) functions should be passed to this function when they are no longer required.

## See also

[MI_Application_NewInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newinstance)

[MI_Context_NewDynamicInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_newdynamicinstance)

[MI_Context_NewInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_newinstance)

[MI_Context_NewParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_newparameters)

[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance)

[MI_Instance_Clone](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clone)

[MI_Utilities_CimErrorFromErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_utilities_cimerrorfromerrorcode)