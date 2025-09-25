# IViewObjectEx::GetRect

## Description

Retrieves a rectangle describing a requested drawing aspect.

## Parameters

### `dwAspect` [in]

The drawing aspect requested.

### `pRect` [out]

A pointer to the rectangle describing the requested drawing aspect.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **DV_E_DVASPECT** | The method does not support the specified aspect. Either the object does not support the aspect requested or the aspect is not rectangular. |

## Remarks

This method returns a rectangle describing the specified drawing aspect. The returned rectangle is in **HIMETRIC** units, relative to the object's origin. The rectangle returned depends on the drawing aspect as follows.

| Drawing Aspect | Description |
| --- | --- |
| DVASPECT_CONTENT | Objects should return the bounding rectangle of the whole object. The top-left corner is at the object's origin and the size is equal to the extent returned by [IViewObject2::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject2-getextent). |
| DVASPECT_OPAQUE | Objects with a rectangular opaque region should return that rectangle. Others should fail and return error code DV_E_DVASPECT.<br><br>If a rectangle is returned, it is guaranteed to be completely obscured by calling [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) for that aspect. The container should use that rectangle to clip out the object's opaque parts before drawing any object behind it during the back to front pass. If this method fails on an object with a non-rectangular opaque region, the container should draw the entire object in the back to front part using the DVASPECT_CONTENT aspect. |
| DVASPECT_TRANSPARENT | Objects should return the rectangle covering all transparent or irregular parts. If the object does not have any transparent or irregular parts, it may return DV_E_ASPECT. A container may use this rectangle to determine whether there are other objects overlapping the transparent parts of a given object. |

## See also

[IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex)