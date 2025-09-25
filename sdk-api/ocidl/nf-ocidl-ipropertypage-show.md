# IPropertyPage::Show

## Description

Makes the property page dialog box visible or invisible. If the page is made visible, the page should set the focus to itself, specifically to the first property on the page.

## Parameters

### `nCmdShow` [in]

A command describing whether to become visible (SW_SHOW or SW_SHOWNORMAL) or hidden (SW_HIDE). No other values are valid for this parameter.

## Return value

This method can return the standard return values E_INVALIDARG, E_UNEXPECTED, and S_OK.

## Remarks

### Notes to Callers

Calls to this method must occur after a call to [IPropertyPage::Activate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-activate) and before a corresponding call to [IPropertyPage::Deactivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-deactivate).

### Notes to Implementers

E_NOTIMPL is not a valid return value. E_OUTOFMEMORY is not a valid return value, since no memory should be used in implementing this method.

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)