# ISnapinAbout::GetSnapinImage

## Description

The **ISnapinAbout::GetSnapinImage** method enables the console to obtain the snap-in's main icon to be used in the About box.

## Parameters

### `hAppIcon` [out]

A pointer to the handle to the main icon of the snap-in that is to be used in the About property page.

## Return value

This method can return one of these values.

## Remarks

For bitmaps, MMC requires a specific background color so it can generate a transparency mask. Icons, however, have built-in transparency so MMC does not require a specific background color.

MMC creates a copy of the returned icon. The snap-in can free the icon when the
ISnapinAbout interface is released.

## See also

[ISnapinAbout](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-isnapinabout)