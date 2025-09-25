# DESKTOP_WALLPAPER_POSITION enumeration

## Description

Specifies how the desktop wallpaper should be displayed.

## Constants

### `DWPOS_CENTER:0`

Center the image; do not stretch. This is equivalent to the [WPSTYLE_CENTER](https://learn.microsoft.com/windows/desktop/shell/iactivedesktop-flags) style in [IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop).

### `DWPOS_TILE:1`

Tile the image across all monitors. This is equivalent to the [WPSTYLE_TILE](https://learn.microsoft.com/windows/desktop/shell/iactivedesktop-flags) style in [IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop).

### `DWPOS_STRETCH:2`

Stretch the image to exactly fit on the monitor. This is equivalent to the [WPSTYLE_STRETCH](https://learn.microsoft.com/windows/desktop/shell/iactivedesktop-flags) style in [IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop).

### `DWPOS_FIT:3`

Stretch the image to exactly the height or width of the monitor without changing its aspect ratio or cropping the image. This can result in [colored letterbox bars](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getbackgroundcolor) on either side or on above and below of the image. This is equivalent to the [WPSTYLE_KEEPASPECT](https://learn.microsoft.com/windows/desktop/shell/iactivedesktop-flags) style in [IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop).

### `DWPOS_FILL:4`

Stretch the image to fill the screen, cropping the image as necessary to avoid letterbox bars. This is equivalent to the [WPSTYLE_CROPTOFIT](https://learn.microsoft.com/windows/desktop/shell/iactivedesktop-flags) style in [IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop).

### `DWPOS_SPAN:5`

Spans a single image across all monitors attached to the system. This flag has no [IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop) equivalent.

## See also

[IDesktopWallpaper::GetPosition](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getposition)

[IDesktopWallpaper::SetPosition](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-setposition)