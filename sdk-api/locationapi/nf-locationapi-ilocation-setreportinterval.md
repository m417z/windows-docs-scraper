# ILocation::SetReportInterval

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Specifies the requested minimum amount of time, in milliseconds, between report events.

## Parameters

### `reportType` [in]

**REFIID** that specifies the report type for which to set the interval.

### `millisecondsRequested` [in]

**DWORD** that contains the report interval value, in milliseconds. If this value is zero, no minimum interval is specified and your application receives events at the location sensor's default interval.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The caller is not registered to receive events for the specified report type. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | *reportType* was other than **IID_ILatLongReport** or **IID_ICivicAddressReport**. |

## Remarks

The interval you request by using this method represents the shortest amount of time between events. This means that you request to receive event notifications no more frequently than specified, but the elapsed time may be significantly longer. Use this method to help ensure that event notifications do not use more processor resources than necessary.

It is not guaranteed that your request for a particular report interval will be set by the location provider. Call [GetReportInterval](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-getreportinterval)  to discover the true report interval setting.

A report interval of zero means that no minimum interval is specified, and the application may receive events at the frequency that the location sensor sends events.

#### Examples

The following example demonstrates how to call **SetReportInterval**.

```cpp

// Set the latitude/longitude report interval to 1000 milliseconds
HRESULT hr = spLocation->SetReportInterval(IID_ILatLongReport, 1000);
```

## See also

[ILocation](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocation)