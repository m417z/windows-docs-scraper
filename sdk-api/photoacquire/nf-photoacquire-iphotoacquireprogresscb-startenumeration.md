# IPhotoAcquireProgressCB::StartEnumeration

## Description

The `StartEnumeration` method provides extended functionality when the enumeration of items to acquire begins.

The application provides the implementation of the `StartEnumeration` method.

## Parameters

### `pPhotoAcquireSource` [in]

Pointer to the [IPhotoAcquireSource](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource) object that items are being enumerated from.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not implemented. |

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)