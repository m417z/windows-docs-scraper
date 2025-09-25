# Animate_Stop macro

## Syntax

```cpp
BOOL Animate_Stop(
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Stops playing an AVI clip in an animation control. You can use this macro or send the [ACM_STOP](https://learn.microsoft.com/windows/desktop/Controls/acm-stop) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the animation control.