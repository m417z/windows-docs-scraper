# PENDINGMSG enumeration

## Description

Specifies the return values for the [IMessageFilter::MessagePending](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imessagefilter-messagepending) method.

## Constants

### `PENDINGMSG_CANCELCALL:0`

Cancel the outgoing call.

### `PENDINGMSG_WAITNOPROCESS:1`

Wait for the return and don't dispatch the message.

### `PENDINGMSG_WAITDEFPROCESS:2`

Wait and dispatch the message.

## See also

[IMessageFilter::MessagePending](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imessagefilter-messagepending)