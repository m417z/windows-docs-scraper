# IPropertyPage::Deactivate

## Description

Destroys the window created in [IPropertyPage::Activate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-activate).

## Return value

This method can return the standard return values E_UNEXPECTED and S_OK.

## Remarks

### Notes to Implementers

It is important that property pages not keep the dialog box around as an optimization. In a property sheet with many property pages, memory consumption would become excessive if all property pages kept their dialog boxes created at all times. Destroying the dialog box prevents excessive memory consumption due to a very large number of created controls in the dialog boxes. If the frame wishes to keep pages alive while they are not visible, it can use [IPropertyPage::Show](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-show) for that purpose. The decision is ultimately left to the frame.

E_NOTIMPL is not a valid return value.

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)