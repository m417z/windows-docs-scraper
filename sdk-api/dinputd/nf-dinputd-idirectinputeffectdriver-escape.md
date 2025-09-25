# IDirectInputEffectDriver::Escape

## Description

The **IDirectInputEffectDriver::Escape**  method escapes to the driver. This method is called in response to an application invoking the **IDirectInputEffect::Escape** or **IDirectInputDevice::Escape** methods.

## Parameters

### `unnamedParam1`

Indicates the joystick ID number being used.

### `unnamedParam2`

Specifies the effect at which the command is directed, or zero if the command is directed at the device itself and not any particular effect.

### `unnamedParam3`

Points to a [DIEFFESCAPE](https://learn.microsoft.com/windows/desktop/api/dinput/ns-dinput-dieffescape) structure that describes the command to be sent. On success, the **cbOutBuffer** member contains the number of output buffer bytes actually used.

## Return value

Returns S_OK if successful; otherwise, returns an error code.