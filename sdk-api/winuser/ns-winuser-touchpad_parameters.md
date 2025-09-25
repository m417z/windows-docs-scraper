# TOUCHPAD_PARAMETERS structure

## Description

Contains user touchpad settings and system information related to all detected touchpads.

> [!NOTE]
> The term "touchpad" refers to Precision Touchpads. The term "legacy touchpad" refers to older generation touchpads that report themselves to Windows as a mouse.

## Members

### `versionNumber`

The version of the struct.

Caller must set to TOUCHPAD_PARAMETERS_LATEST_VERSION to use the latest version, or to TOUCHPAD_PARAMETERS_VERSION_[#] to use a specific version (). The version must be specified when both reading and writing settings.

> [!NOTE]
> TOUCHPAD_PARAMETERS_VERSION_1 is the only specific version of TOUCHPAD_PARAMETERS_VERSION_[#] currently defined.

### `maxSupportedContacts`

The maximum number of simultaneous contacts (for the touchpad that supports the most) amongst all detected touchpads.1

### `legacyTouchpadFeatures`

The supported features reported by detected legacy touchpads. This will be [LEGACY_TOUCHPAD_FEATURE_NONE](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-legacy_touchpad_features) if no legacy touchpads are detected, or if the legacy touchpads do not support configuration through *SPI_SETTOUCHPADPARAMETERS*.1

### `touchpadPresent`

A Precision Touchpad is detected.1

### `legacyTouchpadPresent`

A legacy touchpad is detected.1

### `externalMousePresent`

An external mouse is detected. See [Precision touchpad tuning](https://learn.microsoft.com/windows-hardware/design/component-guidelines/touchpad-tuning-guidelines) for information on exempting a mouse from being considered as external (for the purposes of this status field and behavior of the *allowActiveWhenMousePresent* setting).1

### `touchpadEnabled`

Touchpad input is enabled.1

### `touchpadActive`

Touchpad input is active. It is active if it is enabled, and either there is no external mouse detected or touchpad input has been configured to stay active despite the presence of an external mouse. This field does not indicate whether any touchpad is actively producing input.1

### `feedbackSupported`

A detected touchpad supports haptic feedback.1

### `clickForceSupported`

A detected touchpad supports haptic click force.1

### `Reserved1`

### `allowActiveWhenMousePresent`

Touchpad input can remain active if an external mouse is detected. When inactive, any input produced by a touchpad is ignored.2

### `feedbackEnabled`

Haptic feedback is enabled on touchpads if supported.2

### `tapEnabled`

Single-finger taps are enabled.2

### `tapAndDragEnabled`

Tap-and-drag is enabled.2

### `twoFingerTapEnabled`

Two-finger tap is enabled.2

### `rightClickZoneEnabled`

Pressing the bottom-right corner of the touchpad results in a right-click instead of a left click.2

If the user has swapped their left and right mouse buttons ([GetSystemMetrics(SM_SWAPBUTTON)](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getsystemmetrics) is true), the right-click zone is mirrored horizontally to the bottom-left corner of the touchpad.

### `mouseAccelSettingHonored`

Mouse motion produced by the touchpad honors the user's mouse acceleration setting (specified by [SystemParametersInfo(SPI_GETMOUSE)](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfoa)). If false, the mouse motion always has acceleration applied.2

### `panEnabled`

Two-finger panning is enabled.2

### `zoomEnabled`

Two-finger zooming is enabled.2

### `scrollDirectionReversed`

The direction content scrolls with two-finger panning is reversed. By default, the upward motion of contacts on the touchpad results in content scrolling downward while leftward motion of contacts results in content scrolling rightwards.2

### `Reserved2`

### `sensitivityLevel`

The touchpad sensitivity level. The more sensitive the touchpad, the less suppression of mouse input generation occurs after keyboard activity (see [TOUCHPAD_SENSITIVITY_LEVEL enumeration](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-touchpad_sensitivity_level)).2

### `cursorSpeed`

The rate at which the mouse motion produced by the touchpad moves the cursor. Valid values are 1-20, inclusive.2

### `feedbackIntensity`

The relative intensity of the touchpad's haptic feedback (if supported). Valid values are 0-100, inclusive.2

### `clickForceSensitivity`

The relative sensitivity of the touchpad's haptic click detection (if supported). Valid values are 0-100, inclusive.2

### `rightClickZoneWidth`

The relative width of the touchpad right-click zone. Valid values are 0-100, inclusive. If non-zero, this value overrides the device configuration.2

### `rightClickZoneHeight`

The relative height of the touchpad right-click zone. Valid values are 0-100, inclusive. If non-zero, this value overrides the device configuration.2

## Remarks

All fields apply only to Precision Touchpads, with the exception of fields that specify "legacy touchpad" or are supported by the legacy touchpad as indicated by the *legacyTouchpadFeatures* field.

1 Represents the system information that can be used to help inform which user settings are applicable to the current device. They are ignored when calling SystemParametersInfo ([A](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfoa)/[W](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfow)) with SPI_SETTOUCHPADPARAMETERS.

2 Represents user settings. Modifications to these fields will result in changing the user's settings when calling SystemParametersInfo ([A](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfoa)/[W](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfow)) with SPI_SETTOUCHPADPARAMETERS.

## See also

[TOUCHPAD_SENSITIVITY_LEVEL enumeration](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-touchpad_sensitivity_level), [LEGACY_TOUCHPAD_FEATURES enumeration](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-legacy_touchpad_features)