# ICivicAddressReport::GetCountryRegion

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves the two-letter country or region code.

## Parameters

### `pbstrCountryRegion` [out]

Address of a **BSTR** that receives the country or region code.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The two-letter country or region code is in ISO 3166 format.

#### Examples

The following example demonstrates how to call **GetCountryRegion**.

```cpp
    hr = pCivicAddressReport->GetCountryRegion(&bstrCountryRegion);
    if (SUCCEEDED(hr))
    {
        // Country/Region is an ISO-3166-1 two-letter code.
       wprintf(L"\tCountry/Region:\t%s\n\n", bstrCountryRegion);
    }

```

## See also

[ICivicAddressReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-icivicaddressreport)