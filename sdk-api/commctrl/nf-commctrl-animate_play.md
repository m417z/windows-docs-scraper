# Animate_Play macro

## Syntax

```cpp
BOOL Animate_Play(
   HWND hwnd,
   UINT from,
   UINT to,
   UINT rep
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Plays an AVI clip in an animation control. The control plays the clip in the background while the thread continues executing. You can use this macro or send the [ACM_PLAY](https://learn.microsoft.com/windows/desktop/Controls/acm-play) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the animation control in which to play the AVI clip.

### `from`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index of the frame where playing begins. The value must be less than 65,536. A value of zero means begin with the first frame in the AVI clip.

### `to`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index of the frame where playing ends. The value must be less than 65,536. A value of -1 means end with the last frame in the AVI clip.

### `rep`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of times to replay the AVI clip. A value of -1 means replay the clip indefinitely.

## Remarks

You can use [Animate_Seek](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-animate_seek) to direct the animation control to display a particular frame of the AVI clip.