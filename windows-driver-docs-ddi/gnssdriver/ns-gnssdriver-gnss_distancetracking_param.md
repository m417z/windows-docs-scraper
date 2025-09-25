# GNSS_DISTANCETRACKING_PARAM structure

## Description

This structure defines the parameters for a distance-based tracking fix session.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `MovementThreshold`

If the device moves beyond this threshold, a fix will be generated/recorded. A value of zero indicates that a fix should be reported whenever the device moves. This value is specified in meters.