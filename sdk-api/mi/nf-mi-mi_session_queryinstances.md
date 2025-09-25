# MI_Session_QueryInstances function

## Description

Queries for a set of instances based on a query expression.

## Parameters

### `session` [in]

Session handle returned from [MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession).

### `flags`

Runtime type information (RTTI) and polymorphic [flags](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/mi-flags).

### `options` [in, optional]

Optional [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) value that specifies options such as timeouts and how to control the CIM semantics. Specify **Null** if no operation options are to be sent.

### `namespaceName`

An optional, null-terminated string that represents the namespace name to carry out the operation. If none is specified, the server will pick a default. The namespace cannot include a computer name. It can only be in the form of a namespace name separated by a slash mark character (/). For example, the following would be a valid **namespaceName** value: **root/cimv2**.

### `queryDialect`

An optional, null-terminated string that represents the dialect of the query being passed. This value can be either WQL or CQL. Note that some servers do not support all query types.

### `queryExpression`

An optional, null-terminated string that represents the query expression to be carried out. Usually a query is needed, but if a WS-Management endpoint is being used, a resource URI can be passed. For WMI DCOM transport, this value must be specified.

### `callbacks` [in, optional]

Optional [MI_OperationCallbacks](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationcallbacks) structure that defines the operational callbacks to receive the instance result and CIM semantics. To carry out the operation asynchronously, the structure's **instanceResult** callback member must be specified. If this structure member is not specified, the client must call the [MI_Operation_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getinstance) function to retrieve the results.

### `operation` [out]

Returned operation handle that must be closed via [MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close) once complete. Calling [MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel) before it is complete will cause the operation to shutdown. **MI_Operation_Close** and **MI_Operation_Cancel** can be called from any operation.

## See also

[MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession)

[MI_OperationCallbacks](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationcallbacks)

[MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel)

[MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close)

[MI_Operation_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getinstance)