# WALLPAPEROPT structure

## Description

Contains the wallpaper display options. Used with members of the [IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop) interface.

## Members

### `dwSize`

Type: **DWORD**

The size of this **WALLPAPEROPT** structure.

### `dwStyle`

Type: **DWORD**

The wallpaper style; one of the following values:

#### WPSTYLE_CENTER (0x0)

0x0. Center the wallpaper image in its original size, filling the remaining area with a solid background color if image is smaller than screen or cropping image if image is larger.

#### WPSTYLE_TILE (0x1)

0x1. Tile the wallpaper image, starting in the upper left corner of the screen. This uses the image in its original size.

#### WPSTYLE_STRETCH (0x2)

0x2. Stretch the image to cover the full screen. This can result in distortion of the image as the image's aspect ratio is not retained.

#### WPSTYLE_KEEPASPECT (0x3)

0x3. **Introduced in Windows 7**. Enlarge or shrink the image to fill the screen, retaining the aspect ratio of the original image. If necessary, the image is padded either on the top and bottom or on the right and left with the background color to fill any screen area not covered by the image.

#### WPSTYLE_CROPTOFIT (0x4)

0x4. **Introduced in Windows 7**. Enlarge or shrink the image to fill the screen, retaining the aspect ratio of the original image. If necessary, the image is cropped either on the top and bottom or on the left and right as necessary to fit the screen.

#### WPSTYLE_SPAN (0x5)

0x5. **Introduced in Windows 8**. Spans the wallpaper across multiple monitors.

#### WPSTYLE_MAX

The maximum legitimate value of these flags, used for validation purposes.