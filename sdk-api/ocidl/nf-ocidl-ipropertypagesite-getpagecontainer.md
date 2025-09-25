# IPropertyPageSite::GetPageContainer

## Description

Retrieves a pointer to the object representing the entire property frame dialog box that contains all the pages. Calling this method could potentially allow one page to navigate to another.

However, there are no container interfaces defined for this role, so this method always fails in the property frame implementation.

## Parameters

### `ppUnk` [out]

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer variable that receives the interface pointer to the container object. If an error occurs, the implementation must set **ppUnk* to **NULL**.

## Return value

This method returns E_NOTIMPL.

## See also

[IPropertyPageSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypagesite)