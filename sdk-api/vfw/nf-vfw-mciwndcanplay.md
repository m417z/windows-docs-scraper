# MCIWndCanPlay macro

## Syntax

```cpp
BOOL MCIWndCanPlay(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the device supports playing the data or **FALSE** otherwise.

## Description

The **MCIWndCanPlay** macro determines if an MCI device can play a data file or content of some other kind. You can use this macro or explicitly send the [MCIWNDM_CAN_PLAY](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-play) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_CAN_PLAY](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-play)