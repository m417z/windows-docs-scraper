# _KSCAMERA_EXTENDEDPROP_PROFILE structure

## Description

The payload of the KSPROPERTY_CAMERACONTROL_EXTENDED_PROFILE control contains KSCAMERA_EXTENDEDPROP_HEADER + KSCAMERA_EXTENDEDPROP_PROFILE.

## Members

### `ProfileId`

A GUID representing the selected profile. If this is KSCAMERAPROFILE_Legacy, no profile was selected, the camera driver must expose the Reduced Set Media Type.

If this field is GUID_NULL, no profile was selected, but the application is profile aware so the camera driver must expose the full range of media types.

If the camera is initialized by a SharedReadOnly application GUID_NULL will be sent to the driver. When an ExclusiveControl application comes in it may change the profile and driver is expected to make any sensor changes to meet the expectation of the new camera profile even if streaming has already started.

### `Index`

An index value associated with the identified profile.

### `Reserved`

Unused. Must be 0.