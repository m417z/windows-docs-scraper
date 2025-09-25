# APPLICATION_VIEW_SIZE_PREFERENCE enumeration

## Description

Defines the set of possible general window (app view) size preferences. Used by [ILaunchSourceViewSizePreference::GetSourceViewSizePreference](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ilaunchsourceviewsizepreference-getsourceviewsizepreference) and [ILaunchTargetViewSizePreference::GetTargetViewSizePreference](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ilaunchtargetviewsizepreference-gettargetviewsizepreference).

## Constants

### `AVSP_DEFAULT:0`

The app does not specify a window size preference. Windows, rather than the app, sets the size preference, which defaults to **AVSP_USE_HALF**.

### `AVSP_USE_LESS:1`

Prefers to use less than 50% of the available horizontal screen pixels.

### `AVSP_USE_HALF:2`

Prefers to use 50% (half) of the available horizontal screen pixels.

### `AVSP_USE_MORE:3`

Prefers to use more than 50% of the available horizontal screen pixels.

### `AVSP_USE_MINIMUM:4`

Prefers to use the minimum horizontal pixel width (either 320 or 500 pixels) specified in the app's manifest.

### `AVSP_USE_NONE:5`

The window has no visible component.

### `AVSP_CUSTOM:6`

## See also

[IApplicationDesignModeSettings2::GetApplicationViewOrientation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings2-getapplicationvieworientation)

[IApplicationDesignModeSettings2::SetApplicationViewOrientation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings2-setapplicationvieworientation)