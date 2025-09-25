# MCIWndPutSource macro

## Syntax

```cpp
LONG MCIWndPutSource(
     hwnd,
     prc
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndPutSource** macro redefines the coordinates of the source rectangle used for cropping the images of an AVI file during playback. You can use this macro or explicitly send the [MCIWNDM_PUT_SOURCE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-put-source) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `prc`

Pointer to a RECT structure containing the coordinates of the source rectangle.