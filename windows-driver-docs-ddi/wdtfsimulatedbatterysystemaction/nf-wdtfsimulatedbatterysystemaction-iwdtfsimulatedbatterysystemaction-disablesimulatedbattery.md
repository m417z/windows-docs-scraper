# IWDTFSimulatedBatterySystemAction::DisableSimulatedBattery

## Description

Disables the simulated battery.

Use this method is used to disable the simulated battery (uninstalls simulated
battery device). This does not restore the system to its original state, the [WDTFSimulatedBatterySystemAction::EnableRealBatteries](https://learn.microsoft.com/windows-hardware/drivers/ddi/) method must also be called.

## Parameters

### `pbSuccess` [out, retval]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

[WDTFSimulatedBatterySystemAction::EnableRealBatteries](https://learn.microsoft.com/windows-hardware/drivers/ddi/)