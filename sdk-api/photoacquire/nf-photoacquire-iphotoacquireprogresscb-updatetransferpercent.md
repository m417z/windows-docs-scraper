# IPhotoAcquireProgressCB::UpdateTransferPercent

## Description

The `UpdateTransferPercent` method provides extended functionality when the percentage of items transferred changes. The application provides the implementation of the `UpdateTransferPercent` method.

## Parameters

### `fOverall` [in]

Flag that, when set to **TRUE**, indicates that the value contained in *nPercent* is a percentage of the overall transfer progress, rather than a percentage of an individual item's progress.

### `nPercent` [in]

Integer value containing the percentage of items transferred.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not implemented. |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)