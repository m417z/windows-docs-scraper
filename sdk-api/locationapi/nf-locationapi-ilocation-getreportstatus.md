# ILocation::GetReportStatus

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the status for the specified report type.

## Parameters

### `reportType` [in]

**REFIID** that specifies the report type for which to get the interval.

### `pStatus` [out]

Address of a [LOCATION_REPORT_STATUS](https://learn.microsoft.com/windows/desktop/api/locationapi/ne-locationapi-location_report_status) that receives the current status for the specified report.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | *reportType*  is other than **IID_ILatLongReport** or **IID_ICivicAddressReport**. |
| **E_INVALIDARG** | *pStatus* is **NULL**. |

## Remarks

This method retrieves report status for new reports. The most recent reports remain available through [ILocation::GetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-getreport), regardless of the status reported by this method.

### Known Issues

When an application first starts, or when a new location sensor is enabled, **GetReportStatus** may report a status of **REPORT_RUNNING** shortly before the location report is available.

Therefore, an initial call to [GetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-getreport) will return an error (**ERROR_NO_DATA**) or a value that is not from the expected location sensor, even if **GetReportStatus** indicates a status of **REPORT_RUNNING**. This can happen in the following cases:

1. The application polls for status by using **GetReportStatus** until a report status of **REPORT_RUNNING** is returned, and then calls [GetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-getreport).
2. **GetReportStatus** is called when the application starts. This may occur after creation of the location object, or after calling [RequestPermissions](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocation-requestpermissions).

An application can mitigate the issue by implementing the following workaround. The workaround involves subscribing to location report events.

### Workaround: Subscribing to Events

The application can subscribe to report events and wait for the report from the [OnLocationChanged](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocationevents-onlocationchanged) event or the [OnStatusChanged](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocationevents-onstatuschanged) event. The application should wait for a specified finite amount of time.

The following example shows an application that waits for a location report of type [ILatLongReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilatlongreport). If a report is successfully retrieved within the specified amount of time, it prints out a message indicating that data was received.

The following example code demonstrates how an application may call a function named **WaitForLocationReport** that registers for events and waits for the first location report. **WaitForLocationReport** waits for an event that is set by a callback object. The function **WaitForLocationReport** and the callback object is defined in the examples that follow this one.

```cpp
// main.cpp
// An application that demonstrates how to wait for a location report.
// This sample waits for latitude/longitude reports but can be modified
// to wait for civic address reports by replacing IID_ILatLongReport
// with IID_ICivicAddressReport in the following code.

#include "WaitForLocationReport.h"

#define DEFAULT_WAIT_FOR_LOCATION_REPORT 500 // Wait for half a second.

int wmain()
{
    // You may use the flags COINIT_MULTITHREADED | COINIT_DISABLE_OLE1DDE
    // to specify the multi-threaded concurrency model.
    HRESULT hr = ::CoInitializeEx(NULL,
        COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (SUCCEEDED(hr))
    {
        int args;
        PWSTR *pszArgList = ::CommandLineToArgvW(::GetCommandLineW(), &args);

        DWORD const dwTimeToWait =
            (2 == args) ? static_cast<DWORD>(_wtoi(pszArgList[1])) : DEFAULT_WAIT_FOR_LOCATION_REPORT;

        ::LocalFree(pszArgList);

        wprintf_s(L"Wait time set to %lu\n", dwTimeToWait);

        ILocation *pLocation; // This is the main Location interface.
        hr = CoCreateInstance(CLSID_Location, NULL, CLSCTX_INPROC, IID_PPV_ARGS(&pLocation));
        if (SUCCEEDED(hr))
        {
            // Array of report types to listen for.
            // Replace IID_ILatLongReport with IID_ICivicAddressReport
            // for civic address reports.
            IID REPORT_TYPES[] = { IID_ILatLongReport };

            // Request permissions for this user account to receive location data for all the
            // types defined in REPORT_TYPES (which is currently just one report)
            // TRUE means a synchronous request.
            if (FAILED(pLocation->RequestPermissions(NULL, REPORT_TYPES, ARRAYSIZE(REPORT_TYPES), TRUE)))
            {
                wprintf_s(L"Warning: Unable to request permissions.\n");
            }

            ILocationReport *pLocationReport; // This is our location report object
            // Replace IID_ILatLongReport with IID_ICivicAddressReport for civic address reports
            hr = ::WaitForLocationReport(pLocation, IID_ILatLongReport, dwTimeToWait, &pLocationReport);
            if (SUCCEEDED(hr))
            {
                wprintf_s(L"Successfully received data via GetReport().\n");
                pLocationReport->Release();
            }
            else if (RPC_S_CALLPENDING == hr)
            {
                wprintf_s(L"No LatLong data received.  Wait time of %lu elapsed.\n", dwTimeToWait);
            }
            pLocation->Release();
        }

        ::CoUninitialize();
    }

    return 0;
}

```

The following example code is separated into WaitForLocationReport.h and WaitForLocationReport.cpp. WaitForLocationReport.h contains the header for the **WaitForLocationReport** function. WaitForLocationReport.cpp contains the definition of the **WaitForLocationReport** function and the definition of the callback object that it uses. The callback object provides implementations of the [OnLocationChanged](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocationevents-onlocationchanged) and [OnStatusChanged](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocationevents-onstatuschanged) callback methods. Within these methods, it sets an event that signals when a report is available.

```cpp
// WaitForLocationReport.h
// Header for the declaration of the WaitForLocationReport function.

#pragma once

#include <windows.h>
#include <LocationApi.h>
#include <wchar.h>

HRESULT WaitForLocationReport(
    ILocation* pLocation,              // Location object.
    REFIID reportType,                 // Type of report.
    DWORD dwTimeToWait,                // Milliseconds to wait.
    ILocationReport** ppLocationReport // Receives the location report.
);

```

```cpp
// WaitForLocationReport.cpp
// Contains definitions of the WaitForLocationReport function and
// the callback object that it uses.

#include "WaitForLocationReport.h"
#include <shlwapi.h>
#include <new>

// Implementation of the callback interface that receives location reports.
class CLocationCallback : public ILocationEvents
{
public:
    CLocationCallback() : _cRef(1), _hDataEvent(::CreateEvent(
        NULL,  // Default security attributes.
        FALSE, // Auto-reset event.
        FALSE, // Initial state is nonsignaled.
        NULL)) // No event name.
    {
    }

    virtual ~CLocationCallback()
    {
        if (_hDataEvent)
        {
            ::CloseHandle(_hDataEvent);
        }
    }

    IFACEMETHODIMP QueryInterface(REFIID riid, void **ppv)
    {
        if ((riid == IID_IUnknown) ||
            (riid == IID_ILocationEvents))
        {
            *ppv = static_cast<ILocationEvents*>(this);
        }
        else
        {
            *ppv = NULL;
            return E_NOINTERFACE;
        }
        AddRef();
        return S_OK;
    }

    IFACEMETHODIMP_(ULONG) AddRef()
    {
        return InterlockedIncrement(&_cRef);
    }

    IFACEMETHODIMP_(ULONG) Release()
    {
        long cRef = InterlockedDecrement(&_cRef);
        if (!cRef)
        {
            delete this;
        }
        return cRef;
    }

    // ILocationEvents

    // This is called when there is a new location report.
    IFACEMETHODIMP OnLocationChanged(REFIID /*reportType*/, ILocationReport* /*pLocationReport*/)
    {
        ::SetEvent(_hDataEvent);
        return S_OK;
    }

    // This is called when the status of a report type changes.
    // The LOCATION_REPORT_STATUS enumeration is defined in LocApi.h in the SDK
    IFACEMETHODIMP OnStatusChanged(REFIID /*reportType*/, LOCATION_REPORT_STATUS status)
    {
        if (REPORT_RUNNING == status)
        {
            ::SetEvent(_hDataEvent);
        }
        return S_OK;
    }

    HANDLE GetEventHandle()
    {
        return _hDataEvent;
    }

private:
    long _cRef;
    HANDLE _hDataEvent;    // Data Event Handle
};

// Waits to receive a location report.
// This function waits for the callback object to signal when
// a report event or status event occurs, and then calls GetReport.
// Even if no report event or status event is received before the timeout,
// this function still queries for the last known report by calling GetReport.
// The last known report may be cached data from a location sensor that is not
// reporting events, or data from the default location provider.
//
// Returns S_OK if the location report has been returned
// or RPC_S_CALLPENDING if the timeout expired.
HRESULT WaitForLocationReport(
    ILocation* pLocation,               // Location object.
    REFIID reportType,                 // Type of report to wait for.
    DWORD dwTimeToWait,                // Milliseconds to wait.
    ILocationReport **ppLocationReport // Receives the location report.
    )
{
    *ppLocationReport = NULL;

    CLocationCallback *pLocationCallback = new(std::nothrow) CLocationCallback();
    HRESULT hr = pLocationCallback ? S_OK : E_OUTOFMEMORY;
    if (SUCCEEDED(hr))
    {
        HANDLE hEvent = pLocationCallback->GetEventHandle();
        hr = hEvent ? S_OK : E_FAIL;
        if (SUCCEEDED(hr))
        {
            // Tell the Location API that we want to register for a report.
            hr = pLocation->RegisterForReport(pLocationCallback, reportType, 0);
            if (SUCCEEDED(hr))
            {
                DWORD dwIndex;
                HRESULT hrWait = CoWaitForMultipleHandles(0, dwTimeToWait, 1, &hEvent, &dwIndex);
                if ((S_OK == hrWait) || (RPC_S_CALLPENDING == hrWait))
                {
                    // Even if there is a timeout indicated by RPC_S_CALLPENDING
                    // attempt to query the report to return the last known report.
                    hr = pLocation->GetReport(reportType, ppLocationReport);
                    if (FAILED(hr) && (RPC_S_CALLPENDING == hrWait))
                    {
                        // Override hr error if the request timed out and
                        // no data is available from the last known report.
                        hr = hrWait;    // RPC_S_CALLPENDING
                    }
                }
                // Unregister from reports from the Location API.
                pLocation->UnregisterForReport(reportType);
            }
        }
        pLocationCallback->Release();
    }
    return hr;
}

```

## See also

[ILocation](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocation)