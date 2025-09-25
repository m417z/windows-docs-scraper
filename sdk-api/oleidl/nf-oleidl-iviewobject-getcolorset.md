# IViewObject::GetColorSet

## Description

Returns the logical palette that the object will use for drawing in its [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) method with the corresponding parameters.

## Parameters

### `dwDrawAspect` [in]

Specifies how the object is to be represented. Representations include content, an icon, a thumbnail, or a printed document. Valid values are taken from the enumeration [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect). See the **DVASPECT** enumeration for more information.

### `lindex` [in]

Portion of the object that is of interest for the draw operation. Its interpretation varies with *dwDrawAspect*. See the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) enumeration for more information.

### `pvAspect` [in]

Pointer to additional information about the view of the object specified in *dwDrawAspect*. Since none of the current aspects support additional information, *pvAspect* must always be **NULL**.

### `ptd` [in]

Pointer to the [DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice) structure that describes the device for which the object is to be rendered. If **NULL**, the view should be rendered for the default target device (typically the display). A value other than **NULL** is interpreted in conjunction with *hicTargetDev* and *hdcDraw*. For example, if *hdcDraw* specifies a printer as the device context, ptd points to a structure describing that printer device. The data may actually be printed if *hicTargetDev* is a valid value or it may be displayed in print preview mode if *hicTargetDev* is **NULL**.

### `hicTargetDev` [in]

Information context for the target device indicated by the *ptd* parameter from which the object can extract device metrics and test the device's capabilities. If *ptd* is **NULL**, the object should ignore the *hicTargetDev* parameter.

### `ppColorSet` [out]

Address of LOGPALETTE pointer variable that receives a pointer to the LOGPALETTE structure. The LOGPALETTE structure contains the set of colors that would be used if [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) were called with the same parameters for *dwAspect*, *lindex*, *pvAspect*, *ptd*, and *hicTargetDev*. If *ppColorSet* is **NULL**, the object does not use a palette.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Set of colors is empty or the object will not give out the information. |
| **OLE_E_BLANK** | No presentation data for object. |
| **DV_E_LINDEX** | Invalid value for *lindex*; currently only -1 is supported. |
| **DV_E_DVASPECT** | Invalid value for *dwAspect*. |
| **E_INVALIDARG** | One or more of the supplied parameter values is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory available for this operation. |

## Remarks

The **IViewObject::GetColorSet** method recursively queries any nested objects and returns a color set that represents the union of all colors requested. The color set eventually percolates to the top-level container that owns the window frame. This container can call **IViewObject::GetColorSet** on each of its embedded objects to obtain all the colors needed to draw the embedded objects. The container can use the color sets obtained in conjunction with other colors it needs for itself to set the overall color palette.

The OLE-provided implementation of **IViewObject::GetColorSet** looks at the data it has on hand to draw the picture. If CF_DIB is the drawing format, the palette found in the bitmap is used. For a regular bitmap, no color information is returned. If the drawing format is a metafile, the object handler enumerates the metafile looking for a CreatePalette metafile record. If one is found, the handler uses it as the color set.

## See also

[DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)

[IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject)