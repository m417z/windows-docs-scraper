# CreateDataCache function

## Description

Retrieves a pointer to a new instance of an OLE-provided implementation of a data cache.

## Parameters

### `pUnkOuter` [in]

 If the cache is to be created as part of an aggregate, pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the aggregate. If not, the parameter should be **NULL**.

### `rclsid` [in]

CLSID used to generate icon labels. This value is typically CLSID_NULL.

### `iid` [in]

Reference to the identifier of the interface the caller wants to use to communicate with the cache. This value is typically IID_IOleCache (defined in the OLE headers to equal the interface identifier for [IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)).

### `ppv` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObj* contains the requested interface pointer to the supplied cache object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The interface represented by riid is not supported by the object. The parameter *ppvObj* is set to **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

The cache object created by **CreateDataCache** supports the [IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache), [IOleCache2](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache2), and [IOleCacheControl](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecachecontrol) interfaces for controlling the cache. It also supports the [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage), [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) (without advise sinks), [IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject), and [IViewObject2](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject2) interfaces.

## See also

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[IOleCache2](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache2)

[IOleCacheControl](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecachecontrol)