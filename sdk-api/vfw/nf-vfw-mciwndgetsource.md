# MCIWndGetSource macro

## Syntax

```cpp
LONG MCIWndGetSource(
     hwnd,
     prc
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndGetSource** macro retrieves the coordinates of the source rectangle used for cropping the images of an AVI file during playback. You can use this macro or explicitly send the [MCIWNDM_GET_SOURCE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-get-source) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `prc`

Pointer to a RECT structure to contain the coordinates of the source rectangle.

## See also

[MCIWNDM_GET_SOURCE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-get-source)