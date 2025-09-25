# capGetUserData macro

## Syntax

```cpp
LPARAM capGetUserData(
     hwnd
);
```

## Return value

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the value previously saved by using the **capSetUserData** macro.

## Description

The **capGetUserData** macro retrieves a **LONG_PTR** data value associated with a capture window. You can use this macro or explicitly call the [WM_CAP_GET_USER_DATA](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-get-user-data) message.

## Parameters

### `hwnd`

Handle to a capture window.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)