# IPropertyNotifySink::OnChanged

## Description

Notifies a sink that a [bindable](https://learn.microsoft.com/windows/desktop/Midl/bindable) property has changed.

## Parameters

### `dispID` [in]

The dispatch identifier of the property that changed, or DISPID_UNKNOWN if multiple properties have changed. The client (owner of the sink) should retrieve the current value of each property of interest from the object that generated the notification.

## Return value

This method returns S_OK in all cases.

## Remarks

S_OK is returned in all cases even when the sink does not need [[bindable](https://learn.microsoft.com/windows/desktop/Midl/bindable)] properties or when some other failure has occurred. In short, the calling object simply sends the notification and cannot attempt to use an error code (such as E_NOTIMPL) to determine whether to not send the notification in the future. Such semantics are not part of this interface.

## See also

[IPropertyNotifySink](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink)