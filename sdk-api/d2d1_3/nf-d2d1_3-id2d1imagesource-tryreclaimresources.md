# ID2D1ImageSource::TryReclaimResources

## Description

Restores access to resources that were previously offered by calling [OfferResources](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nf-d2d1_3-id2d1imagesource-offerresources).

## Parameters

### `resourcesDiscarded` [out]

Type: **BOOL***

Returns with TRUE if the corresponding resource’s content was discarded and is now undefined, or FALSE if the corresponding resource’s old content is still intact.
The caller can pass in NULL, if the caller intends to fill the resources with new content regardless of whether the old content was discarded.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

**ReclaimResources** returns:

* **S_OK** if resources were successfully reclaimed
* **E_INVALIDARG** if the resources are invalid

## Remarks

After you call [OfferResources](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nf-d2d1_3-id2d1imagesource-offerresources) to offer one or more resources,
you must call **TryReclaimResources** before you can use those resources again.
You must check the value in the **resourcesDiscarded** to determine whether the resource’s content was discarded.
If a resource’s content was discarded while it was offered, its current content is undefined. Therefore, you must overwrite the resource’s content before you use the resource.

## See also

[ID2D1ImageSource](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1imagesource)