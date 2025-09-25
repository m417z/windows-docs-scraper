# MCIWndGetRepeat macro

## Syntax

```cpp
BOOL MCIWndGetRepeat(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if continuous playback is activated or **FALSE** otherwise.

## Description

The **MCIWndGetRepeat** macro determines if continuous playback has been activated. You can use this macro or explicitly send the [MCIWNDM_GETREPEAT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getrepeat) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETREPEAT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getrepeat)