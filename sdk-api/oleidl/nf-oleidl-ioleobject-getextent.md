# IOleObject::GetExtent

## Description

Retrieves a running object's current display size.

## Parameters

### `dwDrawAspect` [in]

The aspect of the object whose limit is to be retrieved; the value is obtained from the enumerations [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) and from [DVASPECT2](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-dvaspect2). Note that newer objects and containers that support optimized drawing interfaces support the **DVASPECT2** enumeration values. Older objects and containers that do not support optimized drawing interfaces may not support **DVASPECT2**. The most common value for this method is DVASPECT_CONTENT, which specifies a full rendering of the object within its container.

### `psizel` [out]

Pointer to where the object's size is to be returned.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The supplied *dwDrawAspect* value is invalid. |

## Remarks

A container calls **IOleObject::GetExtent** on a running object to retrieve its current display size. If the container can accommodate that size, it will normally do so because the object, after all, knows what size it should be better than the container does. A container normally makes this call as part of initializing an object.

The display size returned by **IOleObject::GetExtent** may differ from the size last set by [IOleObject::SetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setextent) because the latter method dictates the object's display space at the time the method is called but does not necessarily change the object's native size, as determined by its application.

If one of the new aspects is requested in *dwAspect*, this method can either fail or return the same rectangle as for the DVASPECT_CONTENT aspect.

**Note** This method must return the same size as DVASPECT_CONTENT for all the new aspects in [DVASPECT2](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-dvaspect2). [IViewObject2::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject2-getextent) must do the same thing.

### Notes to Callers

Because a container can make this call only to a running object, the container must instead call [IViewObject2::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject2-getextent) if it wants to get the display size of a loaded object from its cache.

### Notes to Implementers

Implementation consists of filling the sizel structure with an object's height and width.

## See also

[DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)

[DVASPECT2](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-dvaspect2)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent)

[IOleObject::SetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setextent)