# CreateStreamOnHGlobal function

## Description

The **CreateStreamOnHGlobal** function creates a stream object that uses an HGLOBAL memory handle to store the stream contents. This object is the OLE-provided implementation of the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface.

The returned stream object supports both reading and writing, is not transacted, and does not support region locking. The object calls the [GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) function to grow the memory block as required.

**Tip** Consider using the [SHCreateMemStream](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatememstream) function, which produces better performance, or for Windows Store apps, consider using [InMemoryRandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.inmemoryrandomaccessstream).

## Parameters

### `hGlobal` [in]

A memory handle allocated by the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function, or if **NULL** a new handle is to be allocated instead. The handle must be allocated as moveable and nondiscardable.

### `fDeleteOnRelease` [in]

A value that indicates whether the underlying handle for this stream object should be automatically freed when the stream object is released. If set to **FALSE**, the caller must free the *hGlobal* after the final release. If set to **TRUE**, the final release will automatically free the underlying handle. See the Remarks for further discussion of the case where *fDeleteOnRelease* is **FALSE**.

### `ppstm` [out]

The address of
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)* pointer variable that receives the interface pointer to the new stream object. Its value cannot be **NULL**.

## Return value

This function supports the standard return values E_INVALIDARG and E_OUTOFMEMORY, as well as the following.

## Remarks

If *hGlobal* is **NULL**, the function allocates a new memory handle and the stream is initially empty.

If *hGlobal* is not **NULL**, the initial contents of the stream are the current contents of the memory block. Thus, **CreateStreamOnHGlobal** can be used to open an existing stream in memory. The memory handle and its contents are undisturbed by the creation of the new stream object.

The initial size of the stream is the size of *hGlobal* as returned by the [GlobalSize](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalsize) function. Because of rounding, this is not necessarily the same size that was originally allocated for the handle. If the logical size of the stream is important, follow the call to this function with a call to the
[IStream::SetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-setsize) method.

The new stream object’s initial seek position is the beginning of the stream.

After creating the stream object with
**CreateStreamOnHGlobal**, call
[GetHGlobalFromStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-gethglobalfromstream) to retrieve the memory handle associated with the stream object.

If a memory handle is passed to **CreateStreamOnHGlobal** or if [GetHGlobalFromStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-gethglobalfromstream) is called, the memory handle of this function can be directly accessed by the caller while it is still in use by the stream object. Appropriate caution should be exercised in the use of this capability and its implications:

* Do not free the *hGlobal* memory handle during the lifetime of the stream object. [IStream::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) must be called before freeing the memory handle.
* Do not call [GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) to change the size of the memory handle during the lifetime of the stream object or its clones. This may cause application crashes or memory corruption. Avoid creating multiple stream objects separately on the same memory handle, because the [IStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) and [IStream::SetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-setsize) methods may internally call **GlobalReAlloc**. The [IStream::Clone](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-clone) method can be used to create a new stream object based on the same memory handle that will properly coordinate its access with the original stream object.
* If possible, avoid accessing the memory block during the lifetime of the stream object, because the object may internally call [GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) and do not make assumptions about its size and location. If the memory block must be accessed, the memory access calls should be surrounded by calls to [GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock) and [GlobalUnLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalunlock).
* Avoid calling the object’s methods while you have the memory handle locked with [GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock). This can cause method calls to fail unpredictably.

If the *fDeleteOnRelease* parameter is **FALSE**, the caller is responsible for freeing the underlying memory handle, even if the *hGlobal* parameter is **NULL**. Use the **GetHGlobalFromStream** function to obtain the underlying memory handle and **GlobalFree** that memory after the last reference to the stream is released. If the caller sets the *fDeleteOnRelease* parameter to **TRUE**, the final release will automatically free the underlying memory handle.

The memory handle passed as the *hGlobal* parameter must be allocated as movable and nondiscardable, as shown in the following example:

```cpp
HGLOBAL	hMem = ::GlobalAlloc(GMEM_MOVEABLE,iSize);
if (!hMem)
    AfxThrowMemoryException();

LPVOID pImage = ::GlobalLock(hMem);
... // Fill memory
::GlobalUnlock(hMem);

CComPtr<IStream> spStream;
HRESULT hr = ::CreateStreamOnHGlobal(hMem,FALSE,&spStream);
```

**CreateStreamOnHGlobal** will accept a memory handle allocated with [GMEM_FIXED](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc), but this usage is not recommended. HGLOBALs allocated with **GMEM_FIXED** are not really handles and their value can change when they are reallocated. If the memory handle was allocated with **GMEM_FIXED** and *fDeleteOnRelease* is **FALSE**, the caller must call [GetHGlobalFromStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-gethglobalfromstream) to get the correct handle in order to free it.

Prior to Windows 7 and Windows Server 2008 R2, this implementation did not zero memory when calling [GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) to grow the memory block. Increasing the size of the stream with [IStream::SetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-setsize) or by writing to a location past the current end of the stream may leave portions of the newly allocated memory uninitialized.

## See also

[GetHGlobalFromStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-gethglobalfromstream)

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)

[IStream::SetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-setsize)

[InMemoryRandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.inmemoryrandomaccessstream)