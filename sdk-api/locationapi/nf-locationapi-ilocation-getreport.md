# ILocation::GetReport

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves a location report.

## Parameters

### `reportType` [in]

**REFIID** that specifies the type of report to retrieve.

### `ppLocationReport` [out]

Address of a pointer to [ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport) that receives the specified location report.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_ACCESSDENIED** | The location provider has permissions disabled and report data cannot be retrieved. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | *reportType*  is other than **IID_ILatLongReport** or **IID_ICivicAddressReport**. |
| **HRESULT_FROM_WIN32(ERROR_NO_DATA)** | No data is available. This may be due to an error or due to the provider being unavailable. |
| **E_POINTER** | *ppLocationReport* is **NULL**. |
| **E_INVALIDARG** | *reportType*  is **IID_ILatLongReport**, and the latitude or longitude value is out of bounds. |
| **E_FAIL** | The underlying sensor is **NULL** or disconnected. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

[ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport) is the base interface for specific location report types. Call **QueryInterface** to retrieve a pointer to the correct report type.

When **GetReport** is called, it may result in a notification being displayed in the taskbar, and a Location Activity event being logged in Event Viewer, if it is the application's first use of location.

**Note** When an application first starts, or when a new location sensor is enabled, [GetReportStatus](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-getreportstatus) may report a status of **REPORT_RUNNING** shortly before the new location report is available. Therefore, an initial call to **GetReport** can return an error (**ERROR_NO_DATA**) or a value that is not from the expected location sensor, even if **GetReportStatus** indicates a status of **REPORT_RUNNING**. See [GetReportStatus](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-getreportstatus) for a description of a workaround for this issue.

#### Examples

The following example calls **GetReport** for latitude/longitude reports and demonstrates how to call QueryInterface to retrieve a pointer to the specified report type.

```cpp
CComPtr<ILocationReport> spLocationReport; // This is our location report object
CComPtr<ILatLongReport> spLatLongReport; // This is our LatLong report object

// Get the current latitude/longitude location report,
hr = spLocation->GetReport(IID_ILatLongReport, &spLocationReport);
// then get a pointer to the ILatLongReport interface by calling QueryInterface
if (SUCCEEDED(hr))
{
    hr = spLocationReport->QueryInterface(&spLatLongReport);
}

```