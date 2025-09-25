# WS_HTTP_REDIRECT_CALLBACK callback function

## Description

Invoked when a message is about to be automatically
redirected to another service utilizing HTTP auto redirect functionality
as described in RFC2616. If the redirection should not be allowed, this
callback should return S_FALSE or an error value. Otherwise the auto
HTTP redirection will proceed.

## Parameters

### `state` [in]

The 'state' as specified as part of [WS_HTTP_REDIRECT_CALLBACK_CONTEXT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_http_redirect_callback_context) 'state' field.

### `originalUrl` [in]

The original endpoint URL that the message was sent to.

### `newUrl` [in]

The endpoint URL that the message is about to be forwarded to.

## Return value

This callback function does not return a value.

## Remarks

The parameters supplied during this callback are valid only for the
duration of the callback.

The callback implementation should avoid lengthy computation or
lengthy blocking calls so that it can return to the caller quickly.