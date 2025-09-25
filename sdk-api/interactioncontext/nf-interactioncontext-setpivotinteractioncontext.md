# SetPivotInteractionContext function

## Description

Sets the center point, and the pivot radius from the center point, for a rotation manipulation using a single input pointer.

## Parameters

### `interactionContext` [in]

Pointer to a handle for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

### `x` [in]

The x-coordinate for the screen location of the center point.

### `y` [in]

The y-coordinate for the screen location of the center point.

### `radius` [in]

The offset between the center point and the single input pointer, in HIMETRIC units.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## See also