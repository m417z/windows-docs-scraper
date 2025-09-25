# IPhotoAcquireProgressCB::Cancelled

## Description

The `Cancelled` method provides extended functionality when a cancellation occurs during an acquisition session. The application provides the implementation of the `Cancelled` method.

## Parameters

### `pfCancelled` [out]

Pointer to a flag that, when set to **TRUE**, indicates that the operation was canceled.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not implemented. |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)