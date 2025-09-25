# Animate_IsPlaying macro

## Syntax

```cpp
BOOL Animate_IsPlaying(
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Checks to see if an Audio-Video Interleaved (AVI) clip is playing. You can use this macro or send an [ACM_ISPLAYING](https://learn.microsoft.com/windows/desktop/Controls/acm-isplaying) message.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the animation control.