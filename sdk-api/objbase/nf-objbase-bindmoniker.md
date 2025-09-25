# BindMoniker function

## Description

Locates an object by means of its moniker, activates the object if it is inactive, and retrieves a pointer to the specified interface on that object.

## Parameters

### `pmk` [in]

A pointer to the object's moniker. See [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker).

### `grfOpt` [in]

This parameter is reserved for future use and must be 0.

### `iidResult` [in]

The interface identifier to be used to communicate with the object.

### `ppvResult` [out]

The address of pointer variable that receives the interface pointer requested in *iidResult*. Upon successful return, **ppvResult* contains the requested interface pointer. If an error occurs, **ppvResult* is **NULL**. If the call is successful, the caller is responsible for releasing the pointer with a call to the object's [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This function can return the following error codes, or any of the error values returned by the [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) method.

| Return code | Description |
| --- | --- |
| **S_OK** | The object was located and activated, if necessary, and a pointer to the requested interface was returned. |
| **MK_E_NOOBJECT** | The object that the moniker object identified could not be found. |

## Remarks

**BindMoniker** is a helper function supplied as a convenient way for a client that has the moniker of an object to obtain a pointer to one of that object's interfaces. **BindMoniker** packages the following calls:

``` syntax
CreateBindCtx(0, &pbc);
pmk->BindToObject(pbc, NULL, riid, ppvObj);
```

[CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx) creates a bind context object that supports the system implementation of IBindContext. The pmk parameter is actually a pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) implementation on a moniker object. This implementation's [BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) method supplies the pointer to the requested interface pointer.

If you have several monikers to bind in quick succession and if you know that those monikers will activate the same object, it may be more efficient to call the [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) method directly, which enables you to use the same bind context object for all the monikers. See the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface for more information.

Container applications that allow their documents to contain linked objects are a special client that generally does not make direct calls to [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) methods. Instead, the client manipulates the linked objects through the [IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink) interface. The default handler implements this interface and calls the appropriate **IMoniker** methods as needed.

## See also

[CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx)

[IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject)