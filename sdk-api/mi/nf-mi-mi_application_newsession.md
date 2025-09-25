# MI_Application_NewSession function

## Description

Creates a session used to share connections for a set of operations to a single destination.

## Parameters

### `application` [in]

A pointer to a handle returned from the [MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1) function.

### `protocol` [in, optional]

A pointer to an optional protocol handler to carry out the operation. If this parameter is **NULL**, a default value is used, based on the destination. Currently supported protocols are L"WMIDCOM" and L"WINRM".

### `destination` [in, optional]

An optional destination for the session. If the destination argument is **NULL**, the session communicates with the local machine. Otherwise, the destination can be the computer name of the local machine or a remote machine.

### `options` [in, optional]

A pointer to optional destination options, such as default time-outs and credentials.

### `callbacks` [in, optional]

A pointer to an optional MI_SessionCallbacks structure that contains callbacks to receive various results.

### `extendedError`

Pointer to optional additional error information if the operation failed. When you have finished using the error information, free the memory by calling the [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.

### `session` [out]

A pointer to the returned session handle. When you have finished using the session handle, close it by calling the [MI_Session_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_session_close) function. If the session handle is not closed before shutting down both the application and the application handle, the application handle shutdown will not respond.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

Creating a destination may not communicate with the destination computer. It will not be until the first operation is carried out on a session that the application can determine whether the computer is accessible.

The [MI_Session_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_session_close) function must be called on the outbound session handle. Close all operations under the target session before closing the session.

If no protocol is specified and *destination* is **NULL**, the WMIDCOM protocol is used. If no protocol is specified and *destination* is not **NULL**, the WINRM protocol is used. .

## See also

[Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal)