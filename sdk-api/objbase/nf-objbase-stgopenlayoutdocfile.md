# StgOpenLayoutDocfile function

## Description

Not supported.

The **StgOpenLayoutDocfile** function opens a compound file on an
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) implementation that is capable of monitoring sector data. To call **StgOpenLayoutDocfile**, both DfLayout.dll and DfLayout.lib are required.

**Note** Do not use this function. Use the [IStorage::CopyTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-copyto)
method instead. **CopyTo** can be used to layout a docfile, thus improving performance in most scenarios.

## Parameters

### `pwcsDfName` [in]

A pointer to the null-terminated Unicode string name of the compound file to be opened.

### `grfMode` [in]

Access mode to use when opening the newly created storage object. Values are taken from the
[STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants). Be aware that priority mode and exclusions are not supported. The most common access mode is likely to be STGM_DIRECT | STGM_READ | STGM_SHARE_EXCLUSIVE.

### `reserved` [in]

Reserved for future use.

### `ppstgOpen` [out]

A pointer to
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer variable that receives the interface pointer to the root object of the newly created root storage object.

## Return value

This function supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL, in addition to the following:

The **StgOpenLayoutDocfile** function can also return any of the error values returned by the
[StgOpenStorageOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageonilockbytes) function.

## Remarks

The compound file implementation created by this function exposes the
[ILayoutStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilayoutstorage) interface on its root storage. Applications use this interface to express the optimal layout of their compound files in order to download and render data more rapidly over a slow link.
**StgOpenLayoutDocfile** returns a pointer to the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the root storage of the newly created compound file. Using this pointer, applications call **QueryInterface** to obtain a pointer to
**ILayoutStorage**.

## See also

[CopyTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-copyto)

[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes)

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)

[STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants)