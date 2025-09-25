# ILocationEvents::OnStatusChanged

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Called when a report status changes.

## Parameters

### `reportType` [in]

**REFIID** that specifies the interface ID of the report type for which the status has changed.

### `newStatus` [in]

A constant from the [LOCATION_REPORT_STATUS](https://learn.microsoft.com/windows/desktop/api/locationapi/ne-locationapi-location_report_status) enumeration that contains the new status.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This event provides report status for new reports. The most recent reports remain available through [ILocation::GetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-getreport), regardless of the status reported by this event.

#### Examples

The following is a sample implementation of **OnStatusChanged** that handles status changed events for latitude/longitude reports.

```cpp
// This is called when the status of a report type changes.
// The LOCATION_REPORT_STATUS enumeration is defined in LocApi.h in the SDK
STDMETHODIMP CLocationEvents::OnStatusChanged(REFIID reportType, LOCATION_REPORT_STATUS status)
{
    if (IID_ILatLongReport == reportType)
    {
        switch (status)
        {
        case REPORT_NOT_SUPPORTED:
            wprintf(L"\nNo devices detected.\n");
            break;
        case REPORT_ERROR:
            wprintf(L"\nReport error.\n");
            break;
        case REPORT_ACCESS_DENIED:
            wprintf(L"\nAccess denied to reports.\n");
            break;
        case REPORT_INITIALIZING:
            wprintf(L"\nReport is initializing.\n");
            break;
        case REPORT_RUNNING:
            wprintf(L"\nRunning.\n");
            break;
        }
    }
    else if (IID_ICivicAddressReport == reportType)
    {
    }

    return S_OK;
}

```

## See also

[ILocationEvents](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationevents)