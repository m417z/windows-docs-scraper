# IOleCacheControl::OnRun

## Description

Notifies the cache that the data source object has entered the running state so that the cache object can establish advise sinks as needed.

## Parameters

### `pDataObject` [in]

A pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the object that is entering the running state.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_OUTOFMEMORY** | Insufficient memory is available for this operation. |

## Remarks

When **OnRun** is called, the cache sets up advisory connections as necessary with the source data object so it can receive notifications. The advisory connection created between the running object and the cache is destroyed when [IOleCacheControl::OnStop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecachecontrol-onstop) is called.

Some object handlers or in-process servers might use the cache passively, and not call **OnRun**. These applications must call [IOleCache2::UpdateCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache2-updatecache), [IOleCache::InitCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-initcache), or [IOleCache::SetData](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-setdata) to fill the cache when necessary to ensure that the cache gets updated.

**OnRun** does not add a reference count on the pointer to [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) passed in *pDataObject*. Because it is the responsibility of the caller of [OleRun](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olerun) to ensure that the lifetime of the *pDataObject* pointer lasts until [OnStop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecachecontrol-onstop) is called, the caller must be holding a pointer to **IDataObject** on the data object of interest.

## See also

[IOleCache2::UpdateCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache2-updatecache)

[IOleCacheControl](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecachecontrol)

[IOleCacheControl::OnStop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecachecontrol-onstop)