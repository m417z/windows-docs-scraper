# MCIWndGetDest macro

## Syntax

```cpp
UINT MCIWndGetDest(
     hwnd,
     prc
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndGetDest** macro retrieves the coordinates of the destination rectangle used for zooming or stretching the images of an AVI file during playback. You can use this macro or explicitly send the [MCIWNDM_GET_DEST](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-get-dest) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `prc`

Pointer to a RECT structure to return the coordinates of the destination rectangle.

## See also

[MCIWNDM_GET_DEST](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-get-dest)