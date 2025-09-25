# IOleObject::SetExtent

## Description

Informs an object of how much display space its container has assigned it.

## Parameters

### `dwDrawAspect` [in]

DWORD that describes which form, or "aspect," of an object is to be displayed. The object's container obtains this value from the enumeration [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) (refer to the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) enumeration). The most common aspect is DVASPECT_CONTENT, which specifies a full rendering of the object within its container. An object can also be rendered as an icon, a thumbnail version for display in a browsing tool, or a print version, which displays the object as it would be rendered using the **File Print** command.

### `psizel` [in]

Pointer to the size limit for the object.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **OLE_E_NOTRUNNING** | The object is not running. |

## Remarks

A container calls **IOleObject::SetExtent** when it needs to dictate to an embedded object the size at which it will be displayed. Often, this call occurs in response to an end user resizing the object window. Upon receiving the call, the object, if possible, should recompose itself gracefully to fit the new window.

Whenever possible, a container seeks to display an object at its finest resolution, sometimes called the object's native size. All objects, however, have a default display size specified by their applications, and in the absence of other constraints, this is the size they will use to display themselves. Since an object knows its optimum display size better than does its container, the latter normally requests that size from a running object by calling **IOleObject::SetExtent**. Only in cases where the container cannot accommodate the value returned by the object does it override the object's preference by calling **IOleObject::SetExtent**.

### Notes to Callers

You can call **IOleObject::SetExtent** on an object only when the object is running. If a container resizes an object while an object is not running, the container should keep track of the object's new size but defer calling **IOleObject::SetExtent** until a user activates the object. If the OLEMISC_RECOMPOSEONRESIZE bit is set on an object, its container should force the object to run before calling **IOleObject::SetExtent**.

As noted above, a container may want to delegate responsibility for setting the size of an object's display site to the object itself, by calling **IOleObject::SetExtent**.

### Notes to Implementers

You may want to implement this method so that your object rescales itself to match as closely as possible the maximum space available to it in its container.

If an object's size is fixed, that is, if it cannot be set by its container, **IOleObject::SetExtent** should return E_FAIL. This is always the case with linked objects, whose sizes are set by their link sources, not by their containers.

## See also

[IAdviseSink::OnViewChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onviewchange)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent)

[IViewObject2::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject2-getextent)