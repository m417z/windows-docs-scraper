# WS_VALIDATE_PASSWORD_CALLBACK callback function

## Description

Validates a username/password pair
on the receiver side. When a [WS_USERNAME_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_username_message_security_binding)
containing this callback is included in the security description, this callback
is invoked for each received message at the server. This callback is expected
to return S_OKif the username/password pair was successfully validated, S_FALSE
when the pair could not be validated and an error value if an unexpected error occurred.
Returning any result other than S_OK from this callback will result in
the associated receive message failing with a security error.

As with all security callbacks, the application should expect to
receive this callback any time between channel/listener open and close,
but it will never be invoked when a channel is not open. In the
current drop, this callback is always invoked synchronously. In the
next drop, this callback will be invoked synchronously for synchronous
message receives and asynchronously for asynchronous message receives,
but it will always be invoked [short](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_callback_model) when it is invoked asynchronously.

## Parameters

### `passwordValidatorCallbackState` [in, optional]

The state to be passed back when invoking this callback.

### `username` [in]

Received username.

### `password` [in]

Received password.

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.