# MCIWndSetPalette macro

## Syntax

```cpp
LONG MCIWndSetPalette(
     hwnd,
     hpal
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndSetPalette** macro sends a palette handle to the MCI device associated with the MCIWnd window. You can use this macro or explicitly send the [MCIWNDM_SETPALETTE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-setpalette) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `hpal`

Palette handle.