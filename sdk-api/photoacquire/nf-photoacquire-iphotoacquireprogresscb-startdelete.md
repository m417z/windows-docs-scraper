# IPhotoAcquireProgressCB::StartDelete

## Description

The `StartDelete` method provides extended functionality when deletion of items from the device begins.

The implementation of `StartDelete` is provided by the application.

## Parameters

### `pPhotoAcquireSource` [in]

Pointer to the [IPhotoAcquireSource](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource) that items are being deleted from.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not yet implemented |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)