# IOleInPlaceSiteEx::OnInPlaceDeactivateEx

## Description

Notifies the container if the object needs to be redrawn upon deactivation.

## Parameters

### `fNoRedraw` [in]

If **TRUE**, the container need not redraw the object after completing the deactivation; if **FALSE** the object must be redrawn after deactivation.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

This method replaces [IOleInPlaceSite::OnInPlaceDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-oninplacedeactivate). If the older method is used, the object must always be redrawn on deactivation.

## See also

[IOleInPlaceSite::OnInPlaceDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-oninplacedeactivate)

[IOleInPlaceSiteEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex)