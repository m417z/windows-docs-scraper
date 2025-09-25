# QACONTAINER structure

## Description

Specifies container information for [IQuickActivate::QuickActivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iquickactivate-quickactivate).

## Members

### `cbSize`

The size of the structure, in bytes.

### `pClientSite`

A pointer to an [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite) interface in the container.

### `pAdviseSink`

A pointer to an [IAdviseSinkEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iadvisesinkex) interface in the container.

### `pPropertyNotifySink`

A pointer to an [IPropertyNotifySink](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink) interface in the container.

### `pUnkEventSink`

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the container's sink object.

### `dwAmbientFlags`

The number of ambient properties supplied by the container using values from the [QACONTAINERFLAGS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-qacontainerflags) enumeration.

### `colorFore`

Specifies ForeColor, an ambient property supplied by the container with a DISPID = -704.

### `colorBack`

Specifies BackColor, an ambient property supplied by the container with a DISPID = -701.

### `pFont`

Specifies Font, an ambient property supplied by the container with a DISPID = -703.

### `pUndoMgr`

A pointer to an [IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager) interface in the container.

### `dwAppearance`

Specifies Appearance, an ambient property supplied by the container with a DISPID = -716.

### `lcid`

Specifies LocaleIdentifier, an ambient property supplied by the container with a DISPID = -705.

### `hpal`

Specifies Palette, an ambient property supplied by the container with a DISPID = -726.

### `pBindHost`

A pointer to an [IBindHost](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775076(v=vs.85)) interface in the container.

### `pOleControlSite`

A pointer to the [IOleControlSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrolsite) interface in the container's site object.

### `pServiceProvider`

A pointer to the [IServiceProvider](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678965(v=vs.85)) interface in the container.

## Remarks

If an interface pointer in the **QACONTAINER** structure is **NULL** it does not indicate that the interface is not supported. In this situation, the control should use [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to obtain the interface pointer in the standard manner.

## See also

[IQuickActivate::QuickActivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iquickactivate-quickactivate)

[QACONTAINERFLAGS](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-qacontainerflags)