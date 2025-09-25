# TTHITTESTINFOA structure

## Description

Contains information that a tooltip control uses to determine whether a point is in the bounding rectangle of the specified tool. If the point is in the rectangle, the structure receives information about the tool.

## Members

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tool or window with the specified tool.

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

Client coordinates of the point to test.

### `ti`

Type: **[TOOLINFO](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa)**

[TOOLINFO](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) structure. If the point specified by
**pt** is in the tool specified by
**hwnd**, this structure receives information about the tool. The
**cbSize** member of this structure must be filled in before sending this message.

## Remarks

This structure is used with the [TTM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/ttm-hittest) message.

> [!NOTE]
> The commctrl.h header defines TTHITTESTINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).