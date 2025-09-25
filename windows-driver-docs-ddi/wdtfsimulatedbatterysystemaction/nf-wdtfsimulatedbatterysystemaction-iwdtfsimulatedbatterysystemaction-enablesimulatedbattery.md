# IWDTFSimulatedBatterySystemAction::EnableSimulatedBattery

## Description

Enables the simulated battery.

 Use this method to enable the simulated battery (installs simulated
battery device). This does not guarantee the ability to simulate DC by
itself, the [IWDTFSimulatedBatterySystemAction::DisableRealBatteries](https://learn.microsoft.com/windows-hardware/drivers/ddi/) method must also be called in order to guarantee a real battery doesn't interfere with the simulation.

## Parameters

### `pbSuccess` [out, retval]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

[IWDTFSimulatedBatterySystemAction::DisableRealBatteries](https://learn.microsoft.com/windows-hardware/drivers/ddi/)