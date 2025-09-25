# CALLTYPE enumeration

## Description

Specifies the call types used by [IMessageFilter::HandleInComingCall](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imessagefilter-handleincomingcall).

## Constants

### `CALLTYPE_TOPLEVEL:1`

A top-level call has arrived and the object is not currently waiting for a reply from a previous outgoing call. Calls of this type should always be handled.

### `CALLTYPE_NESTED:2`

A call has arrived bearing the same logical thread identifier as that of a previous outgoing call for which the object is still awaiting a reply. Calls of this type should always be handled.

### `CALLTYPE_ASYNC:3`

An asynchronous call has arrived. Calls of this type cannot be rejected. OLE always delivers calls of this type.

### `CALLTYPE_TOPLEVEL_CALLPENDING:4`

A new top-level call has arrived with a new logical thread identifier and the object is currently waiting for a reply from a previous outgoing call. Calls of this type may be handled or rejected.

### `CALLTYPE_ASYNC_CALLPENDING:5`

An asynchronous call has arrived with a new logical thread identifier and the object is currently waiting for a reply from a previous outgoing call. Calls of this type cannot be rejected.

## See also

[IMessageFilter::HandleInComingCall](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imessagefilter-handleincomingcall)