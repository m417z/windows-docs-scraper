# IOleAdviseHolder::SendOnSave

## Description

Sends notification to all advisory sinks currently registered with the advise holder that the object has been saved.

## Return value

This method returns S_OK if advise sinks were sent [IAdviseSink::OnSave](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onsave) notifications.

## Remarks

**SendOnSave** calls [IAdviseSink::OnSave](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onsave) to advise the calling object (client), which must have already established an advisory connection, that the object has been saved. If you are using the OLE advise holder (having obtained a pointer through a call to [CreateOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createoleadviseholder)), you can call **SendOnSave** whenever you save the object the advise holder is associated with.

To take the object from the running state to the loaded state, the client calls [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close). Within that implementation, if the user wants to save the object to persistent storage, the object calls [IOleClientSite::SaveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-saveobject), followed by the call to **SendOnSave**.

## See also

[IAdviseSink::OnSave](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onsave)

[IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder)