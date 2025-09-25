# IPhotoAcquireProgressCB::GetDeleteAfterAcquire

## Description

The `GetDeleteAfterAcquire` method returns a value indicating whether photos should be deleted after acquisition.

## Parameters

### `pfDeleteAfterAcquire` [out]

Pointer to a flag that, when set to **TRUE**, indicates that photos should be deleted after acquisition.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not yet implemented |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)