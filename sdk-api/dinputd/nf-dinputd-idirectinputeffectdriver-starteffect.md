# IDirectInputEffectDriver::StartEffect

## Description

The **IDirectInputEffectDriver::StartEffect** method begins the playback of an effect. If the effect is already playing, it is restarted from the beginning.

## Parameters

### `unnamedParam1`

Identifies the external joystick number being addressed

### `unnamedParam2`

Specifies the effect to be played.

### `unnamedParam3`

Specifies how the effect is to affect other effects. Only the mode listed below can be used; all other modes are reserved. For example, the driver never receives the DIES_NODOWNLOAD flag because it is managed by DirectInput and not the driver. This parameter can be zero, one, or more of the following flags:

#### DIES_SOLO

Indicates that all other effects on the device should be stopped before the specified effect is played. If this flag is omitted, the effect is mixed with existing effects that have already started on the device.

### `unnamedParam4`

Specifies the number of times to perform the effect. If the value is INFINITE, then the effect should be repeated until explicitly stopped or paused.

## Return value

Returns S_OK if successful; otherwise, returns an error code.