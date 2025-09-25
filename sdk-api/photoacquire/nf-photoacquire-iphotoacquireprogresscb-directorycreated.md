# IPhotoAcquireProgressCB::DirectoryCreated

## Description

The `DirectoryCreated` method provides extended functionality when a destination directory is created during the acquisition process. The application provides the implementation of the `DirectoryCreated` method.

## Parameters

### `pszDirectory` [in]

Pointer to a null-terminated string containing the directory.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not yet implemented. |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)