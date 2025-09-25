# INERTIA_PARAMETER enumeration

## Description

Specifies the inertia values for a manipulation (translation, rotation, scaling).

## Constants

### `INERTIA_PARAMETER_TRANSLATION_DECELERATION:0x00000001`

The rate of deceleration, in degrees/ms2.

### `INERTIA_PARAMETER_TRANSLATION_DISPLACEMENT:0x00000002`

The relative change in screen location, in DIPs.

### `INERTIA_PARAMETER_ROTATION_DECELERATION:0x00000003`

The rate of deceleration, in degrees/ms2.

### `INERTIA_PARAMETER_ROTATION_ANGLE:0x00000004`

The relative change in angle of rotation, in radians.

### `INERTIA_PARAMETER_EXPANSION_DECELERATION:0x00000005`

The rate of deceleration, in degrees/ms2.

### `INERTIA_PARAMETER_EXPANSION_EXPANSION:0x00000006`

The relative change in size, in pixels.

### `INERTIA_PARAMETER_MAX:0xffffffff`

Maximum number of interactions exceeded.

## See also

[SetInertiaParameterInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setinertiaparameterinteractioncontext)