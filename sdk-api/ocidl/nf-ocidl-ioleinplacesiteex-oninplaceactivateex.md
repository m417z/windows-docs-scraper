# IOleInPlaceSiteEx::OnInPlaceActivateEx

## Description

Called by the embedded object to determine whether it needs to redraw itself upon activation.

## Parameters

### `pfNoRedraw` [out]

A pointer to a variable that receives the current redraw status. The status is **TRUE** if the object need not redraw itself upon activation and **FALSE** otherwise. Windowless objects usually do not need the value returned by this parameter and may pass a **NULL** pointer to save the container the burden of computing this value.

### `dwFlags` [in]

Indicates whether the object is activated as a windowless object. This parameter takes values from the [ACTIVATEFLAGS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-activateflags) enumeration. See [IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless) for more information on windowless objects.

## Return value

This method returns S_OK if the container allows the in-place activation.
Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

This method replaces [IOleInPlaceSite::OnInPlaceActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-oninplaceactivate). If the older method is used, the object must always redraw itself on activation.

Windowless objects are required to use this method instead of [IOleInPlaceSite::OnInPlaceActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-oninplaceactivate) to notify the container of whether they are activating windowless or not.

### Notes to Implementers

The container should carefully check the invalidation status of the object, its z-order, clipping and any other relevant parameters to determine the appropriate value to return in *pfNoRedraw*.

A container can cache the value of the [ACTIVATEFLAGS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-activateflags) enumeration instead of calling the [GetWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolewindow-getwindow) method in the [IOleInPlaceObjectWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless) interface repeatedly.

## See also

[ACTIVATEFLAGS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-activateflags)

[IOleInPlaceObjectWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless)

[IOleInPlaceSite::OnInPlaceActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-oninplaceactivate)

[IOleInPlaceSiteEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex)

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)