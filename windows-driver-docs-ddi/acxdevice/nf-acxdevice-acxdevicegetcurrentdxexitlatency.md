## Description

The **AcxDeviceGetCurrentDxExitLatency** function gets the current audio device sleep state exit latency value.

## Parameters

### `Device`

Pointer to the **WDFDEVICE** for which to get the exit latency.

### `SystemPowerAction`

The [system power action](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-actions) for which to get the latency value.

### `DeviceState`

The device [power state](https://learn.microsoft.com/windows-hardware/drivers/nfc/power-states) for which to get the latency value.

## Return value

**AcxDeviceGetCurrentDxExitLatency** returns the current device exit latency value as defined in the [ACX_DX_EXIT_LATENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ne-acxdevice-acx_dx_exit_latency) enumeration.

## Remarks

A device has different power states. The D0 power state is when the device is up and running, D1 is when the device is one of the sleep states, and so on. "Dx" refers to any device sleep state.

Audio drivers know when to go in [D3Hot](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states#d3hot) or [D3Cold](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states#d3cold-substate) based on the [ACX_DX_EXIT_LATENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ne-acxdevice-acx_dx_exit_latency) returned by this method.

### Example

```cpp
WDFDEVICE              Device;
WDF_POWER_DEVICE_STATE TargetState;
ACX_DX_EXIT_LATENCY    latency;
POWER_ACTION           powerAction;

// Code to initialize WDFDEVICE and WDF_POWER_DEVICE_STATE...

powerAction = WdfDeviceGetSystemPowerAction(Device);

//
// Get the current exit latency.
//
latency = AcxDeviceGetCurrentDxExitLatency(Device, powerAction, TargetState);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_DX_EXIT_LATENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ne-acxdevice-acx_dx_exit_latency)
- [System Power Actions](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-actions)
- [Power states](https://learn.microsoft.com/windows-hardware/drivers/nfc/power-states)
- [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)