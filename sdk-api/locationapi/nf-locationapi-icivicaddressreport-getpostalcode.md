# ICivicAddressReport::GetPostalCode

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the postal code.

## Parameters

### `pbstrPostalCode` [out]

Address of a **BSTR** that receives the postal code.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICivicAddressReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-icivicaddressreport)