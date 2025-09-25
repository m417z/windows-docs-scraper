# IPropertyPage2::EditProperty

## Description

Specifies which field is to receive the focus when the property page is activated.

## Parameters

### `dispID` [in]

The property that is to receive the focus.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | This method is not currently implemented; the interface is probably provided in anticipation of future work on this page. |

## Remarks

### Notes to Implementers

If this method is called before a page is activated, the page should store the property and set the focus to it in the next call to [IPropertyPage::Activate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-activate). If the page is already active, **EditProperty** should set the focus to the specific property field.

## See also

[IPropertyPage2](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage2)