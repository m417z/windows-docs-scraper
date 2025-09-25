# GetInertiaParameterInteractionContext function

## Description

Gets the inertia behavior of a manipulation (translation, rotation, scaling).

## Parameters

### `interactionContext` [in]

The handle of the interaction context.

### `inertiaParameter` [in]

One of the constants from [INERTIA_PARAMETER enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-inertia_parameter).

### `value` [out]

The value of *inertiaParameter*. This value is one of the following:

- The rate of deceleration, in radians/ms2.
- For translation, the relative change in screen location, in HIMETRIC units.
- For rotation, the relative change in angle of rotation, in radians
- For scaling, the relative change in size, in HIMETRIC units.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## See also

[SetInertiaParameterInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setinertiaparameterinteractioncontext)