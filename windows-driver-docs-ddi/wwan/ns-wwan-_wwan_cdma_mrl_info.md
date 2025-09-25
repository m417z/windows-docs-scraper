# _WWAN_CDMA_MRL_INFO structure

## Description

The **WWAN_CDMA_MRL_INFO** structure represents information about a CDMA serving cell or neighboring cell.

## Members

### `ServingCellFlag`

Indicates whether this is a serving cell. A value of 1 indicates a serving cell, while a value of 0 indicates a neighboring cell. There may be more than one serving cell at a time (notably while in a call).

### `NID`

The Network ID (0-65535). Use 0xFFFFFFFF when this information is not available.

### `SID`

The System ID (0-32767). Use 0xFFFFFFFF when this information is not available.

### `BaseStationId`

The Base Station ID (0-65535). Use 0xFFFFFFFF when this information is not available.

### `BaseLatitude`

The Base Station Latitude (0-4194303). This is encoded in units of 0.25 seconds, expressed in two’s complement representation within the low 22 bits of the DWORD. As a signed value, North latitudes are positive. Use 0xFFFFFFFF when this information is not available.

### `BaseLongitude`

The Base Station Longitude (0-8388607). This is encoded in units of 0.25 seconds, expressed in two’s complement representation within the low 23 bits of the DWORD. As a signed value, East longitudes are positive. Use 0xFFFFFFFF when this information is not available.

### `RefPn`

The Base Station PN Number (0-511). Use 0xFFFFFFFF when this information is not available.

### `GPSSeconds`

The GPS seconds, or the time at which this arrived from the base station. Use 0xFFFFFFFF when this information is not available.

### `PilotStrength`

The Signal Strength of the pilot (0-63). Use 0xFFFFFFFF when this information is not available.

## Remarks

**WWAN_CDMA_MRL_INFO** is designed for the CDMA2000 network type. There can be more than one CDMA2000 serving cell at the same time. Both serving cells and neighboring cells will be returned in the same list. The **ServingCellFlag** member indicates whether a cell is a serving cell or not.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[WWAN_CDMA_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_cdma_mrl)