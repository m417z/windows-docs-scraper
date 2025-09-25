# BeginPanningFeedback function

## Description

Notifies the system to send feedback about a target window affected by panning gestures.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle to the target window that will receive feedback.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

TRUE, if successful.

## Remarks

This function must be called before either the [UpdatePanningFeedback](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-updatepanningfeedback) or [EndPanningFeedback](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-endpanningfeedback) functions can be called.