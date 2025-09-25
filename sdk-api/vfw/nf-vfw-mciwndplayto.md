# MCIWndPlayTo macro

## Syntax

```cpp
LONG MCIWndPlayTo(
     hwnd,
     lPos
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndPlayTo** macro plays the content of an MCI device from the current position to the specified ending location or until another command stops playback. If the specified ending location is beyond the end of the content, playback stops at the end of the content. You can use this macro or explicitly send the [MCIWNDM_PLAYTO](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-playto) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lPos`

Ending location. The units for the ending location depend on the current time format.

## Remarks

You can also specify both a starting and ending location for playback by using the [MCIWndPlayFromTo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndplayfromto) macro.