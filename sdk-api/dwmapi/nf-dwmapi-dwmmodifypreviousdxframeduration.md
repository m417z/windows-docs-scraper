# DwmModifyPreviousDxFrameDuration function

## Description

Changes the number of monitor refreshes through which the previous frame will be displayed.

**DwmModifyPreviousDxFrameDuration** is no longer supported. Starting with Windows 8.1, calls to **DwmModifyPreviousDxFrameDuration** always return E_NOTIMPL.

## Parameters

### `hwnd` [in]

The handle to the window for which the new duration is applied to the previous frame.

### `cRefreshes` [in]

The number of refreshes to apply to the previous frame.

### `fRelative` [in]

**TRUE** if the value given in *cRefreshes* is relative to the current value (added to or subtracted from it); **FALSE** if the value replaces the current value.

## Return value

This function always returns S_OK, even when DWM is not running.