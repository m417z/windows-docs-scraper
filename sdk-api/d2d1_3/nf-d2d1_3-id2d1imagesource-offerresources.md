# ID2D1ImageSource::OfferResources

## Description

Allows the operating system to free the video memory of resources by discarding their content.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

**OfferResources** returns:

* **S_OK** if resources were successfully offered
* **E_INVALIDARG** if a resource in the array or the priority is invalid

## See also

[ID2D1ImageSource](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1imagesource)