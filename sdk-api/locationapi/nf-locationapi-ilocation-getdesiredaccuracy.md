# ILocation::GetDesiredAccuracy

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the current requested accuracy setting.

## Parameters

### `reportType` [in]

**REFIID** that specifies the report type for which to get the requested accuracy.

### `pDesiredAccuracy` [out]

The address of a [LOCATION_DESIRED_ACCURACY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd756639(v=vs.85)) that receives the accuracy value. If the report is not registered, this will be set to **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | *reportType* was other than **IID_ILatLongReport** or **IID_ICivicAddressReport**. |
| **E_INVALIDARG** | *pDesiredAccuracy* is **NULL**. |

## See also

[ILocation](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocation)