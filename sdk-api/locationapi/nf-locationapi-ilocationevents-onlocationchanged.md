# ILocationEvents::OnLocationChanged

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Called when a new location report is available.

## Parameters

### `reportType` [in]

**REFIID** that contains the interface ID of the report type contained in *pLocationReport*.

### `pLocationReport` [in]

Pointer to the [ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport) instance that contains the new location report.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport) is the base interface of specific location report types. The actual interface that the caller receives for *pLocationReport* will match the type specified by *reportType*.

If the application calls **OnLocationChanged** as a result of its first use of location, the call might cause a notification to appear in the taskbar, and cause a Location Activity event to be logged in Event Viewer.

**Note** An application does not receive the expected location change event from **OnLocationChanged** if both of the following conditions are true. First, the application runs as a service, in the context of the LOCALSERVICE, SYSTEM, or NETWORKSERVICE user account. Second, the location change event results from changing the default location, either manually when the user selects **Default Location** in Control Panel, or programmatically when an application calls [IDefaultLocation::SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-idefaultlocation).

#### Examples

The following sample implementation of **OnLocationChanged** handles the location change event for a latitude/longitude report. This implementation prints the following information about a latitude/longitude location change event: the timestamp, the sensor ID, the latitude, the longitude, the error radius, the altitude, and the altitude error.

```cpp
// This is called when there is a new location report
STDMETHODIMP CLocationEvents::OnLocationChanged(REFIID reportType, ILocationReport* pLocationReport)
{
    // If the report type is a Latitude/Longitude report (as opposed to IID_ICivicAddressReport or another type)
    if (IID_ILatLongReport == reportType)
    {
        CComPtr<ILatLongReport> spLatLongReport;

        // Get the ILatLongReport interface from ILocationReport
        if ((SUCCEEDED(pLocationReport->QueryInterface(IID_PPV_ARGS(&spLatLongReport)))) && (NULL != spLatLongReport.p))
        {
            // Print the Report Type GUID
            wchar_t szGUID[64];
            wprintf(L"\nReportType: %s", GUIDToString(IID_ILatLongReport, szGUID, ARRAYSIZE(szGUID)));

            // Print the Timestamp and the time since the last report
            SYSTEMTIME systemTime;
            if (SUCCEEDED(spLatLongReport->GetTimestamp(&systemTime)))
            {
                // Compute the number of 100ns units that difference between the current report's time and the previous report's time.
                ULONGLONG currentTime = 0, diffTime = 0;
                if (TRUE == SystemTimeToFileTime(&systemTime, (FILETIME*)&currentTime))
                {
                    diffTime = (currentTime > m_previousTime) ? (currentTime - m_previousTime) : 0;
                }

                wprintf(L"\nTimestamp: YY:%d, MM:%d, DD:%d, HH:%d, MM:%d, SS:%d, MS:%d [%I64d]\n",
                    systemTime.wYear,
                    systemTime.wMonth,
                    systemTime.wDay,
                    systemTime.wHour,
                    systemTime.wMinute,
                    systemTime.wSecond,
                    systemTime.wMilliseconds,
                    diffTime / 10000); // Display in milliseconds

                m_previousTime = currentTime; // Set the previous time to the current time for the next report.
            }

            // Print the Sensor ID GUID
            GUID sensorID = {0};
            if (SUCCEEDED(spLatLongReport->GetSensorID(&sensorID)))
            {
                wchar_t szGUID[64];
                wprintf(L"SensorID: %s\n", GUIDToString(sensorID, szGUID, ARRAYSIZE(szGUID)));
            }

            DOUBLE latitude = 0, longitude = 0, altitude = 0, errorRadius = 0, altitudeError = 0;

            // Print the Latitude
            if (SUCCEEDED(spLatLongReport->GetLatitude(&latitude)))
            {
                wprintf(L"Latitude: %f\n", latitude);
            }

            // Print the Longitude
            if (SUCCEEDED(spLatLongReport->GetLongitude(&longitude)))
            {
                wprintf(L"Longitude: %f\n", longitude);
            }

            // Print the Altitude
            if (SUCCEEDED(spLatLongReport->GetAltitude(&altitude)))
            {
                wprintf(L"Altitude: %f\n", altitude);
            }
            else
            {
                // Altitude is optional and may not be available
                wprintf(L"Altitude: Not available.\n");
            }

            // Print the Error Radius
            if (SUCCEEDED(spLatLongReport->GetErrorRadius(&errorRadius)))
            {
                wprintf(L"Error Radius: %f\n", errorRadius);
            }

            // Print the Altitude Error
            if (SUCCEEDED(spLatLongReport->GetAltitudeError(&altitudeError)))
            {
                wprintf(L"Altitude Error: %f\n", altitudeError);
            }
            else
            {
                // Altitude Error is optional and may not be available
                wprintf(L"Altitude Error: Not available.\n");
            }
        }
    }

    return S_OK;
}

```