# IPhotoAcquire::CreatePhotoSource

## Description

The `CreatePhotoSource` method initializes an [IPhotoAcquireSource](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource) object to pass to [IPhotoAcquire::Acquire](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-acquire).

## Parameters

### `pszDevice` [in]

Pointer to a null-terminated string containing the device name.

### `ppPhotoAcquireSource` [out]

Returns the initialized photo source to acquire photos from.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A non-**NULL** pointer was expected. |

## Remarks

The [IPhotoAcquireSource](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource) object created is used as the parameter for the [Acquire](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-acquire) method.

If an error occurs in `CreatePhotoSource`, *ppPhotoAcquireSource* is initialized to **NULL**.

## See also

[IPhotoAcquire Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquire)

[IPhotoAcquire::Acquire](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-acquire)