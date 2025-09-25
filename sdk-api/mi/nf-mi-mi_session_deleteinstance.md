# MI_Session_DeleteInstance function

## Description

Deletes an instance on the server represented by the session.

## Parameters

### `session` [in]

Session handle returned from [MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession).

### `flags`

Must be 0.

### `options` [in, optional]

Optional [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) value that specifies options such as timeouts and how to control the CIM semantics. Specify **NULL** if no operation options are to be sent.

### `namespaceName`

An optional, null-terminated string that represents the namespace name to carry out the operation. If none is specified, the server will pick a default. The namespace cannot include a computer name. It can only be in the form of a namespace name separated by a slash mark character (/). For example, the following would be a valid **namespaceName** value: **root/cimv2**.

### `inboundInstance` [in]

[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) that represents the class name and key of the instance to be deleted on the server.

### `callbacks` [in, optional]

Optional [MI_OperationCallbacks](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationcallbacks) structure that defines the operational callbacks to receive the instance result and CIM semantics. A callback value is required to carry out the operation asynchronously. If **NULL** is specified, then the client must call the [MI_Operation_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getinstance) function to retrieve the results.

### `operation` [out]

Operation handle that must be closed with a call to [MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close) once the operation is finished and all results have been received. The handle can be used to cancel the operation with a call to [MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel).

## See also

[MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession)

[MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel)

[MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close)

[MI_Operation_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getinstance)