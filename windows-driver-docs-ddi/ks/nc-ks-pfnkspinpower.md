## Description

An AVStream minidriver's *AVStrMiniPinPower* routine is called for pin-centric pins when the device is waking or entering a sleep state.

## Parameters

### `Pin` [in]

Points to a pin-centric [**KSPIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which to register the callback.

### `State` [in]

Specifies the device power state being requested. Set this parameter to one of the following **DEVICE_POWER_STATE** enumeration values: **PowerDeviceD0**, **PowerDeviceD1**, **PowerDeviceD2**, or **PowerDeviceD3**.

## Remarks

> [!WARNING]
> Do not attempt to obtain the filter control mutex from within either the Sleep or Wake callback. Doing so induces a risk of deadlock. For more information about mutexes, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

The minidriver specifies an address for routines of this type in the *Sleep* and/or *Wake* parameters of the [KsPinRegisterPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterpowercallbacks) routine.

## See also

[KsFilterRegisterPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterregisterpowercallbacks)

[KsPinRegisterPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterpowercallbacks)