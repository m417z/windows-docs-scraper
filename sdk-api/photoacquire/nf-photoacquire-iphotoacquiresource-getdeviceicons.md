# IPhotoAcquireSource::GetDeviceIcons

## Description

The `GetDeviceIcons` method retrieves the icons that are used to represent the device.

## Parameters

### `nSize` [in]

Integer value containing the size of the icon to retrieve.

### `phLargeIcon` [out]

Specifies the large icon used for the device.

### `phSmallIcon` [out]

Specifies the small icon used for the device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A null pointer was passed where non-null was expected. |

## See also

[GetDeviceId](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresource-getdeviceid)

[IPhotoAcquireSource Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource)