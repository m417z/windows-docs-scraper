# DDGAMMARAMP structure

## Description

The **DDGAMMARAMP** structure contains red, green, and blue ramp data for the [IDirectDrawGammaControl::GetGammaRamp](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawgammacontrol-getgammaramp) and [IDirectDrawGammaControl::SetGammaRamp](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawgammacontrol-setgammaramp) methods.

## Members

### `red`

Array of 256 WORD elements that describe the red gamma ramp.

### `green`

Array of 256 WORD elements that describe the green gamma ramp.

### `blue`

Array of 256 WORD elements that describe the blue gamma ramp.