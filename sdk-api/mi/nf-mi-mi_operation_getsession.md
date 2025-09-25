# MI_Operation_GetSession function

## Description

Gets the session associated with an operation.

## Parameters

### `operation` [in]

Operation handle returned from an instance session operation.

### `session` [out]

Returned session that was used to create the operation. Copy of the parent session that initiated the operation.

## Remarks

This function is useful in a result asynchronous callback if a new operation needs to be initiated against the same session.