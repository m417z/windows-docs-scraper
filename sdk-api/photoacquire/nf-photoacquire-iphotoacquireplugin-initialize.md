# IPhotoAcquirePlugin::Initialize

## Description

The `Initialize` method provides extended functionality when the plug-in is initialized. The application provides the implementation of the `Initialize` method.

## Parameters

### `pPhotoAcquireSource` [in]

Specifies the source from which photos are being acquired.

### `pPhotoAcquireProgressCB` [in]

Specifies the callback that will provide additional processing during acquisition.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not implemented |

## See also

[IPhotoAcquirePlugin Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireplugin)

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)

[IPhotoAcquireSource Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource)