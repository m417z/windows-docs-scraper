## Description

The **WIFI_STA_BANDS_COMBINATION** structure contains a list of band IDs that are available for secondary STA connections.

## Members

### `NumStaBands`

The number bands.

### `BandIDs`

An array of [**WDI_BAND_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ne-dot11wificxtypes-wdi_band_id) structures. Currently **MAX_SIMULTANEOUS_BAND_CONNECTIONS_ALLOWED** is defined as follows:

```#define MAX_SIMULTANEOUS_BAND_CONNECTIONS_ALLOWED 4```

## Remarks

## See also

[**WIFI_STATION_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_station_capabilities)