# IDirectDrawPalette::Initialize

## Description

Initializes the DirectDrawPalette object.

## Parameters

### `unnamedParam1` [in]

A pointer to the DirectDraw object to associate with the DirectDrawPalette object.

### `unnamedParam2` [in]

Currently not used and must be set to 0.

### `unnamedParam3` [out]

Currently not used and must be set to NULL.

## Return value

This method returns DDERR_ALREADYINITIALIZED.

This method is provided for compliance with the Component Object Model (COM). Because the DirectDrawPalette object is initialized when it is created, this method always returns DDERR_ALREADYINITIALIZED.

## Remarks

## See also

[IDirectDrawPalette](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawpalette)