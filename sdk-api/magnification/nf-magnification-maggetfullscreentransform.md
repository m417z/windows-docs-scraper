# MagGetFullscreenTransform function

## Description

Retrieves the magnification settings for the full-screen magnifier.

## Parameters

### `pMagLevel` [out]

Type: **float***

The current magnification factor for the full-screen magnifier. A value of 1.0 indicates that the screen content is not being magnified. A value above 1.0 indicates the scale factor for magnification. A value less than 1.0 is not valid.

### `pxOffset` [out]

Type: **int***

The x-coordinate offset for the upper-left corner of the unmagnified view. The offset is relative to the upper-left corner of the primary monitor, in unmagnified coordinates.

### `pyOffset` [out]

Type: **int***

The y-coordinate offset for the upper-left corner of the unmagnified view. The offset is relative to the upper-left corner of the primary monitor, in unmagnified coordinates.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns TRUE if successful, or FALSE otherwise.

## Remarks

The offsets are not affected by the current dots per inch (dpi) setting.

#### Examples

The following code snippet retrieves the magnification value and offsets for the full-screen magnifier.

```cpp
    // Get the current magnification level and offset.
    float  magLevel;
    int    xOffset, yOffset;

    if (!MagGetFullscreenTransform(&magLevel, &xOffset, &yOffset))
    {
        return E_FAIL;
    }

    //
    // Do something with the magnification settings.
    //

```

## See also

[MagSetFullscreenTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetfullscreentransform)