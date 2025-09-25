# IPhotoAcquireSettings::SetAcquisitionTime

## Description

The `SetAcquisitionTime` method sets the acquisition time explicitly.

## Parameters

### `pftAcquisitionTime` [in]

Specifies the acquisition time.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is typically used to force two sessions to show the same acquisition time. If not explicitly set, acquisition time defaults to the current machine time.

## See also

[GetAcquisitionTime](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-getacquisitiontime)

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)