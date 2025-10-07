# IPropertyDescription2::GetImageReferenceForValue

## Description

Gets the image reference associated with a property value.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) for which to get an image.

### `ppszImageRes` [out]

Type: **LPWSTR***

A pointer to a buffer that receives, when this method returns successfully, a string of the form \<dll name>,-\<resid> that is suitable to be passed to [PathParseIconLocation](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathparseiconlocationa).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.