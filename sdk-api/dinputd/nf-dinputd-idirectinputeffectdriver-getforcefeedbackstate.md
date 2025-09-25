# IDirectInputEffectDriver::GetForceFeedbackState

## Description

The **IDirectInputEffectDriver::GetForceFeedbackState**  method retrieves the force-feedback state for the device.

## Parameters

### `unnamedParam1`

Indicates the external joystick number being addressed.

### `unnamedParam2`

Points to a [DIDEVICESTATE](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-didevicestate) structure that receives the device state. DirectInput sets the **dwSize** member of the DIDEVICESTATE structure to **sizeof**(DIDEVICESTATE) before calling this method.

## Return value

Returns S_OK if successful; otherwise, returns an error code.