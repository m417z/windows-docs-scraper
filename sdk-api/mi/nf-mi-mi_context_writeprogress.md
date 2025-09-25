# MI_Context_WriteProgress function

## Description

Sends a progress message to the client.

## Parameters

### `context` [in]

Request context.

### `activity` [in]

A null-terminated string that represents the current activity. This string should be localized based on the
client UI request (retrieved through the
[MI_Context_GetLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocale) function).

### `currentOperation` [in]

A null-terminated string that represents the current operation being processed. This string should be
localized based on the client UI request.

### `statusDescription` [in]

A null-terminated string that represents the current status description. This string should be localized
based on the client UI request.

### `percentComplete`

Current percentage of completion. Passing 0xffffffff indicates that the percentage complete is
unknown.

### `secondsRemaining`

Estimated seconds remaining to complete the current operation. Passing 0xffffffff indicates that the time
required to complete the current operation is unknown.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the
function return code. This can be one of the following codes.

## Remarks

A provider calls this function to indicate how far through an operation the provider is and how much time is
remaining. A client can optionally register to receive these messages via an asynchronous callback. If a client
does not register for these messages, the server will ignore the message. This function is particularly important
for long running operations so the client does not think the operation has stopped responding. Do not send too
many progress messages as it can cause a performance hit, but send them often enough that the client does not
think the operation has stopped responding and possibly cancel the operation. (An interval range between 0.5 and
10 seconds is probably reasonable.) Also, if a progress message comes in during an operation, it will reset the
operation timeout period to allow the operation to last longer than the operation timeout value. If the client
does not register for this callback, though, it has no way of resetting the timeout value, so it may time out even
when the provider sends a progress message.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_GetLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocale)