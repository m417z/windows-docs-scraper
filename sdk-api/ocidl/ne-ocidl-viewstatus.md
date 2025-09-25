# VIEWSTATUS enumeration

## Description

Specifies the opacity of the object and the drawing aspects supported by the object.

## Constants

### `VIEWSTATUS_OPAQUE:1`

The object is completely opaque. So, for any aspect, it promises to draw the entire rectangle passed to the [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) method. If this value is not set, the object contains transparent parts. If it also support DVASPECT_TRANSPARENT, then this aspect may be used to draw the transparent parts only.

This bit applies only to CONTENT related aspects and not to DVASPECT_ICON or DVASPECT_DOCPRINT.

### `VIEWSTATUS_SOLIDBKGND:2`

The object has a solid background (consisting in a solid color, not a brush pattern). This bit is meaningful only if VIEWSTATUS_OPAQUE is set.

This bit applies only to CONTENT related aspects and not to DVASPECT_ICON or DVASPECT_DOCPRINT.

### `VIEWSTATUS_DVASPECTOPAQUE:4`

The object supports DVASPECT_OPAQUE. All [IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex) methods taking a drawing aspect as a parameter can be called with this aspect.

### `VIEWSTATUS_DVASPECTTRANSPARENT:8`

The object supports DVASPECT_TRANSPARENT. All [IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex) methods taking a drawing aspect as a parameter can be called with this aspect.

### `VIEWSTATUS_SURFACE:16`

The object supports a 2-dimensional surface.

### `VIEWSTATUS_3DSURFACE:32`

The object supports a 3-dimensional surface.

## See also

[IViewObjectEx::GetViewStatus](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-getviewstatus)