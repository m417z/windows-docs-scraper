# ILocationPower::Disconnect

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Used by Windows Store app browsers in Windows 8 to notify the location platform that an app has been suspended (disconnect) and restored (connect).

Most apps will not need to use this method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ILocationPower](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationpower)