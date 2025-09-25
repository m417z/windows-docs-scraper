# IPhotoAcquireSource::GetPhotoAcquireSettings

## Description

The `GetPhotoAcquireSettings` method obtains an [IPhotoAcquireSettings](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings) object for working with acquisition settings.

## Parameters

### `ppPhotoAcquireSettings` [out]

Pointer to the address of a photo acquire settings object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Null value passed where non-null is expected. |

## See also

[IPhotoAcquireSource Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource)