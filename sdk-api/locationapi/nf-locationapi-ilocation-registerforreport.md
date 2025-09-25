# ILocation::RegisterForReport

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Requests location report events.

## Parameters

### `pEvents` [in]

Pointer to the [ILocationEvents](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationevents) callback interface through which the requested event notifications will be received.

### `reportType` [in]

**GUID** that specifies the interface ID of the report type for which to receive event notifications.

### `dwRequestedReportInterval` [in]

**DWORD** that specifies the requested elapsed time, in milliseconds, between event notifications for the specified report type. If *dwRequestedReportInterval* is zero, no minimum interval is specified and your application requests to receive events at the location sensor's default interval. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | *reportType*  is other than IID_ILatLongReport or IID_ICivicAddressReport. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_REGISTERED)** | *reportType*  is already registered. |

## Remarks

The interval you request by using the *dwRequestedReportInterval* parameter represents the shortest amount of time between events. This means that you request to receive event notifications no more frequently than specified, but the elapsed time may be significantly longer. Use the *dwRequestedReportInterval* parameter to help ensure that event notifications do not use more processor resources than necessary.

The location provider is not required to provide reports at the interval that you request. Call [GetReportInterval](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-getreportinterval) to discover the true report interval setting.

Applications that need to get location data only once, to fill out a form or place the user's location on a map, should register for events and wait for the first report event as described in [Waiting For a Location Report](https://learn.microsoft.com/previous-versions/visualstudio).

#### Examples

The following example calls **RegisterForReport** to subscribe to events.

```cpp
#include <windows.h>
#include <atlbase.h>
#include <atlcom.h>
#include <LocationApi.h> // This is the main Location API header
#include "LocationCallback.h" // This is our callback interface that receives Location reports.

class CInitializeATL : public CAtlExeModuleT<CInitializeATL>{};
CInitializeATL g_InitializeATL; // Initializes ATL for this application. This also does CoInitialize for us

int wmain()
{
    HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED | COINIT_DISABLE_OLE1DDE);;
    if (SUCCEEDED(hr))
    {
        CComPtr<ILocation> spLocation; // This is the main Location interface
        CComObject<CLocationEvents>* pLocationEvents = NULL; // This is our callback object for location reports
        IID REPORT_TYPES[] = { IID_ILatLongReport }; // Array of report types of interest. Other ones include IID_ICivicAddressReport

        hr = spLocation.CoCreateInstance(CLSID_Location); // Create the Location object

        if (SUCCEEDED(hr))
        {
            hr = CComObject<CLocationEvents>::CreateInstance(&pLocationEvents); // Create the callback object
            if (NULL != pLocationEvents)
            {
                pLocationEvents->AddRef();
            }
        }

        if (SUCCEEDED(hr))
        {
            // Request permissions for this user account to receive location data for all the
            // types defined in REPORT_TYPES (which is currently just one report)
            if (FAILED(spLocation->RequestPermissions(NULL, REPORT_TYPES, ARRAYSIZE(REPORT_TYPES), FALSE))) // FALSE means an asynchronous request
            {
                wprintf(L"Warning: Unable to request permissions.\n");
            }

            // Tell the Location API that we want to register for reports (which is currently just one report)
            for (DWORD index = 0; index < ARRAYSIZE(REPORT_TYPES); index++)
            {
                hr = spLocation->RegisterForReport(pLocationEvents, REPORT_TYPES[index], 0);
            }
        }

        if (SUCCEEDED(hr))
        {
            // Wait until user presses a key to exit app. During this time the Location API
            // will send reports to our callback interface on another thread.
            system("pause");

            // Unregister from reports from the Location API
            for (DWORD index = 0; index < ARRAYSIZE(REPORT_TYPES); index++)
            {
                spLocation->UnregisterForReport(REPORT_TYPES[index]);
            }
        }

        // Cleanup
        if (NULL != pLocationEvents)
        {
            pLocationEvents->Release();
            pLocationEvents = NULL;
        }

        CoUninitialize();
    }

    return 0;
}

```

## See also

[ILocation](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocation)

[ILocationEvents](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationevents)