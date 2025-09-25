# MI_Operation_Cancel function

## Description

Cancels a running operation.

## Parameters

### `operation` [in, out]

A pointer to an operation handle that was returned from a call to one of the [MI_Session](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_session) operation functions. For asynchronous callbacks, this value can be the operation handle that is passed into the callback.

### `reason`

[MI_CancellationReason](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_cancellationreason) enumeration value.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Cancellation is asynchronous. Cancelled operations still need to be closed. Cancellation will cause the operation to finish as soon as possible. For an asynchronous operation, this will cause final callback to happen with the final result. For a synchronous operation, the final result should be available soon.

A closing operation, such as **MI_Operations_Cancel**, should be called in same security context as the starting operation.

After cancellation, there may be more than just one result, because cancellation happens as soon as possible, so a few extra results may still get delivered. Not all operation cancellations get through to the provider for notification, though. (For example, enum can, but invoke cannot.) The client does disconnect from the server as soon as possible, though, so it will not wait for the entire operation to complete before giving a final result. Because not all operation cancellation can get to the server, it means that if the operation is taking quota (in terms of running operations, memory usage, and so on), then new operations may possibly fail with quota violations until the provider finally realizes the operation is canceled, and it shuts itself down.