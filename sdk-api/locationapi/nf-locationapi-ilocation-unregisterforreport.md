# ILocation::UnregisterForReport

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Stops event notifications for the specified report type.

## Parameters

### `reportType` [in]

**REFIID** that specifies the interface ID of the report type for which to stop events.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The caller is not registered to receive events for the specified report type. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | *reportType*  is other than IID_ILatLongReport or IID_ICivicAddressReport. |

## See also

[ILocation](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocation)