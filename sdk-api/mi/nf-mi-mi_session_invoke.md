# MI_Session_Invoke function

## Description

Invokes a method in the provider.

## Parameters

### `session` [in]

Session handle returned from
[MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession).

### `flags`

Runtime type information (RTTI)
[flags](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/mi-flags).

### `options` [in, optional]

Optional [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) value that
specifies options such as timeouts and how to control the CIM semantics. Specify **Null**
if no operation options are to be sent.

### `namespaceName` [in, optional]

An optional, null-terminated string that represents the namespace name to carry out the operation. If none
is specified, the server will pick a default. The namespace cannot include a computer name. It can only be in
the form of a namespace name separated by a slash mark character (/). For example, the following would be a
valid **namespaceName** value: **root/cimv2**.

### `className` [in, optional]

An optional, null-terminated string that represents the name of the class the method is a part of. Should
be **Null** when passing in an **inboundinstance**.

### `methodName` [in]

A null-terminated string that represents the name of the method to invoke.

### `inboundInstance` [in, optional]

Instance with keys to specify which method is to be invoked. If **Null**, the method
must be static.

### `inboundProperties` [in, optional]

Inbound method properties. Each inbound property needs to be an element in the instance and the element
name needs to be the same as the name of the method parameter.

### `callbacks` [in, optional]

Optional [MI_OperationCallbacks](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationcallbacks) structure
that defines the operational callbacks to receive the instance result and CIM semantics. To carry out the
operation asynchronously, the structure's **instanceResult** callback member must be
specified. If this member is not specified, then the client must call the
[MI_Operation_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getinstance) function to
retrieve the results.

### `operation` [out]

Returned operation handle that must be closed via
[MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close) once complete. Calling
[MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel) before it is complete
will cause the operation to shutdown.
**MI_Operation_Close** and
**MI_Operation_Cancel** can be called from any
operation.

## Remarks

Methods have return values that will be returned as a *ReturnValue* parameter of the
outbound instance. There may be outbound properties that will be part of the same result. If the streamed
parameter callback is given and any outbound properties are marked as streamed, the streaming callback will be
called for each parameter that supports streaming. They will be called until all results are retrieved or until
the final result is given back.

## See also

[MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession)

[MI_OperationCallbacks](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationcallbacks)

[MI_Operation_Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_cancel)

[MI_Operation_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_close)

[MI_Operation_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operation_getinstance)