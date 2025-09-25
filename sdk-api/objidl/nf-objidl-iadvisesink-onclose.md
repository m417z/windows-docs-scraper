# IAdviseSink::OnClose

## Description

Called by the server to notify all registered advisory sinks that the object has changed from the running to the loaded state.

## Remarks

The **OnClose** notification indicates that an object is making the transition from the running to the loaded state, so its container can take appropriate measures to ensure an orderly shutdown. For example, an object handler must release its pointer to the object.

If the object that is closing is the last open object supported by its OLE server application, the application can also shut down.

In the case of a link object, the notification that the object is closing should always be interpreted to mean that the connection to the link source has broken.

## See also

[IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink)