# MCIWndGetPalette macro

## Syntax

```cpp
HPALETTE MCIWndGetPalette(
     hwnd
);
```

## Return value

Type: **HPALETTE**

Returns the handle of the palette if successful.

## Description

The **MCIWndGetPalette** macro retrieves a handle of the palette used by an MCI device. You can use this macro or explicitly send the [MCIWNDM_GETPALETTE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getpalette) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETPALETTE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getpalette)

[MCIWndGetPalette](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndgetpalette)