# IMFSensorGroup::GetFlags

## Description

Gets the flags set for the sensor group.

## Parameters

### `pFlags` [out]

The flags set for the sensor group

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## Remarks

Currently, no flags are defined for Sensor Groups.

## See also

[IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup)