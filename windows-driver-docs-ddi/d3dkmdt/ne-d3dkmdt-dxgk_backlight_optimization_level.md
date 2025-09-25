# DXGK_BACKLIGHT_OPTIMIZATION_LEVEL enumeration

## Description

Indicates the optimization level of brightness control. Used by Windows Display Driver Model (WDDM) 1.2 and later display miniport drivers that support adaptive brightness control.

## Constants

### `DxgkBacklightOptimizationDisable`

The display miniport driver must completely disable adaptive brightness control.

The operating system always sets this value if the system is on AC power.

### `DxgkBacklightOptimizationDesktop`

The display miniport driver should optimize backlight settings for desktop presentation when the system is on DC power and the other possible scenarios (disabled, dynamic, and dimmed) are not active. This type of optimization is appropriate for displaying photos, internet browsers, common document types, and video playback controls.

This is the default adaptive brightness setting when the system is on DC power.

### `DxgkBacklightOptimizationDynamic`

The display miniport driver should optimize backlight settings for presentation of full-screen video. Typical playback scenarios include playing movies and full-screen video.

The operating system sets this value if a full-screen Windows App is using the HTML5 video tag with JavaScript or the [MediaElement](https://learn.microsoft.com/dotnet/api/system.windows.controls.mediaelement) control with XAML.

The operating system sets this value only when only full-screen video content is displayed on the screen. This value is not set if playback controls or charms are displayed during video playback; in this case, adaptive brightness will not be enabled.

### `DxgkBacklightOptimizationDimmed`

The display miniport driver should optimize backlight settings to display at a low light level that is still visible even if it is not easily readable. In this scenario the display is typically set to a 30 percent brightness level.

After a defined period of no user input, the operating system sets this value to dim the display.

### `DxgkBacklightOptimizationEDR`

Optimization level which informs the driver that the display is being driven with either High Dynamic Range or Enhanced Dynamic Range content so any backlight optimizations can be tailored to the scenario.

## Remarks

For more information on usage scenarios involving **DXGK_BACKLIGHT_OPTIMIZATION_LEVEL** enumeration values, see Remarks in the [**DxgkDdiSetBacklightOptimization**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_backlight_optimization) function.

## See also

[**DxgkDdiSetBacklightOptimization**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_set_backlight_optimization)