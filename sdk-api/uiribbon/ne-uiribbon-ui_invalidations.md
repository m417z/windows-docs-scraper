# UI_INVALIDATIONS enumeration

## Description

Specifies values that identify the aspect of a Command to invalidate.

## Constants

### `UI_INVALIDATIONS_STATE:0x1`

A state property, such as [UI_PKEY_Enabled](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties-uipkey-enabled).

### `UI_INVALIDATIONS_VALUE:0x2`

The value property of a Command.

### `UI_INVALIDATIONS_PROPERTY:0x4`

Any property.

### `UI_INVALIDATIONS_ALLPROPERTIES:0x8`

All properties.

## See also

[Constants and Enumerations](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-enumerations)

[IUIFramework::InvalidateUICommand](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-invalidateuicommand)