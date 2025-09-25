## Description

The **GNSS_GEOREGION** structure defines the geographical shape of a geofence.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `GeoRegionType`

[GNSS_GEOREGIONTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ne-gnssdriver-gnss_georegiontype) enumeration that defines the georegion type of a geofence.

### `Circle`

[GNSS_GEOREGION_CIRCLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_georegion_circle) structure that defines a circular geofence.

### `Unused`

Padding buffer reserved for future use.

## Remarks

A geographical shape is used to define a geofence. Windows 10 currently supports only circular geofences.