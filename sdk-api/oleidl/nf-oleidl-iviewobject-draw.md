# IViewObject::Draw

## Description

Draws a representation of an object onto the specified device context.

## Parameters

### `dwDrawAspect` [in]

Specifies the aspect to be drawn, that is, how the object is to be represented. Representations include content, an icon, a thumbnail, or a printed document. Valid values are taken from the enumerations [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) and [DVASPECT2](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-dvaspect2). Note that newer objects and containers that support optimized drawing interfaces support the **DVASPECT2** enumeration values. Older objects and containers that do not support optimized drawing interfaces may not support **DVASPECT2**. Windowless objects allow only **DVASPECT**_CONTENT, **DVASPECT**_OPAQUE, and **DVASPECT**_TRANSPARENT.

### `lindex` [in]

Portion of the object that is of interest for the draw operation. Its interpretation varies depending on the value in the dwAspect parameter. See the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) enumeration for more information.

### `pvAspect` [in]

Pointer to additional information in a [DVASPECTINFO](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-dvaspectinfo) structure that enables drawing optimizations depending on the aspect specified. Note that newer objects and containers that support optimized drawing interfaces support this parameter as well. Older objects and containers that do not support optimized drawing interfaces always specify **NULL** for this parameter.

### `ptd` [in]

Pointer to the [DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice) structure that describes the device for which the object is to be rendered. If **NULL**, the view should be rendered for the default target device (typically the display). A value other than **NULL** is interpreted in conjunction with *hdcTargetDev* and *hdcDraw*. For example, if *hdcDraw* specifies a printer as the device context, the *ptd* parameter points to a structure describing that printer device. The data may actually be printed if *hdcTargetDev* is a valid value or it may be displayed in print preview mode if *hdcTargetDev* is **NULL**.

### `hdcTargetDev` [in]

Information context for the target device indicated by the ptd parameter from which the object can extract device metrics and test the device's capabilities. If *ptd* is **NULL**; the object should ignore the value in the *hdcTargetDev* parameter.

### `hdcDraw` [in]

Device context on which to draw. For a windowless object, the *hdcDraw* parameter should be in MM_TEXT mapping mode with its logical coordinates matching the client coordinates of the containing window. For a windowless object, the device context should be in the same state as the one normally passed by a WM_PAINT message.

### `lprcBounds` [in]

Pointer to a RECTL structure specifying the rectangle on *hdcDraw* and in which the object should be drawn. This parameter controls the positioning and stretching of the object. This parameter should be **NULL** to draw a windowless in-place active object. In every other situation, **NULL** is not a legal value and should result in an E_INVALIDARG error code. If the container passes a non-**NULL** value to a windowless object, the object should render the requested aspect into the specified device context and rectangle. A container can request this from a windowless object to render a second, non-active view of the object or to print the object.

### `lprcWBounds` [in]

If *hdcDraw* is a metafile device context, pointer to a RECTL structure specifying the bounding rectangle in the underlying metafile. The rectangle structure contains the window extent and window origin. These values are useful for drawing metafiles. The rectangle indicated by *lprcBounds* is nested inside this *lprcWBounds* rectangle; they are in the same coordinate space.

If *hdcDraw* is not a metafile device context; *lprcWBounds* will be **NULL**.

### `pfnContinue` [in]

Pointer to a callback function that the view object should call periodically during a lengthy drawing operation to determine whether the operation should continue or be canceled. This function returns **TRUE** to continue drawing. It returns **FALSE** to stop the drawing in which case **IViewObject::Draw** returns DRAW_E_ABORT.

#### dwContinue

### `dwContinue` [in]

Value to pass as a parameter to the function pointed to by the *pfnContinue* parameter. Typically, *dwContinue* is a pointer to an application-defined structure needed inside the callback function.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_BLANK** | No data to draw from. |
| **DRAW_E_ABORT** | Draw operation aborted. |
| **VIEW_E_DRAW** | Error in drawing. |
| **DV_E_LINDEX** | Invalid value for lindex; currently only -1 is supported. |
| **DV_E_DVASPECT** | Invalid value for *dwAspect*. |
| **OLE_E_INVALIDRECT** | Invalid rectangle. |

## Remarks

A container application issues a call to **IViewObject::Draw** to create a representation of a contained object. This method draws the specified piece (*lindex*) of the specified view (*dwAspect* and *pvAspect*) on the specified device context (*hdcDraw*). Formatting, fonts, and other rendering decisions are made on the basis of the target device specified by the ptd parameter.

There is a relationship between the *dwDrawAspect* value and the *lprcbounds* value. The *lprcbounds* value specifies the rectangle on *hdcDraw* into which the drawing is to be mapped. For [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)_THUMBNAIL, **DVASPECT**_ICON, and **DVASPECT**_SMALLICON, the object draws whatever it wants to draw, and it maps it into the space given in the best way. Some objects might scale to fit while some might scale to fit but preserve the aspect ratio. In addition, some might scale so the drawing appears at full width, but the bottom is cropped. The container can suggest a size via [IOleObject::SetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setextent), but it has no control over the rendering size. In the case of **DVASPECT**_CONTENT, the **IViewObject::Draw** implementation should either use the extents given by **IOleObject::SetExtent** or use the bounding rectangle given in the *lprcBounds* parameter.

For newer objects that support optimized drawing techniques and for windowless objects, this method should be used as follows:

* New drawing aspects are supported in *dwAspect* as defined in [DVASPECT2](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-dvaspect2).
* The pvAspect parameter can be used to pass additional information allowing drawing optimizations through the [DVASPECTINFO](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-dvaspectinfo) structure.
* The **IViewObject::Draw** method can be called to redraw a windowless in-place active object by setting the *lrpcBounds* parameter to **NULL**. In every other situation, **NULL** is an illegal value and should result in an E_INVALIDARG error code. A windowless object uses the rectangle passed by the activation verb or calls [IOleInPlaceObject::SetObjectRects](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-setobjectrects) instead of using this parameter. If the container passes a non-**NULL** value to a windowless object, the object should render the requested aspect into the specified device context and rectangle. A container can request this from a windowless object to render a second, non-active view of the object or to print the object. See the [IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless) interface for more information on drawing windowless objects.
* For windowless objects, the *dwAspect* parameter only allows the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)_CONTENT, **DVASPECT**_OPAQUE, and **DVASPECT**_TRANSPARENT aspects.
* For a windowless object, the hdcDraw parameter should be in MM_TEXT mapping mode with its logical coordinates matching the client coordinates of the containing window. For a windowless object, the device context should be in the same state as the one normally passed by a WM_PAINT message.

To maintain compatibility with older objects and containers that do not support drawing optimizations, all objects, rectangular or not, are required to maintain an origin and a rectangular extent. This allows the container to still consider all its embedded objects as rectangles and to pass them appropriate rendering rectangles in **Draw**.

An object's extent depends on the drawing aspect. For non-rectangular objects, the extent should be the size of a rectangle covering the entire aspect. By convention, the origin of an object is the top-left corner of the rectangle of the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)_CONTENT aspect. In other words, the origin always coincides with the top-left corner of the rectangle maintained by the object's site, even for a non-rectangular object.

## See also

[DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)

[DVASPECT2](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-dvaspect2)

[DVASPECTINFO](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-dvaspectinfo)

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)

[IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject)

[OleDraw](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-oledraw)