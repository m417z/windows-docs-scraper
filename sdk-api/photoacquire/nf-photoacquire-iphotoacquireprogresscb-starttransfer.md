# IPhotoAcquireProgressCB::StartTransfer

## Description

The `StartTransfer` method provides additional processing when transfer of items from the device begins. The application provides the implementation of the `StartTransfer` method.

## Parameters

### `pPhotoAcquireSource` [in]

Pointer to the IPhotoAcquireSource from which items are being retrieved.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any Failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

Returning an error HRESULT other than E_NOTIMPL will cause acquisition to be aborted.

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)