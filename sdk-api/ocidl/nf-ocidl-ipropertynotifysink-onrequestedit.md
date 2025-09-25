# IPropertyNotifySink::OnRequestEdit

## Description

Notifies a sink that a [requestedit](https://learn.microsoft.com/windows/desktop/Midl/requestedit) property is about to change.

## Parameters

### `dispID` [in]

The dispatch identifier of the property that is about to change or DISPID_UNKNOWN if multiple properties are about to change.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The specified property or properties are allowed to change. |
| **S_FALSE** | The specified property or properties are not allowed to change. The caller must obey this return value by discarding the new property value(s). This is part of the contract of the [[requestedit](https://learn.microsoft.com/windows/desktop/Midl/requestedit)] attribute and this method. |

## Remarks

The sink may choose to allow or disallow the change to take place. For example, the sink may enforce a read-only state on the property. DISPID_UNKNOWN is a valid parameter to this method to indicate that multiple properties are about to change. In this case, the sink can enforce a global read-only state for all [[requestedit](https://learn.microsoft.com/windows/desktop/Midl/requestedit)] properties in the object, including any specific ones that the sink otherwise recognizes.

If the sink allows changes, the object must also make [IPropertyNotifySink::OnChanged](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertynotifysink-onchanged) notifications for any properties that are marked [[bindable](https://learn.microsoft.com/windows/desktop/Midl/bindable)] in addition to [[requestedit](https://learn.microsoft.com/windows/desktop/Midl/requestedit)].

This method cannot be used to implement any sort of data validation. At the time of the call, the desired new value of the property is unavailable and thus cannot be validated. This method's only purpose is to allow the sink to enforce a read-only state on a property.

## See also

[IPropertyNotifySink](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink)