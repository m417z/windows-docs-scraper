# ILayoutStorage::LayoutScript

## Description

The **LayoutScript** method provides explicit directions for reordering the storages, streams, and controls in a compound file to match the order in which they are accessed during the download.

## Parameters

### `pStorageLayout` [in]

Pointer to an array of
[StorageLayout](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-storagelayout) structures.

### `nEntries` [in]

Number of entries in the array of
[StorageLayout](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-storagelayout) structures.

### `glfInterleavedFlag` [in]

Reserved for future use.

## Return value

This function supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL, as well as the following:

| Return code | Description |
|----------------|---------------|
|STG_E_INVALIDPOINTER | The storage layout pointer is invalid.|
|STG_E_INVALIDFLAG | The value of *glfInterleavedFlag* is invalid.|
|STG_E_PATHNOTFOUND | The new document file name specified is invalid.|
|STG_E_INSUFFICIENTMEMORY | There is not enough memory to complete the operation.|
|STG_E_INVALIDPARAMETER | One of the parameters is invalid.|
| STG_E_INUSE | The **BeginMonitor** method was called while **ILayoutStorage** was already monitoring.|

## Remarks

To provide explicit layout instructions, the application calls **ILayoutStorage::LayoutScript**, passing an array of
[StorageLayout](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-storagelayout) structures. Each structure defines a single storage or stream data block and specifies where the block is to be written in the
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) byte array.

An application can combine scripted layout with monitoring, as the structure of a particular compound file may dictate.

When the optimal data-layout pattern of an entire compound file has been determined, the application calls
[ILayoutStorage::ReLayoutDocfile](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-relayoutdocfile) to restructure the compound file to match the order in which its data sectors were accessed.

## See also

[ILayoutStorage::ReLayoutDocfile](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-relayoutdocfile)

[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes)

[StorageLayout](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-storagelayout)