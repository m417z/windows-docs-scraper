# IOleObject::Advise

## Description

Establishes an advisory connection between a compound document object and the calling object's advise sink, through which the calling object receives notification when the compound document object is renamed, saved, or closed.

## Parameters

### `pAdvSink` [in]

Pointer to the [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface on the advise sink of the calling object.

### `pdwConnection` [out]

Pointer to a token that can be passed to [IOleObject::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise) to delete the advisory connection.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory available for this operation. |

## Remarks

The **IOleObject::Advise** method sets up an advisory connection between an object and its container, through which the object informs the container's advise sink of close, save, rename, and link-source change events in the object. A container calls this method, normally as part of initializing an object, to register its advisory sink with the object. In return, the object sends the container compound-document notifications by calling [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) or [IAdviseSink2](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink2).

If container and object successfully establish an advisory connection, the object receiving the call returns a nonzero value through *pdwConnection* to the container. If the attempt to establish an advisory connection fails, the object returns zero. To delete an advisory connection, the container calls [IOleObject::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise) and passes this nonzero token back to the object.

An object can delegate the job of managing and tracking advisory events to an OLE advise holder, to which you obtain a pointer by calling [CreateOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createoleadviseholder). The returned [IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder) interface has three methods for sending advisory notifications, as well as [IOleAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-advise), [IOleAdviseHolder::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-unadvise), and [IOleAdviseHolder::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-enumadvise) methods that are identical to those for [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject). Calls to **IOleObject::Advise**, [IOleObject::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise), or [IOleObject::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumadvise) are delegated to corresponding methods in the advise holder.

To destroy the advise holder, simply call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the [IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder) interface.

## See also

[CreateOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createoleadviseholder)

[IOleAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-advise)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumadvise)

[IOleObject::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise)