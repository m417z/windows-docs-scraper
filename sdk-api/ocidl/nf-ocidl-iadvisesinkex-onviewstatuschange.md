# IAdviseSinkEx::OnViewStatusChange

## Description

Notifies the sink that a view status of an object has changed.

## Parameters

### `dwViewStatus` [in]

The new view status. Possible values are from the [VIEWSTATUS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-viewstatus) enumeration.

## Return value

This method returns S_OK on success.

## Remarks

It is important that objects call the [IAdviseSink:OnViewChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onviewchange) method whenever the object's view changes even when the object is in place active. Containers rely on this notification to keep an object's view up-to-date.

## See also

[IAdviseSink:OnViewChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onviewchange)

[IAdviseSinkEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iadvisesinkex)