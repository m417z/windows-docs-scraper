# BP_ANIMATIONPARAMS structure

## Description

Defines animation parameters for the [BP_PAINTPARAMS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-bp_paintparams) structure used by [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

## Members

### `cbSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of this structure.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved.

### `style`

Type: **[BP_ANIMATIONSTYLE](https://learn.microsoft.com/windows/desktop/api/uxtheme/ne-uxtheme-bp_animationstyle)**

Animation style.

### `dwDuration`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of the animation, in milliseconds.