# IMFSensorActivityReport::GetProcessCount

## Description

Gets the count of [IMFSensorProcessActivity](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprocessactivity) objects, representing the current activity of a process associated with the sensor, that are available to be retrieved.

## Parameters

### `pcCount` [out]

A pointer in which the process count is stored.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pulCount* parameter is null. |

## See also

[IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport)