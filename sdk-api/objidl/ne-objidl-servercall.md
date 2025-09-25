# SERVERCALL enumeration

## Description

Indicates the status of server call.

## Constants

### `SERVERCALL_ISHANDLED:0`

The object may be able to process the call.

### `SERVERCALL_REJECTED:1`

The object cannot handle the call due to an unforeseen problem, such as network unavailability.

### `SERVERCALL_RETRYLATER:2`

The object cannot handle the call at this time. For example, an application might return this value when it is in a user-controlled modal state.

## See also

[IMessageFilter::HandleInComingCall](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imessagefilter-handleincomingcall)

[IMessageFilter::RetryRejectedCall](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imessagefilter-retryrejectedcall)