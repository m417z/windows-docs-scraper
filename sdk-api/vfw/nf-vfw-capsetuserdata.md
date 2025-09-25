# capSetUserData macro

## Syntax

```cpp
BOOL capSetUserData(
     hwnd,
     lUser
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if streaming capture is in progress.

## Description

The **capSetUserData** macro associates a **LONG_PTR** data value with a capture window. You can use this macro or explicitly call the [WM_CAP_SET_USER_DATA](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-user-data) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `lUser`

Data value to associate with a capture window.

## Remarks

Typically this message is used to point to a block of data associated with a capture window.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)