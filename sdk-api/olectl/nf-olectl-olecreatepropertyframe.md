# OleCreatePropertyFrame function

## Description

Invokes a new property frame, that is, a property sheet dialog box, whose parent is *hwndOwner*, where the dialog is positioned at the point (x,y) in the parent window and has the caption *lpszCaption*.

## Parameters

### `hwndOwner` [in]

Handle to the parent window of the resulting property sheet dialog box.

### `x` [in]

Reserved. Horizontal position for the dialog box relative to *hwndOwner*.

### `y` [in]

Reserved. Vertical position for the dialog box relative to *hwndOwner*.

### `lpszCaption` [in]

Pointer to the string used for the caption of the dialog box.

### `cObjects` [in]

Number of object pointers passed in *ppUnk*.

### `ppUnk` [in]

An array of [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointers on the objects for which this property sheet is being invoked. The number of elements in the array is specified by *cObjects*. These pointers are passed to each property page through [IPropertyPage::SetObjects](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-setobjects).

### `cPages` [in]

Number of property pages specified in *pPageCIsID*.

### `pPageClsID` [in]

Array of size *cPages* containing the CLSIDs of each property page to display in the property sheet.

### `lcid` [in]

Locale identifier to use for the property sheet. Property pages can retrieve this identifier through [IPropertyPageSite::GetLocaleID](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypagesite-getlocaleid).

### `dwReserved` [in]

Reserved for future use; must be zero.

### `pvReserved` [in]

Reserved for future use; must be **NULL**.

## Return value

This function supports the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The dialog box was invoked and operated successfully. |
| **E_POINTER** | The address in *lpszCaption*, *ppUnk*, or *pPageCIsID* is not valid. For example, any one of them may be **NULL**. |

## Remarks

The property pages to be displayed are identified with *pPageClsID*, which is an array of *cPages* [CLSID](https://learn.microsoft.com/windows/desktop/com/clsid) values. The objects that are affected by this property sheet are identified in *ppUnk*, an array of size *cObjects* containing [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointers.

This function always creates a modal dialog box and does not return until the dialog box is closed.

## See also

[IPropertyPage::SetObjects](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-setobjects)

[IPropertyPageSite::GetLocaleID](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypagesite-getlocaleid)