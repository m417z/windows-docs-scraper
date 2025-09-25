# IDirectInputEffectDriver::GetEffectStatus

## Description

The **IDirectInputEffectDriver::GetEffectStatus**  method obtains information about the status of an effect.

## Parameters

### `unnamedParam1`

Indicates the external joystick number being addressed.

### `unnamedParam2`

Specifies the effect to be queried.

### `unnamedParam3`

Points to a **DWORD**  that receives the effect status. The **DWORD** should be filled in with one of the following values:

#### DIEGES_PLAYING

The effect is still playing.

#### 0

The effect is not playing.

## Return value

Returns S_OK if successful; otherwise, returns an error code.