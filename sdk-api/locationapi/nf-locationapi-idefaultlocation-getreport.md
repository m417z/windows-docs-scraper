# IDefaultLocation::GetReport

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the specified report type from the default location provider.

## Parameters

### `reportType` [in]

**REFIID** representing the interface ID for the type of report being retrieved.

### `ppLocationReport` [out]

The address of a pointer to [ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport) that receives the specified location report from the default location provider.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The location report was successfully retrieved. |
| **E_INVALIDARG** | *reportType*  is other than **IID_ILatLongReport** or **IID_ICivicAddressReport**. |
| **HRESULT_FROM_WIN32(ERROR_NO_DATA)** | No data is available. This may be due to a lack of default location data in the registry, corrupt data in the registry, or a missing Country/Region field in the default location report. |
| **E_POINTER** | *ppLocationReport* is **NULL**. |

## Remarks

[ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport) is the base interface for specific location report types. The actual interface you use for *ppLocationReport* must match the type you specified through *reportType*.

A call to **IDefaultLocation::GetReport** may result in a notification being displayed in the taskbar, and a Location Activity event being logged in Event Viewer, if it is the application's first use of location.

## See also

[About Location Notifications](https://learn.microsoft.com/previous-versions/visualstudio)

[About Logging Location Activity](https://learn.microsoft.com/previous-versions/visualstudio)

[IDefaultLocation](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-idefaultlocation)