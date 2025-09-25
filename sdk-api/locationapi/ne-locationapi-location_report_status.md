# LOCATION_REPORT_STATUS enumeration

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Defines possible status for new reports of a particular report type.

## Constants

### `REPORT_NOT_SUPPORTED:0`

The requested report type is not supported by the API. No location providers of the requested type are installed.

### `REPORT_ERROR:1`

There was an error when creating the report, or location providers for the requested type are unable to provide any data. Location providers might be currently unavailable, or location providers cannot obtain any data. For example, this state may occur when a GPS sensor is indoors and no satellites are in view.

### `REPORT_ACCESS_DENIED:2`

 No permissions have been granted to access this report type. Call [ILocation::RequestPermissions](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-requestpermissions).

### `REPORT_INITIALIZING:3`

The report is being initialized.

### `REPORT_RUNNING:4`

The report is running. New location data for the requested report type is available.

## Remarks

These values represent status for new reports. The most recent reports remain available through [ILocation::GetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-getreport), regardless of the reported status. If the status is **REPORT_RUNNING**, the data in a report is new. Otherwise, **ILocation::GetReport** provides cached data if cached data is available.

#### Examples

The following code example demonstrates how to retrieve the **LOCATION_REPORT_STATUS** values from [ILocation::GetReportStatus](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-getreportstatus).

```cpp
    // Get the status of this report type
    if (SUCCEEDED(spLocation->GetReportStatus(IID_ILatLongReport, &status)))
    {
        bool fIsNotRunning = true;
        switch (status)
        {
        case REPORT_RUNNING:
            // If the status for the current report is running,
            // then do not print any additional message.
            // Otherwise, print a message indicating that reports may contain cached data.
            fIsNotRunning = false;
            break;
        case REPORT_NOT_SUPPORTED:
            wprintf(L"\nThere is no sensor installed for this report type.\n");
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
        }

        if (true == fIsNotRunning)
        {
            wprintf(L"Location reports returned from GetReport contain cached data.\n");
        }
    }

```

The following code is a sample implementation of the callback function [ILocationEvents::OnStatusChanged](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocationevents-onstatuschanged). This implementation prints out messages when there is a change in the status of latitude/longitude reports.

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