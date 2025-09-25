# IDefaultLocation::SetReport

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Sets the default location.

## Parameters

### `reportType` [in]

**REFIID** that represents the interface ID of the type of report that is passed using *pLocationReport*.

### `pLocationReport` [in]

Pointer to the [ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport) instance that contains the location report from the default location provider.

## Return value

Possible values include, but are not limited to, those in the following table.

| Return value | Description |
| --- | --- |
| S_OK | The location report was successfully set. |
| E_INVALIDARG | The location report contains invalid data. This may occur when a civic address report does not contain a valid IS0 3166 two-letter country or region code, or when a latitude/longitude report does not contain a latitude between -90 and 90 or does not contain a longitude between -180 and 180. |
| E_ACCESSDENIED | The user does not have permission to set the default location. |

## Remarks

[ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport) is the base interface of specific location report types. The actual interface you use for *pLocationReport* must match the type you specify through *reportType*.

Note that the type specified by *reportType* must be the **IID** of either [ICivicAddressReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-icivicaddressreport) or [ILatLongReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilatlongreport).

The latitude and longitude provided in a latitude/longitude report must correspond to a location on the globe. Otherwise this method returns an **HRESULT** error value.

**Note** An application does not receive the expected location change event from [OnLocationChanged](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-ilocationevents-onlocationchanged) if both of the following conditions are true. First, the application runs as a service, in the context of the LOCALSERVICE, SYSTEM, or NETWORKSERVICE user account. Second, the location change event results from changing the default location, either manually when the user selects **Default Location** in Control Panel, or programmatically when an application calls [IDefaultLocation::SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-idefaultlocation).

#### Examples

The following example shows how to set the default location using a civic address report.

```cpp
            // set the civic address fields of the Default Location
            hr = spDefaultLocation->SetReport(IID_ICivicAddressReport, spCivicAddressReport);
            if (E_INVALIDARG == hr)
            {
                wprintf(L"The civic address report has invalid data. ");
                wprintf(L"Country/region must be a valid ISO-3166 2-letter or 3-letter code.\n");
            }
            else if (E_ACCESSDENIED == hr)
            {
                wprintf(L"Administrator privilege required.\n");
            }

```

## See also

[IDefaultLocation](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-idefaultlocation)