# IPhotoAcquireSettings::GetAcquisitionTime

## Description

The `GetAcquisitionTime` method retrieves the acquisition time of the current session.

## Parameters

### `pftAcquisitionTime` [out]

Specifies acquisition time.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A non-NULL value was expected. |

## Remarks

If not set explicitly, the acquisition time defaults to the current machine time.

## See also

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)

[SetAcquisitionTime](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-setacquisitiontime)