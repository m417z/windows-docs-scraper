# IQuickActivate::QuickActivate

## Description

Quick activates a control.

## Parameters

### `pQaContainer` [in]

A pointer to the [QACONTAINER](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-qacontainer) structure containing information about the container.

### `pQaControl` [in, out]

A pointer to the [QACONTROL](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-qacontrol) structure filled in by the control to return information about the control to the container. The container calling this method must reserve memory for this structure.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

If the control does not support [IQuickActivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iquickactivate), the container performs certain handshaking operations when it loads the control. The container calls certain interfaces on the control and the control, in turn, calls back to certain interfaces on the container's client site. First, the container creates the control object and calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to query for interfaces that it needs. Then, the container calls [IOleObject::SetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setclientsite) on the control, passing a pointer to its client site. Next, the control calls **QueryInterface** on this site, retrieving a pointer to additional necessary interfaces.

Using the **QuickActivate** method, the container passes a pointer to a [QACONTAINER](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-qacontainer) structure. The structure contains pointers to interfaces which are needed by the control and the values of some ambient properties that the control may need. Upon return, the control passes a pointer to a [QACONTROL](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-qacontrol) structure that contains pointers to its own interfaces that the container requires, and additional status information.

The **IPersist*::Load** and **IPersist*::InitNew** methods should be called after quick activation occurs. The control should establish its connections to the container's sinks during quick activation. However, these connections are not live until **IPersist*::Load** or **IPersist*::InitNew** has been called.

## See also

[IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile)

[IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage)

[IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream)

[IPersistStreamInit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit)

[IQuickActivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iquickactivate)