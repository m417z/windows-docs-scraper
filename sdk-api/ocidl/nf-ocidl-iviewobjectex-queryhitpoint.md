# IViewObjectEx::QueryHitPoint

## Description

Indicates whether a point is within a given aspect of an object.

## Parameters

### `dwAspect` [in]

The requested drawing aspect.

### `pRectBounds` [in]

An object bounding rectangle in client coordinates of the containing window. This rectangle is computed and
passed by the container so that the object can meaningfully interpret the hit location.

### `ptlLoc` [in]

The hit location in client coordinates of the containing window.

### `lCloseHint` [in]

Suggested distance in **HIMETRIC** units that the container considers close. This
value is a hint, and objects can interpret it in their own way. Objects can also use this hint to roughly infer
output resolution to choose expansiveness of hit test implementation.

### `pHitResult` [out]

A pointer to returned information about the hit expressed as the
[HITRESULT](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-hitresult) enumeration values.

## Return value

This method returns **S_OK** on success. Other possible return values include the
following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | This method is not implemented for the requested aspect. Use [DVASPECT_CONTENT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) instead. |

## Remarks

To support hit detection on non-rectangular objects, the container needs a reliable way to ask an object
whether a given location is inside one of its drawing aspects. This function is provided by
**IViewObjectEx::QueryHitPoint**.

**Note** Because this method is part of the [IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex)
interface, the container can figure whether a mouse hit is over an object without having to necessarily launch
the server. If the hit happens to be inside the object, then it is likely that the object will be in-place
activated and the server started.

Typically, the container first quickly determines whether a given location is within the rectangular extent of
an object. If the location is within the rectangular extent of an object, the container calls
**IViewObjectEx::QueryHitPoint** to get
confirmation that the location is actually inside the object. The hit location is passed in client coordinates of
the container window. Since the object may be inactive when this method is called, the bounding rectangle of the
object in the same coordinate system is also passed to this method, similarly to what happens in
[IPointerInactive::OnInactiveSetCursor](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-oninactivesetcursor).

Possible returned values include:

* Outside, on a transparent region
* Close enough to be considered a hit (may be used by small or thin objects)
* Hit

**IViewObjectEx::QueryHitPoint** is not
concerned by the sub-objects of the object it is called for. It merely indicates whether the mouse hit was within
the object or not.

**IViewObjectEx::QueryHitPoint** can be called
for any of the drawing aspects an object supports. It should fail if the it is not supported for the requested
drawing aspect.

Transparent objects may wish to implement a complex hit-detection mechanism where the user can select either
the transparent object or an object behind it, depending on where exactly the click happens inside the object.
For example, a transparent text box showing big enough text may let the user select the object behind, for
example, a bitmap, when the user clicks between the characters. For this reason, the information returned by
**IViewObjectEx::QueryHitPoint** includes
indication about whether the hit happens on an opaque or transparent region.

An example of non-rectangular and transparent hit detection is a transparent circle control with an object
behind it (a line in the example below):

:::image type="content" source="./images/a7c7fe0d-f171-4823-ba4c-b51cb90d8733.png" border="false" alt-text="Diagram of a circle with a diagonal line through it, showing the hit detection values for the areas inside and outside the circle and near the line.":::

The values shown are for hit tests against the circle; gray regions are not part of the control, but are shown
here to indicate an area around the image considered close. Each object implements its own definition of close
but is assisted by a hint provided by the container so that closeness can be adjusted as images zoom larger or
smaller.

In the picture above, the points marked Hit, Close, and Transparent would all be hits of varying strength on
the circle, with the exception of the one marked Transparent, (but for the line, close). This illustrates the
effect of the different strength of hits. Because the circle responds transparent while the line claims close,
and transparent is weaker than close, the line takes the hit.

### Notes to Implementers

An object supporting [IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex) is required to
implement this method at least for the **DVASPECT_CONTENT** aspect. The object should
not take any other action in response to this method other than to return the information; there should be no
side-effects.

## See also

[HITRESULT](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-hitresult)

[IPointerInactive::OnInactiveSetCursor](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-oninactivesetcursor)

[IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex)