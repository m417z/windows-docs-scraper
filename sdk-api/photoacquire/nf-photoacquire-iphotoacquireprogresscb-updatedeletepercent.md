# IPhotoAcquireProgressCB::UpdateDeletePercent

## Description

The `UpdateDeletePercent` method provides extended functionality when the percentage of items deleted changes. The application provides the implementation of the `UpdateDeletePercent` method.

## Parameters

### `nPercent` [in]

Integer value containing the percentage of items deleted.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not implemented |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)