## Description

The **GNSS_GEOFENCES_TRACKINGSTATUS_DATA** structure is used by the GNSS engine to notify of any changes in the tracking status while tracking a set of previously created geofences.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `Status`

A failure code indicates that the GNSS engine is unable to track the geofences (due to bad signal conditions or other transient errors).

A success code indicates that the GNSS engine was previously unable to track geofences, and is now able to track them.

### `StatusTimeStamp`

The UTC time of this status.

### `Unused`

Padding buffer reserved for future use.

## Remarks

The GNSS engine must not raise events when it is not tracking any mobile-originated geofences (but tracking network-initiated Geofences), or when the geofence tracking has been reset by the GNSS_ResetGeofenceTracking command.