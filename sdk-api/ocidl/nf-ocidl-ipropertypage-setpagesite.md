# IPropertyPage::SetPageSite

## Description

Initializes a property page and provides the page with a pointer to the [IPropertyPageSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypagesite) interface through which the property page communicates with the property frame.

## Parameters

### `pPageSite` [in]

A pointer to the [IPropertyPageSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypagesite) interface of the page site that manages and provides services to this property page within the entire property sheet.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## Remarks

### Notes to Implementers

If the *pPageSite* parameter is **NULL**, this method must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on any [IPropertyPageSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypagesite) pointer passed during a previous call to this method. If non-**NULL**, this method must save the **IPropertyPageSite** pointer value and call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref). Two consecutive calls to this method with a non-**NULL** site pointer are not allowed and should cause the property page to return E_UNEXPECTED.

E_NOTIMPL is not a valid return value. All property pages must implement this method.

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)