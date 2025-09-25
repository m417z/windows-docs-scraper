# ILocationReport::GetTimestamp

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the date and time when the report was generated.

## Parameters

### `pCreationTime` [out]

Address of a **SYSTEMTIME** that receives the date and time when the report was generated. Time stamps are provided as Coordinated Universal Time (UTC).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport)