# IViewObjectEx::QueryHitRect

## Description

Indicates whether any point in a rectangle is within a given drawing aspect of an object.

## Parameters

### `dwAspect` [in]

The requested drawing aspect.

### `pRectBounds` [in]

An object bounding rectangle in client coordinates of the containing window. This rectangle is computed and passed by the container so that the object can meaningfully interpret the hit location.

### `pRectLoc` [in]

The hit test rectangle, specified in **HIMETRIC** units, relative to the top-left corner of the object.

### `lCloseHint` [in]

The suggested distance, in **HIMETRIC** units, that the container considers close. This value is a hint, and objects can interpret it in their own way. Objects can also use this hint to roughly infer output resolution to choose expansiveness of hit test implementation.

### `pHitResult` [out]

A pointer to returned information about the hit expressed as the [HITRESULT](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-hitresult) enumeration values.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | This method is not implemented for the requested aspect. Use DVASPECT_CONTENT instead. |

## Remarks

Containers may need to test whether an object overlaps a given drawing aspect of another object. They can determine whether the objects overlap by requesting a region or at least a bounding rectangle of the aspect in question. However, a quicker way to do this is to call **IViewObjectEx::QueryHitRect** to ask the object whether a given rectangle intersects one of its drawing aspects.

**Note** Unlike [IViewObjectEx::QueryHitPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-queryhitpoint), this method does not return HITRESULT_TRANSPARENT or HITRESULT_CLOSE. It is strictly hit or miss, returning HITRESULT_OUTSIDE if no point in the rectangle is hit and HITRESULT_HIT if at least one point in the rectangle is a hit.

### Notes to Implementers

An object supporting [IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex) is required to implement this method at least for the DVASPECT_CONTENT aspect. The object should not take any other action in response to this method other than to return the information; there should be no side-effects. If there is any ambiguity about whether a point is a hit, for instance due to coordinates not converting exactly, the object should return HITRESULT_HIT whenever any point in the rectangle might be a hit on the object. That is, it is permissible to claim a hit for a point that is not actually rendered, but never correct to claim a miss for any point that is in the rendered image of the object.

## See also

[HITRESULT](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-hitresult)

[IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex)