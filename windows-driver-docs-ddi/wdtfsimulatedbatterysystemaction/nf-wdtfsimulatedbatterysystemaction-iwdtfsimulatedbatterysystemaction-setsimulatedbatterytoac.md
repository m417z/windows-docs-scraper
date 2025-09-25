# IWDTFSimulatedBatterySystemAction::SetSimulatedBatteryToAC

## Description

Sets the simulated battery status to AC power.

Use this method to set the simulated battery status to AC power. If
real batteries in the system are disabled, this sets the OS status and
policy to AC power. This is useful for testing software behavior that
changes depending on the AC/DC state.

## Parameters

### `pbSuccess` [out, retval]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.