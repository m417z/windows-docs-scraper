# IWDTFSimulatedBatterySystemAction::DisableRealBatteries

## Description

Disables real batteries if they are present in the system.

Use this method to disable real batteries if they are present in the
system. If no real batteries are present, this method does nothing. This
method should be called before calling methods that change the simulated
battery state, otherwise the state changes might not have the desired
effect on OS or software behavior.

## Parameters

### `pbSuccess` [out, retval]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.