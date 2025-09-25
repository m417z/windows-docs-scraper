# IPhotoAcquireProgressCB::EndDelete

## Description

The `EndDelete` method provides extended functionality when deletion of files from the image source is complete. The application provides the implementation of the `EndDelete` method.

## Parameters

### `hr` [in]

Specifies the result of the delete operation.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not yet implemented |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)