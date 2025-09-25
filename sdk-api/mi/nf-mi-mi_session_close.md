# MI_Session_Close function

## Description

Closes a session and releases all associated memory.

## Parameters

### `session` [in, out]

Session handle returned from [MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession).

### `completionContext` [in, optional]

Optional parameter to be returned through the **completionCallback** callback.

### `completionCallback` [in, out]

Optional callback to make the session close asynchronous. (If this value is **NULL**, then the close call is synchronous.) If the **MI_Session_Close** is called from a callback the completion callback must be specified. Not doing so can result in a deadlock.

#### completionContext

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Closing a session will cause all operations that are currently running to be canceled. Canceling operations will cause asynchronous operation callbacks to be called (with the final result of an MI_Operation_Get* function call's *moreResults* parameter equal to **MI_FALSE**, although more than one result may be delivered before this happens). Not closing all operation handles that were created with the current session will cause the closing of the session to stop responding for synchronous calls and the asynchronous callback will not be called. Operation and session handles not fully closed will cause the application handle to stop responding during shutdown.