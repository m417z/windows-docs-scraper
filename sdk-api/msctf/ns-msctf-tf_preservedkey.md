# TF_PRESERVEDKEY structure

## Description

The **TF_PRESERVEDKEY** structure represents a preserved key.

## Members

### `uVKey`

Virtual key code of the keyboard shortcut.

### `uModifiers`

Modifies the preserved key. This can be zero or a combination of one or more of the [TF_MOD_* constants](https://learn.microsoft.com/windows/desktop/TSF/tf-mod--constants).

## Remarks

Preserved keys are registered by TSF text services and provide keyboard shortcuts to common commands implemented by the TSF text service.

## See also

[TF_MOD_* constants](https://learn.microsoft.com/windows/desktop/TSF/tf-mod--constants)