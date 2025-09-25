# ANIMATIONINFO structure

## Description

Describes the animation effects associated with user actions. This structure is used with the
[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function when the SPI_GETANIMATION or SPI_SETANIMATION action value is specified.

## Members

### `cbSize`

The size of the structure, in bytes. The caller must set this to `sizeof(ANIMATIONINFO)`.

### `iMinAnimate`

If this member is nonzero, minimize and restore animation is enabled; otherwise it is disabled.

## See also

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)