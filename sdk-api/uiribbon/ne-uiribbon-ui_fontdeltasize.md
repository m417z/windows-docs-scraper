# UI_FONTDELTASIZE enumeration

## Description

Specifies values that identify whether the font size of a highlighted text run should be incremented or decremented.

## Constants

### `UI_FONTDELTASIZE_GROW:0`

Increment the font size.

### `UI_FONTDELTASIZE_SHRINK:1`

Decrement the font size.

## Remarks

When you highlight a run of heterogeneously sized text, the Ribbon framework sets the **Font size** control to blank. When you click the **Font grow** button or the **Font shrink** button, the highlighted text is resized, and the relative size variations in the text run are maintained.

The following screen shot shows the **Font grow** and **Font shrink** buttons on the [FontControl](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-fontcontrol).

![Screen shot of the Font grow and Font shrink buttons on the FontControl.](https://learn.microsoft.com/windows/win32/api/uiribbon/images/FontControl_IncDec.png)

## See also

[Constants and Enumerations](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-enumerations)

[UI_PKEY_FontProperties_DeltaSize](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties-uipkey-fontproperties-deltasize)