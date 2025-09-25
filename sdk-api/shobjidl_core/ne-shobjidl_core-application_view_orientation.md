# APPLICATION_VIEW_ORIENTATION enumeration

## Description

Defines the set of display orientation modes for a window (app view). Used by [IApplicationDesignModeSettings2::GetApplicationViewOrientation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings2-getapplicationvieworientation) and
[IApplicationDesignModeSettings2::SetApplicationViewOrientation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings2-setapplicationvieworientation).

## Constants

### `AVO_LANDSCAPE:0`

The window is in landscape orientation, with the display width greater than the height.

### `AVO_PORTRAIT`

The window is in portrait orientation, with the display height greater than the width.

## See also

[IApplicationDesignModeSettings2::GetApplicationViewOrientation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings2-getapplicationvieworientation)

[IApplicationDesignModeSettings2::SetApplicationViewOrientation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings2-setapplicationvieworientation)