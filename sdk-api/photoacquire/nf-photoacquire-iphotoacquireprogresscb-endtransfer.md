# IPhotoAcquireProgressCB::EndTransfer

## Description

The `EndTransfer` method provides extended functionality when the transfer of all files is complete. The application provides the implementation of the `EndTransfer` method.

## Parameters

### `hr` [in]

Specifies the result of the transfer.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not yet implemented |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)