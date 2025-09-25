# MCIWndPlayReverse macro

## Syntax

```cpp
LONG MCIWndPlayReverse(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndPlayReverse** macro plays the current content in the reverse direction, beginning at the current position and ending at the beginning of the content or until another command stops playback. You can use this macro or explicitly send the [MCIWNDM_PLAYREVERSE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-playreverse) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.