# ISensorDataReport::GetTimestamp

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves the time at which the data report was created.

## Parameters

### `pTimeStamp` [out]

Address of a [SYSTEMTIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-systemtime) variable that receives the time stamp.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The sensor driver did not return a valid time stamp for the data report. |
| **E_POINTER** | NULL was passed in for pTimeStamp. |

## Remarks

Time stamps use Universal Coordinated Time (UTC).

## See also

[ISensorDataReport](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensordatareport)