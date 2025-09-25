# ICivicAddressReport::GetAddressLine1

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the first line of a street address.

## Parameters

### `pbstrAddress1` [out]

Address of a **BSTR** that receives the first line of a street address.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICivicAddressReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-icivicaddressreport)