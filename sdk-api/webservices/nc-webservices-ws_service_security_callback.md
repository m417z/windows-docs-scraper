# WS_SERVICE_SECURITY_CALLBACK callback function

## Description

Invoked when headers of the incoming message
are received and the body is not processed.

## Parameters

### `context` [in]

The incoming message with headers only.

### `authorized` [out]

Set to **TRUE**, if authorization succeeded, **FALSE** if authorization failed.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.