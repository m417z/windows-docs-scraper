# IOleAdviseHolder::SendOnRename

## Description

Sends notification to all advisory sinks currently registered with the advise holder that the name of object has changed.

## Parameters

### `pmk` [in]

A pointer to the new full moniker of the object.

## Return value

This method returns S_OK if advise sinks were sent [IAdviseSink::OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename) notifications.

## Remarks

**SendOnRename** calls [IAdviseSink::OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename) to advise the calling object, which must have already established an advisory connection, that the object has a new moniker. If you are using the OLE advise holder (having obtained a pointer through a call to [CreateOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createoleadviseholder)), you can call **SendOnRename** in the implementation of [IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker), when you have determined that the operation is successful.

## See also

[IAdviseSink::OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename)

[IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder)