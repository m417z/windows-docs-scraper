# MCIWndPlayFromTo macro

## Syntax

```cpp
LONG MCIWndPlayFromTo(
     hwnd,
     lStart,
     lEnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndPlayFromTo** macro plays a portion of content between specified starting and ending locations. This macro seeks to the specified point to begin playback, then plays the content to the specified ending location. This macro is defined using the [MCIWndSeek](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndseek) and [MCIWndPlayTo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndplayto) macros, which in turn use the [MCI_SEEK](https://learn.microsoft.com/windows/desktop/Multimedia/mci-seek) command and the [MCIWNDM_PLAYTO](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-playto) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lStart`

Position to seek; it is also the starting location.

### `lEnd`

Ending location.

## Remarks

The units for the seek position depend on the current time format.