# KsFilterRegisterPowerCallbacks function

## Description

The **KsFilterRegisterPowerCallbacks** function registers power management callbacks for *Filter*.

## Parameters

### `Filter` [in]

A pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure for which to register power callbacks. In order to receive power notification messages, *Filter* must be filter-centric.

### `Sleep` [in, optional]

A pointer to a function that handles sleep requests for the device. If **NULL**, no sleep callback is registered. For more information, see the Remarks section below.

### `Wake` [in, optional]

A pointer to a function that handles wake requests for the device. If **NULL**, no wake callback is specified. For more information, see the Remarks section below.

## Remarks

> [!WARNING]
> Do not attempt to obtain the filter control mutex* from within either the Sleep or Wake callback, or deadlock may occur. For more information about mutexes, read [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

The two callbacks should be prototyped as follows:

```cpp
void Sleep/Wake (IN PKSFILTER Filter, IN DEVICE_POWER_STATE State);
```

The *Sleep* callback is made if *Filter* is a filter-centric filter and the device is going to sleep. The *Wake* callback is made if *Filter* is a filter-centric filter and the device is waking.

For information about device power states, see [Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states).

Also see [Initializing an AVStream Minidriver](https://learn.microsoft.com/windows-hardware/drivers/stream/initializing-an-avstream-minidriver) and [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing).

## See also

[KsPinRegisterPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterpowercallbacks)