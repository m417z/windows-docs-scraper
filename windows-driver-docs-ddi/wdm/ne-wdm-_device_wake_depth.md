# _DEVICE_WAKE_DEPTH enumeration

## Description

The **DEVICE_WAKE_DEPTH** enumeration specifies the deepest device power state from which a device can trigger a wake signal.

## Constants

### `DeviceWakeDepthNotWakeable`

There is no device power state that can trigger a wake signal.

### `DeviceWakeDepthD0`

D0 is the deepest device power state from which the device can trigger a wake signal. For more information, see Remarks.

### `DeviceWakeDepthD1`

D1 is the deepest low-power device power state from which the device can trigger a wake signal.

### `DeviceWakeDepthD2`

D2 is the deepest low-power device power state from which the device can trigger a wake signal.

### `DeviceWakeDepthD3hot`

D3hot is the deepest low-power device power state from which the device can trigger a wake signal.

### `DeviceWakeDepthD3cold`

D3cold is the deepest low-power device power state from which the device can trigger a wake signal.

### `DeviceWakeDepthMaximum`

Reserved for use by the operating system.

## Remarks

The *DeepestWakeableDstate* parameter of the [GetIdleWakeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_idle_wake_info) routine is a pointer to a variable of type **DEVICE_WAKE_DEPTH**.

The drivers for most devices have no reason to arm a wake signal when the device is in D0. These drivers can treat the **DeviceWakeDepthD0** output value as equivalent to a call to the *GetIdleWakeInfo* routine that fails and returns an error status.

## See also

[GetIdleWakeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_idle_wake_info)