# IPicture::PictureChanged

## Description

Notifies the picture object that its picture resource has changed. This method only calls [IPropertyNotifySink::OnChanged](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertynotifysink-onchanged) with DISPID_PICT_HANDLE for any connected sinks.

## Return value

This method S_OK if it succeeds and E_FAIL if the picture object is uninitialized.

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)