# IPropertyPageSite::OnStatusChange

## Description

Informs the frame that the property page managed by this site has changed its state, that is, one or more property values have been changed in the page. Property pages should call this method whenever changes occur in their dialog boxes.

## Parameters

### `dwFlags` [in]

Indicates the changes that have occurred. This parameter can contain one of the following values.

| Value | Meaning |
| --- | --- |
| **PROPPAGESTATUS_DIRTY**<br><br>0x1 | The values in the pages have changed, so the state of the **Apply** button should be updated. |
| **PROPPAGESTATUS_VALIDATE**<br><br>0x2 | Now is an appropriate time to apply changes. |

## Return value

This method can return the standard return values E_INVALIDARG and S_OK.

## See also

[IPropertyPageSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypagesite)