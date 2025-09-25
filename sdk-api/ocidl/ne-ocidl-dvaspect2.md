# DVASPECT2 enumeration

## Description

Specifies new drawing aspects used to optimize the drawing process.

## Constants

### `DVASPECT_OPAQUE:16`

Represents the opaque, easy to clip parts of an object. Objects may or may not support this aspect.

### `DVASPECT_TRANSPARENT:32`

Represents the transparent or irregular parts of on object, typically parts that are expensive or impossible to clip out. Objects may or may not support this aspect.

## Remarks

To support drawing optimizations to reduce flicker, an object needs to be able to draw and return information about three separate aspects of itself.

| Aspect | Description |
| --- | --- |
| DVASPECT_CONTENT | Specifies the entire content of an object. All objects should support this aspect. |
| DVASPECT_OPAQUE | Represents the opaque, easy to clip parts of an object. Objects may or may not support this aspect. |
| DVASPECT_TRANSPARENT | Represents the transparent or irregular parts of on object, typically parts that are expensive or impossible to clip out. Objects may or may not support this aspect. |

The container can determine which of these drawing aspects an object supports by calling the new method [IViewObjectEx::GetViewStatus](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-getviewstatus). Individual bits return information about which aspects are supported. If an object does not support the [IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex) interface, it is assumed to support only DVASPECT_CONTENT.

Depending on which aspects are supported, the container can ask the object to draw itself during the front to back pass only, the back to front pass only, or both. The various possible cases are:

* Objects supporting only DVASPECT_CONTENT should be drawn during the back to front pass, with all opaque parts of any overlapping object clipped out. Since all objects should support this aspect, a container not concerned about flickering - maybe because it is drawing in an offscreen bitmap - can opt to draw all objects that way and skip the front to back pass.
* Objects supporting DVASPECT_OPAQUE may be asked to draw this aspect during the front to back pass. The container is responsible for clipping out the object's opaque regions before painting any further object behind it.
* Objects supporting DVASPECT_TRANSPARENT may be asked to draw this aspect during the back to front pass. The container is responsible for clipping out opaque parts of overlapping objects before letting an object draw this aspect.

Even when DVASPECT_OPAQUE and DVASPECT_TRANSPARENT are supported, the container is free to use these aspects or not. In particular, if it is painting in an offscreen bitmap and consequently is unconcerned about flicker, the container may use DVASPECT_CONTENT and a one-pass drawing only. However, in a two-pass drawing, if the container uses DVASPECT_OPAQUE during the front to back pass, then it must use DVASPECT_TRANSPARENT during the back to front pass to complete the rendering of the object.

## See also

[IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw)