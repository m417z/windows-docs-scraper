# EndPanningFeedback function

## Description

Terminates any existing animation that was in process or set up by [BeginPanningFeedback](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginpanningfeedback) and [UpdatePanningFeedback](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-updatepanningfeedback).

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle to the target window that will receive feedback.

### `fAnimateBack` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag that indicates whether the displaced window should return to the original position using animation. If **FALSE**, the method restore the moved window using a direct jump.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if successful.

## Remarks

This function can only be called after a [BeginPanningFeedback](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginpanningfeedback) call.