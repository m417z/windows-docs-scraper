# Animate_Seek macro

## Syntax

```cpp
BOOL Animate_Seek(
   HWND hwnd,
   UINT frame
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Directs an animation control to display a particular frame of an AVI clip. The control displays the clip in the background while the thread continues executing. You can use this macro or send the [ACM_PLAY](https://learn.microsoft.com/windows/desktop/Controls/acm-play) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the animation control in which to display the AVI frame.

### `frame`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index of the frame to display.

## See also

[Animate_Play](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-animate_play)