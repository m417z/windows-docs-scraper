# DwmGetCompositionTimingInfo function

## Description

Retrieves the current composition timing information for a specified window.

## Parameters

### `hwnd` [in]

The handle to the window for which the composition timing information should be retrieved.

Starting with Windows 8.1, this parameter must be set to **NULL**. If this parameter is not set to **NULL**, **DwmGetCompositionTimingInfo** returns E_INVALIDARG.

### `pTimingInfo` [out]

A pointer to a [DWM_TIMING_INFO](https://learn.microsoft.com/windows/desktop/api/dwmapi/ns-dwmapi-dwm_timing_info) structure that, when this function returns successfully, receives the current composition timing information for the window. The **cbSize** member of this structure must be set before this function is called.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.