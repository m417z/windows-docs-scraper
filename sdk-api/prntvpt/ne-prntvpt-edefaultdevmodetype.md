# EDefaultDevmodeType enumeration

## Description

Enables users to specify which [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) to use as the source of default values when a print ticket does not specify all possible settings.

## Constants

### `kUserDefaultDevmode`

The user's default preferences.

### `kPrinterDefaultDevmode`

The print queue's default preferences.

## Remarks

If user defaults are not available when using kUserDefaultDevmode, queue defaults will be used.