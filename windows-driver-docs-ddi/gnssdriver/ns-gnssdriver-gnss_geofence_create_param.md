## Description

The **GNSS_GEOFENCE_CREATE_PARAM** structure defines the parameters for creating a geofence in the GNSS engine.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `AlertTypes`

This is a bitmask that indicates the various alerts for this geofence that the HLOS is interested in. The GNSS engine should not raise any geofence alerts unless specifically requested by the HLOS.

If the HLOS sets only GNSS_GEOFENCEALERTTYPE_ENTRY, the GNSS engine must track the geofence all the time, but raise alert only when the device has entered the geofence. The next alert is expected when the device moves out of the geofence and reenters.

If the HLOS sets only GNSS_GEOFENCEALERTTYPE_EXIT, the GNSS engine must track the geofence all the time, but raise alert only when the device has exit the geofence after entering it previously. The next alert is expected when the device moves inside the geofence and re-exits.

If the HLOS sets both the bitmasks, the GNSS engine must track the geofence all the time, and raise alert as the device moves in and out of the geofence .

In all cases, the GNSS engine must separately raise the global tracking status alert if it is unable to track the geofences (irrespective of their alert settings).

### `InitialState`

Indicates the initial state of the specific geofence, as seen by the HLOS. The GNSS engine must use this state as the starting state of the geofence, as opposed always starting from the GNSS_GeofenceState_Unknown state. This allows the GNSS engine to stay in sync with the HLOS in terms of the geofence states and get around any differences in geofence entry or exit detection logic between the GNSS engine and the HLOS.

As the GNSS engine starts tracking the newly added geofence, if it determines that the geofence is in a different state than this initial state, it should raise the appropriate alert. Conversely, if the states are identical, no alert should be raised.

### `Boundary`

The actual boundary of the geofence.

### `Unused`

Padding buffer reserved for future use.

## Remarks

A geographical shape is used to define a geofence. Windows 10 currently supports only circular geofences.