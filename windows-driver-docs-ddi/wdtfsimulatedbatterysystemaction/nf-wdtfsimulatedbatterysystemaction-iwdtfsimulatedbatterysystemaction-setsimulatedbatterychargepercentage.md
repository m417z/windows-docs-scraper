# IWDTFSimulatedBatterySystemAction::SetSimulatedBatteryChargePercentage

## Description

Sets the charge percentage reported to the OS by the simulated battery.

Use this method to change the charge level reported to the OS by the
simulated battery. This is useful for testing software behavior that changes based on the battery charge level.

## Parameters

### `Percent` [in]

Specifies charge level percentage, 0-100.

### `pbSuccess` [out, retval]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.