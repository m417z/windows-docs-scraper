# QACONTROL structure

## Description

Specifies control information for [IQuickActivate::QuickActivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iquickactivate-quickactivate).

## Members

### `cbSize`

The size of the structure, in bytes.

### `dwMiscStatus`

The control's miscellaneous status bits that can also be returned by [IOleObject::GetMiscStatus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmiscstatus). See [OLEMISC](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olemisc) for more information.

### `dwViewStatus`

The control's view status that can also be returned by [IViewObjectEx::GetViewStatus](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-getviewstatus). See [VIEWSTATUS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-viewstatus) for more information.

### `dwEventCookie`

A unique identifier for control-defined events.

### `dwPropNotifyCookie`

A unique identifier for control-defined properties.

### `dwPointerActivationPolicy`

The control's activation policy that can also be returned by [IPointerInactive::GetActivationPolicy](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy). If all the bits of **dwPointerActivationPolicy** are set, then the IPointerInactive interface may not be supported. The container should [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to obtain the interface pointer in the standard manner.

## See also

[IQuickActivate::QuickActivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iquickactivate-quickactivate)