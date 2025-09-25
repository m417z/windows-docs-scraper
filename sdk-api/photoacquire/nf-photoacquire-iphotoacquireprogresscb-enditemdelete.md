# IPhotoAcquireProgressCB::EndItemDelete

## Description

The `EndItemDelete` method provides extended functionality each time a file is deleted from the image source. The application provides the implementation of the `EndItemDelete` method.

## Parameters

### `nItemIndex` [in]

Integer value containing the item index.

### `pPhotoAcquireItem` [in]

Pointer to the deleted [IPhotoAcquireItem](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem) object.

### `hr` [in]

Specifies the result of the delete operation.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | This method is not yet implemented |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)