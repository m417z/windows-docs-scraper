# IOleItemContainer::GetObject

## Description

Retrieves a pointer to the specified object.

## Parameters

### `pszItem` [in]

The container's name for the requested object.

### `dwSpeedNeeded` [in]

 Indicates approximately how long the caller will wait to get the object. Possible values are taken from the enumeration [BINDSPEED](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-bindspeed).

### `pbc` [in]

A pointer to the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on the bind context object to be used in this binding operation. The bind context caches objects bound during the binding process, contains parameters that apply to all operations using the bind context, and provides the means by which the binding implementation should retrieve information about its environment.

### `riid` [in]

A reference to the identifier of the interface pointer requested.

### `ppvObject` [out]

Address of the pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppvObject* contains the requested interface pointer to the object named by *pszItem*. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the **ppvObject*; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, the implementation sets **ppvObject* to **NULL**.

## Return value

This method can return the standard return value E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **MK_E_EXCEEDEDDEADLINE** | The binding operation could not be completed within the time limit specified by the bind context's [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure, or with the speed indicated by the *dwSpeedNeeded* parameter. |
| **MK_E_NOOBJECT** | The parameter *pszItem* does not identify an object in this container. |
| **E_NOINTERFACE** | The requested interface was not available. |

## Remarks

The item moniker implementation of [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) calls this method, passing the name stored within the item moniker as the *pszItem* parameter.

### Notes to Implementers

Your implementation of **IOleItemContainer::GetObject** should first determine whether *pszItem* is a valid name for one of the container's objects. If not, you should return MK_E_NOOBJECT.

If *pszItem* names an embedded or linked object, your implementation must check the value of the *dwSpeedNeeded* parameter. If the value is BINDSPEED_IMMEDIATE and the object is not yet loaded, you should return MK_E_EXCEEDEDDEADLINE. If the object is loaded, your implementation should determine whether the object is running (for example, by calling the [OleIsRunning](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleisrunning) function). If it is not running and the *dwSpeedNeeded* value is BINDSPEED_MODERATE, your implementation should return MK_E_EXCEEDEDDEADLINE. If the object is not running and *dwSpeedNeeded* is BINDSPEED_INDEFINITE, your implementation should call the [OleRun](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olerun) function to put the object in the running state. Then it can query the object for the requested interface. Note that it is important the object be running before you query for the interface.

If *pszItem* names a pseudo-object, your implementation can ignore the *dwSpeedNeeded* parameter because a pseudo-object is running whenever its container is running. In this case, your implementation can simply query for the requested interface.

If you need more specific information about the time limit than is given by *dwSpeedNeeded*, you can call [IBindCtx::GetBindOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getbindoptions) on the *pbc* parameter to get the actual deadline parameter.

## See also

[IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer)