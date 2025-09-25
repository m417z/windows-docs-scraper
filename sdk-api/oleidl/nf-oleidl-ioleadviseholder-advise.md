# IOleAdviseHolder::Advise

## Description

Establishes an advisory connection between an OLE object and the calling object's advise sink. Through that sink, the calling object can receive notification when the OLE object is renamed, saved, or closed.

## Parameters

### `pAdvise` [in]

A pointer to the [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface on the advisory sink that should be informed of changes.

### `pdwConnection` [out]

A pointer to a token that can be passed to the [IOleAdviseHolder::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-unadvise) method to delete the advisory connection. The calling object is responsible for calling both [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) and [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on this pointer.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The supplied [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface pointer is invalid. |

## Remarks

Containers, object handlers, and link objects all create advise sinks to receive notification of changes in compound-document objects of interest, such as embedded or linked objects. OLE objects of interest to these objects must implement the [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) interface, which includes several advisory methods, including [IOleObject::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-advise). A call to this method must set up an advisory connection with any advise sink that calls it, and maintain each connection until it is closed. It must be able to handle more than one advisory connection at a time.

**IOleAdviseHolder::Advise** is intended to be used to simplify the implementation of [IOleObject::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-advise). You can get a pointer to the OLE implementation of IOleAdviseHolder by calling [CreateOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createoleadviseholder), and then, to implement **IOleObject::Advise**, just delegate the call to **IOleAdviseHolder::Advise**. Other [IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder) methods are intended to implement other [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) advisory methods.

If the attempt to establish an advisory connection is successful, the object receiving the call returns a nonzero value through *pdwConnection*. If the attempt fails, the object returns a zero. To delete an advisory connection, the object with the advise sink passes this nonzero token back to the object by calling **IOleAdviseHolder::Advise**.

## See also

[IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder)

[IOleAdviseHolder::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-enumadvise)

[IOleAdviseHolder::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-unadvise)

[IOleObject::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-advise)