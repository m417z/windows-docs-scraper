# IAdviseSink::OnRename

## Description

Called by the server to notify all registered advisory sinks that the object has been renamed.

## Parameters

### `pmk` [in]

 A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the new full moniker of the object.

## Remarks

OLE link objects normally implement **IAdviseSink::OnRename** to receive notification of a change in the name of a link source or its container. The object serving as the link source calls **OnRename** and passes its new full moniker to the object handler, which forwards the notification to the link object. In response, the link object must update its moniker. The link object, in turn, forwards the notification to its own container.

## See also

[IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink)