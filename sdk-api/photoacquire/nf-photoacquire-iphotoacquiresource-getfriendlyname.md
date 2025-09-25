# IPhotoAcquireSource::GetFriendlyName

## Description

The `GetFriendlyName` method retrieves the name of the device, formatted for display.

## Parameters

### `pbstrFriendlyName` [out]

Pointer to a string containing the friendly name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A null value was passed where non-null is expected. |

## See also

[IPhotoAcquireSource Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource)