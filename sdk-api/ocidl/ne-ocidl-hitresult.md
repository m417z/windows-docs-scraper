# HITRESULT enumeration

## Description

Indicates whether a location is within the image of an object.

## Constants

### `HITRESULT_OUTSIDE:0`

The specified location is outside the object and not close to the object.

### `HITRESULT_TRANSPARENT:1`

The specified location is within the bounds of the object, but not close to the image. For example, a point in the middle of a transparent circle could be HITRESULT_TRANSPARENT.

### `HITRESULT_CLOSE:2`

The specified location is inside the object or is outside the object but is close enough to the object to be considered inside. Small, thin or detailed objects may use this value. Even if a point is outside the bounding rectangle of an object it may still be close. This value is needed for hitting small objects.

### `HITRESULT_HIT:3`

The specified location is within the image of the object.

## See also

[IViewObjectEx::QueryHitPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-queryhitpoint)

[IViewObjectEx::QueryHitRect](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-queryhitrect)