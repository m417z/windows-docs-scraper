# IPropertyPage::Apply

## Description

Applies the current values to the underlying objects associated with the property page as previously passed to
[IPropertyPage::SetObjects](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-setobjects).

## Return value

This method can return the standard return values **E_OUTOFMEMORY** and
**E_UNEXPECTED**, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Changes were successfully applied and the property page is current with the underlying objects. |
| **S_FALSE** | Changes were applied, but the property page cannot determine if its state is current with the objects. |

## Remarks

The objects to be changed are provided through a previous call to
[IPropertyPage::SetObjects](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-setobjects). By calling
**IPropertyPage::SetObjects** prior to calling this
method, the caller ensures that all underlying objects have the correct interfaces through which to communicate
changes. Therefore, this method should not fail because of non-existent interfaces.

After applying its values, the property page should determine if its state is now current with the objects in
order to properly implement
[IPropertyPage::IsPageDirty](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-ispagedirty) and to provide both
**S_OK** and **S_FALSE** return values.

### Notes to Implementers

E_NOTIMPL is not a valid return value.

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)