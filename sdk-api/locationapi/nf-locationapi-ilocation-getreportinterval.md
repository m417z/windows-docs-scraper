# ILocation::GetReportInterval

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the requested amount of time, in milliseconds, between report events.

## Parameters

### `reportType` [in]

**REFIID** that specifies the report type for which to get the interval.

### `pMilliseconds` [out]

The address of a **DWORD** that receives the report interval value, in milliseconds. If the report is not registered, this will be set to **NULL**. If this value is set to zero, no minimum interval is specified and your application receives events at the location sensor's default interval.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | *reportType* was other than **IID_ILatLongReport** or **IID_ICivicAddressReport**. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The caller is not registered to receive events for the specified report type. |
| **E_INVALIDARG** | *pMilliseconds* is **NULL**. |

## Remarks

You must call [RegisterForReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-registerforreport) before calling this method.

#### Examples

The following example demonstrates how to call **GetReportInterval**.

```

DWORD reportInterval = 0;
HRESULT hr = spLocation->GetReportInterval(IID_ILatLongReport, &reportInterval);
```

## See also

[ILocation](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocation)