# MI_Session_CreateInstance function

## Description

Creates an instance on the server that the session represents.

## Parameters

### `session` [in]

Session handle returned from [MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession).

### `flags`

Runtime type information (RTTI) [flags](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/mi-flags).

### `options` [in, optional]

Optional [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) value that specifies options such as timeouts and how to control the CIM semantics. Specify **Null** if no operation options are to be sent.

### `namespaceName`

A null-terminated string that contains the optional namespace name to carry out the operation. If none is specified, the server will pick a default. The namespace cannot include a computer name. It can only be in the form of a namespace name separated by a slash mark character (/). For example, the following would be a valid **namespaceName** value: **root/cimv2**.

### `inboundInstance` [in]

[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) that represents the class name and keys of the instance to be created on the server along with the rest of the properties of the instance that destination instance will be set to. Sometimes keys are read-only, so not all keys need to be specified. If the instance that is specified already exists, the function will fail; to update an existing instance, use the [MI_Session_ModifyInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_session_modifyinstance) function.

### `callbacks` [in, optional]

Optional [MI_OperationCallbacks](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationcallbacks) structure that defines the operational callbacks to receive the instance result and CIM semantics. To do asynchronously, this value must be specified. If NULL is specified, the client must call the [MI_Operation_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getinstance) function to retrieve the results.

### `operation` [out]

Operation handle that must be closed with a call to [MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close) once the operation is finished and all results have been received. The handle can be used to cancel the operation with a call to [MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel).

## See also

[MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel)

[MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close)

[MI_Operation_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getinstance)

[MI_Session_ModifyInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_session_modifyinstance)