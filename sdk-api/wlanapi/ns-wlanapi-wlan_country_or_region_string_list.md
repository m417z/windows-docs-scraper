# WLAN_COUNTRY_OR_REGION_STRING_LIST structure

## Description

A **WLAN_COUNTRY_OR_REGION_STRING_LIST** structure contains a list of supported country or region strings.

## Members

### `dwNumberOfItems`

Indicates the number of supported country or region strings.

### `pCountryOrRegionStringList.unique`

### `pCountryOrRegionStringList.size_is`

### `pCountryOrRegionStringList.size_is.dwNumberOfItems`

### `pCountryOrRegionStringList`

A list of supported country or region strings. In Windows, a **DOT11_COUNTRY_OR_REGION_STRING** is of type **char[3]**.

## See also

[WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface)