# IPhotoAcquirePlugin::TransferComplete

## Description

Provides extended functionality when a transfer session is completed. The application provides the implementation of the **TransferComplete** method.

## Parameters

### `hr` [in]

Specifies the result of the transfer operation.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not implemented |

## See also

[IPhotoAcquirePlugin Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireplugin)