# ICivicAddressReport::GetDetailLevel

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Reserved.

## Parameters

### `pDetailLevel` [out]

Reserved.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To determine whether a civic address report contains valid data for a particular field, simply inspect the field's contents. If the field contains a value, you can assume that the field contains the most accurate information available.

## See also

[ICivicAddressReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-icivicaddressreport)