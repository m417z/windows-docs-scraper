# MI_Application_InitializeV1 function

## Description

Initializes an application so that it can make Management Infrastructure (MI) client API
calls.

## Parameters

### `flags`

Must be 0.

### `applicationID` [in, optional]

An optional string (usually **GUID** in string format) to represent a client
application. This string may be used for application specific configuration and application specific
logging.

### `extendedError` [out, optional]

Optional parameter giving more error information if the operation failed. If an instance is returned,
[MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) must be called to free it
when it is no longer needed.

### `application` [out]

A pointer to an uninitialized [MI_Application](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_application)
handle is passed in and a populated handle is returned. The initialized handle must be passed to
[MI_Application_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_close) before the application
shuts down. If an application passes this handle, pass it by value rather than as a pointer.

## Return value

This function returns MI_Result MI_MAIN_CALL.

## Remarks

This API needs to be called only once per application; although, it can be called multiple times safely.
Calling this API multiple times will result in a small amount of extra memory usage. When called, the application
passes in an [MI_Application](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_application) pointer to be initialized.
This pointer must be closed by calling
[MI_Application_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_close). Not doing so will cause
memory leaks and potential crashes during shutdown.

MI.h defines
**MI_Application_Initialize** as
**MI_Application_InitializeV1** with this
line:

`#define MI_Application_Initialize MI_Application_InitializeV1`