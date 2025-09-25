# UpdatePanningFeedback function

## Description

Updates clients about state of a window resulting from a panning gesture. This function can only be called after a [BeginPanningFeedback](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginpanningfeedback) call.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle to the target window that will receive feedback. For the method to succeed, this must be the same HWND as provided in [BeginPanningFeedback](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginpanningfeedback).

### `lTotalOverpanOffsetX` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The total displacement that the window has moved in the horizontal direction since the end of scrollable region was reached. A maximum displacement of 30 pixels is allowed.

### `lTotalOverpanOffsetY` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The total displacement that the window has moved in the vertical direction since the end of scrollable region was reached. A maximum displacement of 30 pixels is allowed.

### `fInInertia` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag indicating whether the application is handling a WM_GESTURE message with the GF_INERTIA FLAG set.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if successful.

## Remarks

Incremental calls to this function should always pass the sum of the increments and not just the latest increment itself.