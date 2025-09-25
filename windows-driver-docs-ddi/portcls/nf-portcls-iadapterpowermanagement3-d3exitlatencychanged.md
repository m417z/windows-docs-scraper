# IAdapterPowerManagement3::D3ExitLatencyChanged

## Description

PortCls calls the D3ExitLatencyChanged method while the device is in sleep (D3) power state, to provide a new exit latency value.

## Parameters

### `NewD3ExitLatency` [in]

The [PC_EXIT_LATENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-_pc_exit_latency) enumerated value that Portcls has determined for the device.

## Return value

This method returns an NTSTATUS value.

## Remarks

 The D3ExitLatencyChanged method is only called when the device is the D3 power state. When Portcls wakes the device into D0, it does so via [PowerChangeState3](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/jj200332(v=vs.85)), and the device must be able to exit its sleep state within the latency period indicated by *NewD3ExitLatency*. Waking the audio adapter in this manner allows the driver to use the most appropriate method to adjust the power state of the audio adapter within the time-frame indicated by the *NewD3ExitLatency* value.

The following table shows the possible values for *NewD3ExitLatency*.

| Exit Latency | Meaning |
| --- | --- |
| PcExitLatencyInstant | The driver must wake the audio adapter instantly with no latency. |
| PcExitLatencyFast | The driver must wake the audio adapter within 10 milliseconds. |
| PcExitLatencyResponsive | The driver must wake the audio adapter within 200 milliseconds. |

## See also

[IAdapterPowerManagement3](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement3)

[PC_EXIT_LATENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-_pc_exit_latency)

[PowerChangeState3](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/jj200332(v=vs.85))