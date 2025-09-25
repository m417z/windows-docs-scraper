# IDirectDrawSurface7::Initialize

## Description

Initializes a DirectDrawSurface object.

## Parameters

### `unnamedParam1` [in]

A pointer to the DirectDraw object to associate with the DirectDrawSurface object.

### `unnamedParam2` [in]

A pointer to a [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure that describes how to initialize this surface.

## Return value

This method returns DDERR_ALREADYINITIALIZED.

This method is provided for compliance with the Component Object Model (COM). Because the DirectDrawSurface object is initialized when it is created, this method always returns DDERR_ALREADYINITIALIZED.

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)