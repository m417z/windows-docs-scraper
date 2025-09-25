# IOleAdviseHolder::SendOnClose

## Description

Sends notification to all advisory sinks currently registered with the advise holder that the object has closed.

## Return value

This method returns S_OK if advise sinks were notified of the close operation through a call to the [IAdviseSink::OnClose](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onclose) method.

## Remarks

**SendOnClose** must call [IAdviseSink::OnClose](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onclose) on all advise sinks that have a valid advisory connection with the object, whenever the object goes from the running state to the loaded state. This occurs through a call to [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close), so you can call **SendOnClose** when you determine that a Close operation has been successful.

## See also

[IAdviseSink::OnClose](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onclose)

[IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder)