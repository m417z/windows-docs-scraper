# MCIWndGetZoom macro

## Syntax

```cpp
UINT MCIWndGetZoom(
     hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the most recent values used with [MCIWndSetZoom](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndsetzoom). A return value of 100 indicates the image is not zoomed. A value of 200 indicates the image is enlarged to twice its original size. A value of 50 indicates the image is reduced to half its original size.

## Description

The **MCIWndGetZoom** macro retrieves the current zoom value used by an MCI device. You can use this macro or explicitly send the [MCIWNDM_GETZOOM](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getzoom) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETZOOM](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getzoom)

[MCIWndSetZoom](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndsetzoom)