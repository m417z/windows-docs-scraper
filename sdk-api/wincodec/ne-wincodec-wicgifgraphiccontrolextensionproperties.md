# WICGifGraphicControlExtensionProperties enumeration

## Description

Specifies the graphic control extension metadata properties that define the transitions between each frame animation for Graphics Interchange Format (GIF) images.

## Constants

### `WICGifGraphicControlExtensionDisposal:0x1`

[VT_UI1] Indicates the disposal requirements. 0 - no disposal, 1 - do not dispose, 2 - restore to background color, 3 - restore to previous.

### `WICGifGraphicControlExtensionUserInputFlag:0x2`

[VT_BOOL] Indicates the user input flag. **TRUE** if user input should advance to the next frame; otherwise, **FALSE**.

### `WICGifGraphicControlExtensionTransparencyFlag:0x3`

[VT_BOOL] Indicates the transparency flag. **TRUE** if a transparent color in is in the color table for this frame; otherwise, **FALSE**.

### `WICGifGraphicControlExtensionDelay:0x4`

[VT_UI2] Indicates how long to display the next frame before advancing to the next frame, in units of 1/100th of a second.

### `WICGifGraphicControlExtensionTransparentColorIndex:0x5`

[VT_UI1] Indicates which color in the palette should be treated as transparent.

### `WICGifGraphicControlExtensionProperties_FORCE_DWORD:0x7fffffff`