# IPhotoAcquireProgressCB::EndItemTransfer

## Description

The `EndItemTransfer` method provides extended functionality each time a file is transferred from the image source. The application provides the implementation of the `EndItemTransfer` method.

## Parameters

### `nItemIndex` [in]

Integer value containing the item index.

### `pPhotoAcquireItem` [in]

Pointer to a photo acquire item object.

### `hr` [in]

Specifies the result of the transfer operation.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not yet implemented |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)