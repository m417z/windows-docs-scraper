# MI_Application_NewOperationOptions function

## Description

Creates an [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) object that can be used with the operation functions on the [MI_Session](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_session) object.

## Parameters

### `application` [in]

A pointer to a handle returned from the [MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1) function.

### `mustUnderstand`

Specifies if the transport and provider are required to process the options being passed. This should be set to **MI_FALSE**. Setting this parameter to **MI_TRUE** can cause the operation to fail if the server cannot process one of the options.

### `options` [out]

A pointer to an options handle returned from this function.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

When you have finished using the object returned from this call, delete it by calling the [MI_OperationOptions_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operationoptions_delete) function.