# OCPFIPARAMS structure

## Description

Contains parameters used to invoke a property sheet dialog box through the [OleCreatePropertyFrameIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepropertyframeindirect) function.

## Members

### `cbStructSize`

The size of the structure, in bytes.

### `hWndOwner`

Handle to the parent window of the resulting property sheet dialog box.

### `x`

Horizontal position for the dialog box relative to **hWndOwner**, in pixels.

### `y`

Vertical position for the dialog box relative to **hWndOwner**, in pixels.

### `lpszCaption`

Pointer to an [OLESTR](https://learn.microsoft.com/windows/desktop/api/wtypesbase/nf-wtypesbase-olestr) that contains the caption of the dialog.

### `cObjects`

Number of object pointers passed in **lplpUnk**.

### `lplpUnk`

Array of [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointers on the objects for which this property sheet is being invoked. The number of elements in the array is specified by **cObjects**. These pointers are passed to each property page through [IPropertyPage::SetObjects](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-setobjects).

### `cPages`

Number of property pages specified in **lpPages**.

### `lpPages`

Pointer to an array of size **cPages** containing the CLSIDs of each property page to display in the property sheet.

### `lcid`

Locale identifier for the property sheet. This value will be returned through [IPropertyPageSite::GetLocaleID](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypagesite-getlocaleid).

### `dispidInitialProperty`

Property that is highlighted when the dialog box is made visible.

## See also

[IPropertyPage::SetObjects](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-setobjects)

[IPropertyPageSite::GetLocaleID](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypagesite-getlocaleid)

[OLESTR](https://learn.microsoft.com/windows/desktop/api/wtypesbase/nf-wtypesbase-olestr)

[OleCreatePropertyFrameIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepropertyframeindirect)