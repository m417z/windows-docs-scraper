## Description

The **ACX_DX_EXIT_LATENCY** enum defines values that specify an ACX device's sleep state exit latency.

## Constants

### `AcxDxExitLatencyInstant`

The device is powered up, so the device must be able to respond immediately.

### `AcxDxExitLatencyFast`

The system is in S0 and not in connected standby, so it must be fast when powering up. This value corresponds to the [D3Hot](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states#d3hot) power sub-state.

### `AcxDxExitLatencyResponsive`

The system is entering a sleep state, so the longest exit latency can be tolerated. This value corresponds to the [D3Cold](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states#d3cold-substate) power sub-state.

## Remarks

A device has different power states. The D0 power state is when the device is up and running, D1 is when the device is one of the sleep states, and so on. "Dx" refers to any device sleep state.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

* [AcxDeviceGetCurrentDxExitLatency](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdevicegetcurrentdxexitlatency)
* [System Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-states)
* [PC_EXIT_LATENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-_pc_exit_latency)
* [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)