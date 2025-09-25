## Description

The KsPinRegisterPowerCallbacks function registers power management callbacks for *Pin*.

## Parameters

### `Pin` [in]

A pointer to the [**KSPIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which to register power callbacks. Note that the pin must actually process (be pin-centric) in order to receive power notification messages.

### `Sleep` [in, optional]

This parameter supplies the address of a [AVStrMiniPinPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinpower) function that handles sleep requests for the device. Optional.

### `Wake` [in, optional]

This parameter supplies the address of a [AVStrMiniPinPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinpower) function that handles wake requests for the device. Optional.

## Remarks

> [!WARNING]
> Do not attempt to obtain the filter control mutex from within either the Sleep or Wake callback, or deadlock may occur. For more information about mutexes, read [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

At least one of the callbacks must be specified when calling KsPinRegisterPowerCallbacks.

## See also

[AVStrMiniPinPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinpower)

[KsFilterRegisterPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterregisterpowercallbacks)