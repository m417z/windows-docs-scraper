# _WWAN_NITZ_INFO structure

## Description

The **WWAN_NITZ_INFO** structure describes the current network time and time zone information.

## Members

### `Year`

The year as an integer. For example, **2014**.

### `Month`

The month, \[1-12\], where January == **1**.

### `Day`

The day of the month, \[1-31\].

### `Hour`

The hour, \[0-23\].

### `Minute`

The minute, \[0-59\].

### `Second`

The second, \[0-59\].

### `TimeZoneOffsetMinutes`

The time zone offset, in minutes, from UTC. This value includes any adjustment for the current state of daylight saving time. This value should be set to **0xFFFFFFFF** when time zone info is not available.

### `DaylightSavingTimeOffsetMinutes`

The offset for daylight saving time, in minutes. This value should be set to **0xFFFFFFFF** when daylight saving time is not available.

### `DataClasses`

Data classes supported by this network. If this information is not available, this field should be set to **WwanDataClassNone**.

## Remarks

This structure is used in the [**NDIS_WWAN_NITZ_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_nitz_info) structure.

## See also

[MB NITZ support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-nitz-support)

[OID_WWAN_NITZ](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-nitz)

[**NDIS_WWAN_NITZ_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_nitz_info)