# IWDTFSimulatedBatterySystemAction::EnableRealBatteries

## Description

Enables real batteries if they are present in the system.

Use this method to enable real batteries if they are present in the
system. If no real batteries are present, this method does nothing. This
method should be called when disabling the simulated battery in order to return the system to its original state.

## Parameters

### `pbSuccess` [out, retval]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.