# DVASPECTINFOFLAG enumeration

## Description

Indicates whether an object can support optimized drawing of itself.

## Constants

### `DVASPECTINFOFLAG_CANOPTIMIZE:1`

Indicates that the object can support optimized rendering of itself. Because most objects on a form share the same font, background color, and border types, leaving these values in the device context allows the next object to use them without having to re-select them. Specifically, the object can leave the font, brush, and pen selected on return from the [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) method instead of deselecting these from the device context. The container then must deselect these values at the end of the overall drawing process. The object can also leave other drawing state changes in the device context, such as the background color, the text color, raster operation code, the current point, the line drawing, and the poly fill mode. The object cannot change state values unless other objects are capable of restoring them. For example, the object cannot leave a changed mode, transformation value, selected bitmap, clip region, or metafile.

## See also

[DVASPECTINFO](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-dvaspectinfo)