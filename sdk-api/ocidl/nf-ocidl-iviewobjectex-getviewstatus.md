# IViewObjectEx::GetViewStatus

## Description

Retrieves information about the opacity of the object, and what drawing aspects are supported.

## Parameters

### `pdwStatus` [out]

A pointer to the view status. This information is returned as a combination of the [VIEWSTATUS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-viewstatus) enumeration values.

## Return value

This method returns S_OK on success.

## Remarks

In order to optimize the drawing process, the container needs to be able to determine whether an object is opaque and whether it has a solid background. It is not necessary to redraw objects that are entirely covered by a completely opaque object. Other operations, such as scrolling for example, can also be highly optimized if an object is opaque and has a solid background.

The **IViewObjectEx::GetViewStatus** method returns whether the object is entirely opaque or not (VIEWSTATUS_OPAQUE bit) and whether its background is solid (VIEWSTATUS_SOLIDBKGND bit). This information may change in time. An object may be opaque at a given time and become totally or partially transparent later on, for example, because of a change of the BackStyle property. An object should notify its sites when it changes using [IAdviseSinkEx::OnViewStatusChange](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iadvisesinkex-onviewstatuschange) so the sites can cache this information for high speed access.

Objects not supporting [IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex) are considered to be always transparent.

The **IViewObjectEx::GetViewStatus** method also returns a combination of bits indicating which aspects are supported.

If a given drawing aspect is not supported, all [IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex) methods taking a drawing aspect as an input parameter should fail and return E_INVALIDARG. The **IViewObjectEx::GetViewStatus** method allows the container to get back information about all drawing aspects in one quick call. Normally the set of supported drawing aspects should not change with time. However, if this was not the case, an object should notify its container using [IAdviseSinkEx::OnViewStatusChange](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iadvisesinkex-onviewstatuschange).

Which drawing aspects are supported is independent of whether the object is opaque, partially transparent, or totally transparent. In particular, a transparent object that does not support DVASPECT_TRANSPARENT should be drawn correctly during the back to front pass using DVASPECT_CONTENT. However, this is likely to result in more flicker.

## See also

[IAdviseSinkEx::OnViewStatusChange](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iadvisesinkex-onviewstatuschange)

[IViewObjectEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex)

[VIEWSTATUS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-viewstatus)