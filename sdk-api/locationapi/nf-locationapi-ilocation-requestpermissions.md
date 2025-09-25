# ILocation::RequestPermissions

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation)
API.
]

Opens a system dialog box to request user permission to enable location devices.

## Parameters

### `hParent` [in]

**HWND** for the parent window. This parameter is optional. In Windows 8 the dialog is always modal if *hParent* is provided, and not modal if *hParent* is NULL.

### `pReportTypes` [in]

Pointer to an **IID** array. This array must contain interface IDs for all report types for which you are requesting permission. The interface IDs of the valid report types are IID_ILatLongReport and IID_ICivicAddressReport. The count of IDs must match the value specified through the *count* parameter.

### `count` [in]

The count of interface IDs contained in *pReportTypes*.

### `fModal`

This parameter is not used.

## Return value

This method can return one of these values.

The following table describes return codes when the call is synchronous.

| Return code | Description |
| --- | --- |
| **S_OK** | The user enabled location services. The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)** | The location platform is disabled. An administrator turned the location platform off. |
| **HRESULT_FROM_WIN32(ERROR_CANCELLED)** | The user did not enable access to location services or canceled the dialog box. |

The following table describes return codes when the call is asynchronous.

| Return code | Description |
| --- | --- |
| **S_OK** | The user enabled access to location services. The method succeeded. |
| **E_INVALIDARG** | An argument is not valid. |
| **HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)** | The location platform is disabled. An administrator turned the location platform off. The dialog box was not shown. |

## Remarks

If the user chooses not to enable location services, Windows will not show the permissions dialog box again.

**Note** Repeated asynchronous calls to **RequestPermissions** will display multiple instances of the **Enable location services** dialog box and can potentially flood the screen with dialog boxes, resulting in a poor user experience. If you think that other location sensors might be installed after your first call to **RequestPermissions**, requiring another call to **RequestPermissions**, you should either call **RequestPermissions** synchronously or wait until all location sensors are installed to make an asynchronous call.

**Note** Making a synchronous call from the user interface (UI) thread of a Windows application can block the UI thread and make the application less responsive. To prevent this, do not make a synchronous call to **RequestPermissions** from the UI thread.

**Note** If an application running in protected mode, such as a Browser Helper Object (BHO) for Internet Explorer, calls **RequestPermissions**, and the user chooses not to enable location using the dialog box, the location provider will not be enabled, but Windows will display the dialog box again if **RequestPermissions** is called again by the same user.

#### Examples

The following example demonstrates how to call **RequestPermissions** to request permission for latitude/longitude reports.

```cpp
             // Array of report types of interest. Other ones include IID_ICivicAddressReport
            IID REPORT_TYPES[] = { IID_ILatLongReport };

            // Request permissions for this user account to receive location data for all the
            // types defined in REPORT_TYPES (which is currently just one report type)
            // The last parameter is not used.
            if (FAILED(spLocation->RequestPermissions(
                  NULL,
                  REPORT_TYPES,
                  ARRAYSIZE(REPORT_TYPES),
                  TRUE)))
            {
                wprintf(L"Warning: Unable to request permissions.\n");
            }

```