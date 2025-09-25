# IPropertyPage::Activate

## Description

Creates the dialog box window for the property page.

The dialog box is created without a frame, caption, or system menu/controls. The text in the dialog should match the locale obtained through [IPropertyPageSite::GetLocaleID](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypagesite-getlocaleid).

## Parameters

### `hWndParent` [in]

The window handle of the parent of the dialog box that is being created.

### `pRect` [in]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the positioning information for the dialog box. This method must create its dialog box with the placement and dimensions described by this structure.

### `bModal` [in]

Indicates whether the dialog box frame is modal (**TRUE**) or modeless (**FALSE**).

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The address in *prc* is not valid. For example, it may be **NULL**. |

## Remarks

The property page maintains the window handle created in this process, which it uses to destroy the dialog box within [IPropertyPage::Deactivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-deactivate).

### Notes to Implementers

E_NOTIMPL is not a valid return value.

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)