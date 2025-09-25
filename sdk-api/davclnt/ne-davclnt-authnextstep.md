# AUTHNEXTSTEP enumeration

## Description

Specifies the next action that the WebDAV client should take after a successful call to the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) callback function.

## Constants

### `DefaultBehavior`

Retry the connection request without using the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) callback function. This is the same as the default behavior if no callback function is registered.

### `RetryRequest`

Retry the connection request using the credentials that were retrieved by the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) function.

### `CancelRequest`

Cancel the connection request.

## Remarks

This enumeration provides the values for the *NextStep* parameter of the [DavAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback) callback function.