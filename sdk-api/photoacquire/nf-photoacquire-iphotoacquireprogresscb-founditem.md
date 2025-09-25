# IPhotoAcquireProgressCB::FoundItem

## Description

The `FoundItem` method provides extended functionality each time an item is found during enumeration of items from the device. This method can be used to exclude an item from the list of items to acquire. The application provides the implementation of the `FoundItem` method.

## Parameters

### `pPhotoAcquireItem` [in]

Pointer to the found [IPhotoAcquireItem](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem) object.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | Exclude this item from the list of files to acquire. |

## Remarks

Return S_FALSE to exclude the item from the results of the enumeration. This would allow the caller to exclude videos or camera raw files, for instance.

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)