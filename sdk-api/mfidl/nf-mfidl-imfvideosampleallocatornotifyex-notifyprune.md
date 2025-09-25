# IMFVideoSampleAllocatorNotifyEx::NotifyPrune

## Description

Called when allocator samples are released for pruning by the allocator, or when the allocator is removed.

## Parameters

### `__MIDL__IMFVideoSampleAllocatorNotifyEx0000`

The sample to be pruned.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)

[IMFVideoSampleAllocatorNotifyEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocatornotifyex)