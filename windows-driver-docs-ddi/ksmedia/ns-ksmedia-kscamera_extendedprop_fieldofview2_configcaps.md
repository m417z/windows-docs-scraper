## Description

The **KSCAMERA_EXTENDEDPROP_FIELDOFVIEW2_CONFIGCAPS** structure defines the configuration capabilities of a camera's field of view (FoV).

## Members

### `DefaultDiagonalFieldOfViewInDegrees`

 This is the default diagonal field of view in degrees. The DefaultDiagonalFieldOfViewInDegrees value must be equal to one of the values provided in the DiscreteFoVStops array.

### `DiscreteFoVStopsCount`

This is a count of valid FoVStops in the DiscreteFoVStops[360] array, with value between 1 and 360. The array has room for maximum of 360 FoV values, but not all of them need to be populated.

For example, if three FoV values are supported: 110, 90, and 75 degrees

```cpp
DiscreteFoVStopsCount = 3,
DiscreteFoVStops[0] = 110,
DiscreteFoVStops[1] = 90,
DiscreteFoVStops[2] = 75
DiscreteFoVStops[3] = 0 (not populated)
...
DiscreteFoVStops[359] = 0 (not populated)
```

### `DiscreteFoVStops[360]`

This is an array of discrete FoV stops. Each element in the array represents a specific field of view setting in degrees. The values are populated in descending order.

### `Reserved`

Reserved. Set to 0.

## Remarks

## See also

[KSPROPERTY_CAMERACONTROL_EXTENDED_FIELDOFVIEW2](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-fieldofview2)

[KSPROPERTY_CAMERACONTROL_EXTENDED_FIELDOFVIEW2_CONFIGCAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-fieldofview2-configcaps)