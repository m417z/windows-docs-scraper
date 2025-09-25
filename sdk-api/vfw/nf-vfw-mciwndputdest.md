# MCIWndPutDest macro

## Syntax

```cpp
LONG MCIWndPutDest(
     hwnd,
     prc
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndPutDest** macro redefines the coordinates of the destination rectangle used for zooming or stretching the images of an AVI file during playback. You can use this macro or explicitly send the [MCIWNDM_PUT_DEST](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-put-dest) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `prc`

Pointer to a RECT structure containing the coordinates of the destination rectangle.