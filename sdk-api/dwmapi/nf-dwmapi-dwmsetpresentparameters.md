# DwmSetPresentParameters function

## Description

Sets the present parameters for frame composition.

**DwmSetPresentParameters** is no longer supported. Starting with Windows 8.1, calls to **DwmSetPresentParameters** always return E_NOTIMPL.

## Parameters

### `hwnd` [in]

The handle to the window where the present parameters are applied.

### `pPresentParams` [in, out]

A pointer to a [DWM_PRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/dwmapi/ns-dwmapi-dwm_present_parameters) structure that contains DWM video frame parameters for frame composition.

## Return value

This function always returns S_OK.