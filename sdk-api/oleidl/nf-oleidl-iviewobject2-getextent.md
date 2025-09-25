# IViewObject2::GetExtent

## Description

Retrieves the size that the specified view object will be drawn on the specified target device.

## Parameters

### `dwDrawAspect` [in]

Requested view of the object whose size is of interest. Possible values are taken from the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) and [DVASPECT2](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-dvaspect2) enumerations. Note that newer objects and containers that support optimized drawing interfaces support the **DVASPECT2** enumeration values. Older objects and containers that do not support optimized drawing interfaces may not support **DVASPECT2**.

### `lindex` [in]

The portion of the object that is of interest. Currently, the only possible value is -1.

### `ptd` [in]

A pointer to the [DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice) structure defining the target device for which the object's size should be returned.

### `lpsizel` [out]

A pointer to where the object's size is returned.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_BLANK** | An appropriate cache is not available. |

## Remarks

The OLE-provided implementation of **IViewObject2::GetExtent** searches the cache for the size of the view object.

The [IOleObject::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent) method in the [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) interface provides some of the same information as **IViewObject2::GetExtent**.

This method must return the same size as DVASPECT_CONTENT for all the new aspects in [DVASPECT2](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-dvaspect2). [IOleObject::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent) must do the same thing.

If one of the new aspects is requested in *dwAspect*, this method can either fail or return the same rectangle as for the DVASPECT_CONTENT aspect.

### Notes to Callers

To prevent the object from being run if it isn't already running, you can call **IViewObject2::GetExtent** rather than [IOleObject::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent) to determine the size of the presentation to be drawn.

## See also

[DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)

[DVASPECT2](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-dvaspect2)

[IOleObject::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent)

[IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject)

[IViewObject2](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject2)