# SetInertiaParameterInteractionContext function

## Description

Configures the inertia behavior of a manipulation (translation, rotation, scaling) after the contact is lifted.

## Parameters

### `interactionContext` [in]

The handle of the interaction context.

### `inertiaParameter` [in]

One of the constants from [INERTIA_PARAMETER enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-inertia_parameter).

### `value` [in]

One of the following:

- The rate of deceleration, in radians/ms2.
- For translation, the relative change in screen location, in HIMETRIC units.
- For rotation, the relative change in angle of rotation, in radians.
- For scaling, the relative change in size, in HIMETRIC units.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## Remarks

[Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) uses the inertia system setting for all manipulations (translation, rotation, scaling). This function overrides the system setting.

To restore the system setting, set *value* to INERTIA_PARAMETER_INVALID_VALUE (FLT_MAX).

## See also

[GetInertiaParameterInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-getinertiaparameterinteractioncontext)