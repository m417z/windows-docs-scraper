# MCIWndPlayFrom macro

## Syntax

```cpp
LONG MCIWndPlayFrom(
     hwnd,
     lPos
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndPlayFrom** macro plays the content of an MCI device from the specified location to the end of the content or until another command stops playback. You can use this macro or explicitly send the [MCIWNDM_PLAYFROM](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-playfrom) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lPos`

Starting location. The units for the starting location depend on the current time format.

## Remarks

You can also specify both a starting and ending location for playback by using the [MCIWndPlayFromTo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndplayfromto) macro.