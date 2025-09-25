# APPLICATION_VIEW_STATE enumeration

## Description

Indicates the current view state of a Windows Store app. Used by [IApplicationDesignModeSettings::SetApplicationViewState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings-setapplicationviewstate) and [IApplicationDesignModeSettings::IsApplicationViewStateSupported](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings-isapplicationviewstatesupported).

## Constants

### `AVS_FULLSCREEN_LANDSCAPE:0`

The current app's view is full-screen (has no snapped app adjacent to it), and is in landscape orientation.

### `AVS_FILLED`

The current app's view has been reduced to a partial screen view as the result of another app snapping (being docked at one side of the screen in a narrow view).

### `AVS_SNAPPED`

The current app's view has been snapped (docked at one side of the screen in a narrow view).

### `AVS_FULLSCREEN_PORTRAIT`

The current app's view is full-screen (has no snapped app adjacent to it), and is in portrait orientation.

## See also

[IApplicationDesignModeSettings::IsApplicationViewStateSupported](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings-isapplicationviewstatesupported)

[IApplicationDesignModeSettings::SetApplicationViewState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdesignmodesettings-setapplicationviewstate)