# IOleLink::UnbindSource

## Description

Breaks the connection between a linked object and its link source.

## Return value

This method returns S_OK on success.

## Remarks

You typically do not call **UnbindSource** directly. When it's necessary to deactivate the connection to the link source, your container typically calls [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close) or [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release); the linked object's implementation of these methods calls **UnbindSource**. The linked object's [IAdviseSink::OnClose](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onclose) implementation also calls **UnbindSource**.

### Notes to Implementers

The linked object's implementation of **UnbindSource** does nothing if the link source is not currently bound. If the link source is bound, **UnbindSource** calls the link source's [IOleObject::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise) and [IDataObject::DUnadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dunadvise) implementations to delete the advisory connections to the link source. The **UnbindSource** method also calls the compound document's [IOleContainer::LockContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecontainer-lockcontainer) implementation to unlock the containing compound document. This undoes the lock on the container and the advisory connections that were established in [IOleLink::BindToSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-bindtosource). **UnbindSource** releases all the linked object's interface pointers to the link source.

## See also

[IAdviseSink::OnClose](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onclose)

[IDataObject::DUnadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dunadvise)

[IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink)

[IOleLink::BindToSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-bindtosource)

[IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close)

[IOleObject::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise)