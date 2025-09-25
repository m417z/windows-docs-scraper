# IDirectInputEffectDriver::DestroyEffect

## Description

The **IDirectInputEffectDriver::DestroyEffect**  method removes an effect from the device. If the effect is playing, the driver should stop it before unloading it.

## Parameters

### `unnamedParam1`

Specifies the external joystick number being addressed.

### `unnamedParam2`

Specifies the effect to be destroyed.

## Return value

Returns S_OK if successful; otherwise, returns an error code.