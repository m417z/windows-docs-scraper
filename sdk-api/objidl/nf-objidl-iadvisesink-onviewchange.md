# IAdviseSink::OnViewChange

## Description

Notifies an object's registered advise sinks that its view has changed.

## Parameters

### `dwAspect` [in]

The aspect, or view, of the object. Contains a value taken from the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) enumeration.

### `lindex` [in]

The portion of the view that has changed. Currently only -1 is valid.

## Remarks

Containers register to be notified when an object's view changes by calling [IViewObject::SetAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-setadvise). After it is registered, the object will call the sink's **IAdviseSink::OnViewChange** method when appropriate. **OnViewChange** can be called when the object is in either the loaded or running state.

Even though [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) values are individual flag bits, *dwAspect* may represent only one value. That is, *dwAspect* cannot contain the result of an OR operation combining two or more **DVASPECT** values.

The *lindex* parameter represents the part of the aspect that is of interest. The value of *lindex* depends on the value of *dwAspect*. If *dwAspect* is either DVASPECT_THUMBNAIL or DVASPECT_ICON, *lindex* is ignored. If *dwAspect* is DVASPECT_CONTENT, *lindex* must be -1, which indicates that the entire view is of interest and is the only value that is currently valid.

## See also

[IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink)

[IViewObject::SetAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-setadvise)