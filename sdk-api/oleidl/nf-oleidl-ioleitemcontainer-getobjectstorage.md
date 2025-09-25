# IOleItemContainer::GetObjectStorage

## Description

Retrieves a pointer to the storage for the specified object.

## Parameters

### `pszItem` [in]

The compound document's name for the object whose storage is requested.

### `pbc` [in]

A pointer to the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on the bind context to be used in this binding operation. The bind context caches objects bound during the binding process, contains parameters that apply to all operations using the bind context, and provides the means by which the binding implementation should retrieve information about its environment.

### `riid` [in]

A reference to the identifier of the interface to be used to communicate with the object, usually [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage).

### `ppvStorage` [out]

Address of a pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppvStorage* contains the requested interface pointer to the storage for the object named by *pszItem*. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on **ppvStorage*; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, **ppvStorage* is set to **NULL**.

## Return value

This method can return the standard return value E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completely successfully. |
| **MK_E_OBJECT** | The parameter *pszItem* does not identify a object in this container. |
| **MK_E_NOSTORAGE** | The object does not have its own independent storage. |
| **E_NOINTERFACE** | The requested interface is not available. |

## Remarks

The item moniker implementation of [IMoniker::BindToStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtostorage) calls this method.

### Notes to Implementers

If *pszItem* designates a pseudo-object, your implementation of **IOleItemContainer::GetObjectStorage** should return MK_E_NOSTORAGE, because pseudo-objects do not have their own independent storage. If *pszItem* designates an embedded object, or a portion of the document that has its own storage, your implementation should return the specified interface pointer on the appropriate storage object.

## See also

[IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer)