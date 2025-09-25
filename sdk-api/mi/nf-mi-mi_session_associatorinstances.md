# MI_Session_AssociatorInstances function

## Description

Finds instances that are associated with the specific key instance.

## Parameters

### `session` [in]

Handle created from a call to [MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession).

### `flags`

Runtime type information (RTTI) [flags](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/mi-flags).

### `options` [in, optional]

Optional [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) value that specifies options such as timeouts and how to control the CIM semantics. Specify NULL if no operation options are to be sent.

### `namespaceName`

A null-terminated string that contains the optional namespace name to carry out the operation. If none is specified the server will pick a default. The namespace cannot include a computer name. It can only be in the form of namespace names separated by a slash character, for instance root/cimv2.

### `instanceKey` [in]

An [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) that represents the class name and the keys of the instance where the association will start.

### `assocClass`

A null-terminated string that represents the optional value that specifies to only map the association via this association class. If this value is NULL, then any association classes will be used.

### `resultClass`

A null-terminated string that represents the optional values that restricts the result set to only this class. Specify NULL if no filtering is wanted.

### `role`

A null-terminated string that represents the property name in the association object that points to our key object.

### `resultRole`

A null-terminated string that represents the property name in the association object that points to the resultant class.

### `keysOnly`

If set to MI_TRUE the operation will only retrieve the key properties of the instances. Otherwise, specify MI_FALSE.

### `callbacks` [in, optional]

Optional [MI_OperationCallbacks](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationcallbacks) structure that defines the operational callbacks to receive the instance result and CIM semantics. For asynchronous operation, the callback must be specified. For synchronous operation, specify NULL; the client must then call [MI_Operation_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getinstance) to retrieve the results.

### `operation` [out]

Operation handle that must be closed with a call to [MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close) once the operation is finished and all results have been received. The handle can be used to cancel the operation with a call to [MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel).

## Remarks

An association is a relationship between two objects. It is represented with a third object containing two properties, each being a reference to one of those two related objects. The *role* parameter is the association object's reference property, pointing to the object being associated. The *resultRole* parameter points to the other, resultant object.

## See also

[MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession)

[MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel)

[MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close)

[MI_Operation_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getinstance)