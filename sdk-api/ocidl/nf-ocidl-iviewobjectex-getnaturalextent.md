# IViewObjectEx::GetNaturalExtent

## Description

Provides sizing hints from the container for the object to use as the user resizes it.

## Parameters

### `dwAspect` [in]

The requested drawing aspect. It can be any of the following values, which are defined by the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) enumeration.

| Value | Meaning |
| --- | --- |
| **DVASPECT_CONTENT** | Provide a representation of the control so it can be displayed as an embedded object inside of a container. This value is typically specified for compound document objects. The presentation can be provided for the screen or printer. |
| **DVASPECT_DOCPRINT** | Provide a representation of the control on the screen as though it were printed to a printer using the **Print** command from the **File** menu. The described data may represent a sequence of pages. |
| **DVASPECT_ICON** | Provide an iconic representation of the control. |
| **DVASPECT_THUMBNAIL** | Provide a thumbnail representation of an object so it can be displayed in a browsing tool. The thumbnail is approximately a 120 by 120 pixel, 16-color (recommended) device-independent bitmap potentially wrapped in a metafile. |

### `lindex` [in]

Indicates the portion of the object that is of interest for the draw operation. Its interpretation varies depending on the value in the *dwAspect* parameter. See the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) enumeration for more information.

### `ptd` [in]

Pointer to the target device structure that describes the device for which the object is to be rendered. If **NULL**, the view should be rendered for the default target device (typically the display). A value other than **NULL** is interpreted in conjunction with *hicTargetDev* and **hdcDraw**. For example, if **hdcDraw** specifies a printer as the device context, the *ptd* parameter points to a structure describing that printer device. The data may actually be printed if *hicTargetDev* is a valid value or it may be displayed in print preview mode if *hicTargetDev* is **NULL**.

### `hicTargetDev` [in]

Specifies the information context for the target device indicated by the ptd parameter from which the object can extract device metrics and test the device's capabilities. If *ptd* is **NULL**; the object should ignore the value in the *hicTargetDev* parameter.

### `pExtentInfo` [in]

Pointer to [DVEXTENTINFO](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-dvextentinfo) structure that specifies the sizing data.

### `pSizel` [out]

Pointer to sizing data returned by the object. The returned sizing data is set to -1 for any dimension that was not adjusted. That is if **cx** is -1 then the width was not adjusted, if **cy** is -1 then the height was not adjusted. If E_FAIL is returned indicating no size was adjusted then *pSizel* may be **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | This method is not implemented for the specified *dwAspect*, or the size was not adjusted. |
| **E_NOTIMPL** | This method was not implemented. |

## Remarks

There are two general approaches to sizing a control. The first approach gives the control responsibility for sizing itself; the second approach gives the container responsibility for sizing the control. The first approach is called autosizing. There are two alternatives involved in the second approach: content sizing and integral sizing.

The **IViewObjectEx::GetNaturalExtent** method supports both content and integral sizing. In content sizing, the container passes the [DVEXTENTINFO](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-dvextentinfo) structure to the object into which the object returns a suggested size. In integral sizing, the container passes a preferred size to the object in **DVEXTENTINFO**, and the object actually adjusts its height. Integral sizing is used when the user rubberbands a new size in design mode.

Autosizing typically occurs with objects such as the Label control which resizes if the autosize property was enabled and the associated text changed. Autosizing is handled differently depending on the state of the object.

If the object is inactive, the following occurs:

1. The object calls [IOleClientSite::RequestNewObjectLayout](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-requestnewobjectlayout).
2. The container calls [IOleObject::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent) and retrieves the new extents.
3. The container calls [IOleObject::SetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setextent) and adjusts the new extents.

If the object is active, the following occurs:

1. The object calls [IOleInPlaceSite::OnPosRectChange](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onposrectchange) to specify that it requires resizing.
2. The container calls [IOleInPlaceObject::SetObjectRects](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-setobjectrects) and specifies the new size.

## See also

[IOleClientSite::RequestNewObjectLayout](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-requestnewobjectlayout)

[IOleInPlaceObject::SetObjectRects](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-setobjectrects)

[IOleInPlaceSite::OnPosRectChange](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onposrectchange)

[IOleObject::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent)

[IOleObject::SetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setextent)

[IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex)