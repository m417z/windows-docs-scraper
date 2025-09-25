# IPhotoAcquireProgressCB::StartItemDelete

## Description

The `StartItemDelete` method provides extended functionality each time the deletion of an individual item from the device begins. The application provides the implementation of the `StartItemDelete` method.

## Parameters

### `nItemIndex` [in]

Integer value containing the item index in the list of items to delete.

### `pPhotoAcquireItem` [in]

Pointer to the [IPhotoAcquireItem](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem) object that is being deleted.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not implemented. |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)