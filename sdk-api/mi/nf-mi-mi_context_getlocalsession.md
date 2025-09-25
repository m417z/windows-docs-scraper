# MI_Context_GetLocalSession function

## Description

Gets the local session ([MI_Session](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_session)) which allows the provider to perform CIM operations against the local server hosting the provider.

## Parameters

### `context` [in]

A pointer to the request context.

### `session` [out]

A pointer to the returned [MI_Session](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_session) object. This session must not be closed.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This session is pre-instantiated and has the lifetime of the context from which the session was obtained. The provider must not close this session because its lifetime is bound to the context.

The provider should call this function rather than creating a new session through the [MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession) function, because some optimizations may be possible for talking to the CIM server.

The security context used to call the **MI_Context_GetLocalSession** function should be the same identity used communicate back to the server through the MI_Session_* operation functions. Do not cache these sessions outside the current operation. The provider calls this method multiple times within an operation under different identities, in which case the retrieved session should also be used with the same identity. Any operations on the session should always be the same identity that the user retrieved for the local session, or else the operation could fail with the **MI_RESULT_ACCESS_DENIED** return code.