# IPropertyPage::IsPageDirty

## Description

Indicates whether the property page has changed since it was activated or since the most recent call to [Apply](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-apply).

## Return value

This method returns S_OK to indicate that the property page has changed. Otherwise, it returns S_FALSE.

## Remarks

The property sheet uses this information to enable or disable the **Apply** button in the dialog box. There is no need to apply the values on a property page if those values are already current with the underlying objects.

### Notes to Implementers

This method has no reason to return an error code, since the inability to determine if the page is dirty should return S_OK as a default. In this way, the user has a chance to update the values. The page should not return an error code, since an error code is not the same as S_OK and would indicate that the page is not dirty. Then, the property frame could potentially disable the **Apply** button, not allowing the user to make sure that the property values are current.

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)