# SHCreateQueryCancelAutoPlayMoniker function

## Description

[This function is deprecated. Use [CreateClassMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createclassmoniker) instead. Note that the CLSID used in the call to **CreateClassMoniker** must be application-defined. Do not call **CreateClassMoniker** with a system-defined CLSID.]

Deprecated. Creates a **QueryCancelAutoPlay** class moniker, which can then be used to register the [IQueryCancelAutoPlay](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iquerycancelautoplay) handler in the running object table (ROT).

## Parameters

### `ppmoniker` [out]

Type: **[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)****

The address of a [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface pointer that, when this function returns successfully, receives the **QueryCancelAutoPlay** class moniker. If this function call fails, this value is **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If successful, **SHCreateQueryCancelAutoPlayMoniker** calls the interface's [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method and increments the reference count. When you are finished, call the interface's [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to release.

## See also

[CreateClassMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createclassmoniker)