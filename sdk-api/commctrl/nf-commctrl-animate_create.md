# Animate_Create macro

## Syntax

```cpp
HWND Animate_Create(
   HWND      hwndP,
   UINT      id,
   DWORD     dwStyle,
   HINSTANCE hInstance
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the animation control.

## Description

Creates an animation control. **Animate_Create** calls the [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) function to create the animation control.

## Parameters

### `hwndP`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the parent window.

### `id`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The child window identifier of the animation control.

### `dwStyle`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The window styles. For a list of the animation control style values, see [Animation Control Styles](https://learn.microsoft.com/windows/desktop/Controls/animation-control-styles).

### `hInstance`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the instance of the module that is creating the animation control.

## Remarks

The **Animate_Create** macro sets the width and height of the animation control to zero if the [ACS_CENTER](https://learn.microsoft.com/windows/desktop/Controls/animation-control-styles) style is specified. If the **ACS_CENTER** style is not specified, **Animate_Create** sets the width and height based on the dimensions of a frame in the AVI clip.