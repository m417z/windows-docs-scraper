# IAdviseSink::OnDataChange

## Description

Called by the server to notify a data object's currently registered advise sinks that data in the object has changed.

## Parameters

### `pFormatetc` [in]

A pointer to a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure, which describes the format, target device, rendering, and storage information of the calling data object.

### `pStgmed` [in]

A pointer to a [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure, which defines the storage medium (global memory, disk file, storage object, stream object, GDI object, or undefined) and ownership of that medium for the calling data object.

## Remarks

Object handlers and containers of link objects implement **IAdviseSink::OnDataChange** to take appropriate steps when notified that data in the object has changed. They also must call [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) to set up advisory connections with the objects in whose data they are interested.

Containers that take advantage of OLE's caching support do not need to register for data-change notifications, because the information necessary to update the container's presentation of the object, including any changes in its data, are maintained in the object's cache.

### Notes to Implementers

If you implement **IAdviseSink::OnDataChange** for a container, remember that this method is asynchronous and that making synchronous calls within asynchronous methods is not valid. Therefore, you cannot call [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) to obtain the data you need to update your object. Instead, you either post an internal message, or invalidate the rectangle for the changed data by calling [InvalidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidaterect) and waiting for a [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message, at which point you are free to get the data and update the object.

The data itself, which is valid only for the duration of the call, is passed using the storage medium pointed to by *pStgmed*. Since the caller owns the medium, the advise sink should not free it. Also, if *pStgmed* points to an [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) or [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface, the sink must not increment the reference count.

## See also

[IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink)