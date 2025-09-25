# MI_Operation_Close function

## Description

Closes an operation handle.

## Parameters

### `operation` [in, out]

A pointer to an operation handle that was returned from a call to one of the
[MI_Session](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_session) operation functions. For asynchronous
callbacks, it can also be the operation handle that is passed into the callback.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the
function return code. This can be one of the following codes.

## Remarks

For synchronous operations, the close function is synchronous on retrieving the final result, so if the client
does not retrieve all results, then this call will fail. For asynchronous operations, this function will not
block.

A closing operation, such as **MI_Operations_Close**, should be called in same security
context as the starting operation.