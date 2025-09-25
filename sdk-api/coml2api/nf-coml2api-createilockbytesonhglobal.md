# CreateILockBytesOnHGlobal function

## Description

The **CreateILockBytesOnHGlobal** function creates a byte array object that uses an HGLOBAL memory handle to store the bytes intended for in-memory storage of a compound file. This object is the OLE-provided implementation of the [ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface.

The returned byte array object supports both reading and writing, but does not support region locking . The object calls the [GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) function to grow the memory block as required.

## Parameters

### `hGlobal` [in]

A memory handle allocated by the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function, or if **NULL** a new handle is to be allocated instead. The handle must be allocated as moveable and nondiscardable.

### `fDeleteOnRelease` [in]

A flag that specifies whether the underlying handle for this byte array object should be automatically freed when the object is released. If set to **FALSE**, the caller must free the *hGlobal* after the final release. If set to **TRUE**, the final release will automatically free the *hGlobal* parameter.

### `pplkbyt` [out]

The address of
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) pointer variable that receives the interface pointer to the new byte array object.

## Return value

This function supports the standard return values **E_INVALIDARG** and **E_OUTOFMEMORY**, as well as the following:

## Remarks

If *hGlobal* is **NULL**, the **CreateILockBytesOnHGlobal** allocates a new memory handle and the byte array is empty initially.

If *hGlobal* is not **NULL**, the initial contents of the byte array object are the current contents of the memory block. Thus, this function can be used to open an existing byte array in memory, for example to reload a storage object previously created by the [StgCreateDocfileOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfileonilockbytes) function. The memory handle and its contents are undisturbed by the creation of the new byte array object.

The initial size of the byte array is the size of *hGlobal* as returned by the [GlobalSize](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalsize) function. This is not necessarily the same size that was originally allocated for the handle because of rounding. If the logical size of the byte array is important, follow the call to **CreateILockBytesOnHGlobal** with a call to [ILockBytes::SetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-setsize).

After creating the byte array object with [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal), [StgCreateDocfileOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfileonilockbytes) can be used to create a new storage object in memory, or [StgOpenStorageOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageonilockbytes) can be used to reopen a previously existing storage object that is already contained in the memory block. [GetHGlobalFromILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-gethglobalfromilockbytes) can be called to retrieve the memory handle associated with the byte array object.

If a memory handle is passed to **CreateILockBytesOnHGlobal** or if [GetHGlobalFromILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-gethglobalfromilockbytes) is called, the memory handle of this function can be directly accessed by the caller while it is still in use by the byte array object. Appropriate caution should be exercised in the use of this capability and its implications:

* Do not free the *hGlobal* memory handle during the lifetime of the byte array object. [ILockBytes::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) must be called before the memory handle is freed.
* Do not call [GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) to change the size of the memory handle during the lifetime of the byte array object. This may cause application crashes or memory corruption. Avoid creating multiple byte array objects on the same memory handle, because [ILockBytes::WriteAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-writeat) and [ILockBytes::SetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-setsize) methods may internally call **GlobalReAlloc**.
* If possible, avoid accessing the memory block during the lifetime of the byte array object, because the object may internally call [GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) and do not make assumptions about its size and location. If the memory block must be accessed, the memory access calls should be surrounded by calls to [GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock) and [GlobalUnLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalunlock).
* Avoid calling the object’s methods while the memory handle is locked with [GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock). This can cause method calls to fail unpredictably.

If the caller sets the *fDeleteOnRelease* parameter to **FALSE**, then the caller must also free the *hGlobal* after the final release. If the caller sets the *fDeleteOnRelease* parameter to **TRUE**, the final release will automatically free the *hGlobal*. The memory handle passed as the hGlobal parameter must be allocated as movable and nondiscardable, as shown in the following example:

```cpp
HGLOBAL	hMem = ::GlobalAlloc(GMEM_MOVEABLE,iSize);
if (!hMem)
    AfxThrowMemoryException();

LPVOID pCompoundFile = ::GlobalLock(hMem);
... // Fill memory
::GlobalUnlock(hMem);

CComPtr<ILockBytes> spLockBytes;
HRESULT hr = ::CreateILockBytesOnHGlobal(hMem,FALSE,&spLockBytes);

```

**CreateILockBytesOnHGlobal** will accept memory allocated with [GMEM_FIXED](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc), but this usage is not recommended. HGLOBALs allocated with **GMEM_FIXED** are not really handles and their value can change when they are reallocated. If the memory handle was allocated with **GMEM_FIXED** and *fDeleteOnRelease* is **FALSE**, then the caller must call [GetHGlobalFromILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-gethglobalfromilockbytes) to get the correct HGLOBAL value in order to free the handle.

This implementation of [ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) does not support region locking. Applications that use this implementation with the [StgCreateDocfileOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfileonilockbytes) or [StgOpenStorageOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageonilockbytes) functions should avoid opening multiple concurrent instances on the same **ILockBytes** object.

Prior to Windows 7 and Windows Server 2008 R2, this implementation did not zero memory when calling [GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) to grow the memory block. Increasing the size of the byte array with [ILockBytes::SetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-setsize) or by writing to a location past the current end of the byte array will leave any unwritten portions of the newly allocated memory uninitialized. The storage objects returned by the [StgCreateDocfileOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfileonilockbytes) and [StgOpenStorageOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageonilockbytes) may increase the size of the byte array without initializing all of the newly allocated space.

Compound files in memory are typically used as scratch space or with APIs that require a storage object, and in these cases the uninitialized memory is generally not a concern. However, if the contents of the memory block will be written to a file, consider the following alternatives to avoid potential information disclosure:

* Copy the logical contents of the in-memory compound file to the destination file using the [IStorage::CopyTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-copyto) method rather than directly writing the contents of the memory block.
* Instead of a compound file in memory, create a temporary file by calling [StgCreateStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatestorageex) with a **NULL** value for the *pwcsName* parameter. When it is time to write to the destination file, use the [IRootStorage::SwitchToFile](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irootstorage-switchtofile) method.
* Implement the [ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface such that memory reallocations are zeroed (see for example the **HEAP_ZERO_MEMORY** flag in [HeapReAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaprealloc)). The memory contents of this byte array can then be written to a file.

## See also

[GetHGlobalFromILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-gethglobalfromilockbytes)

[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes)

[StgOpenStorageOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageonilockbytes)