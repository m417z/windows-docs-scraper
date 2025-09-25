# INTERFACEINFO structure

## Description

Contains information about incoming calls.

## Members

### `pUnk`

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the object.

### `iid`

The identifier of the requested interface.

### `wMethod`

The interface method.

## See also

[IMessageFilter::HandleInComingCall](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imessagefilter-handleincomingcall)