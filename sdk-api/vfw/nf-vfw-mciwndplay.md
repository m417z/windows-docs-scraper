# MCIWndPlay macro

## Syntax

```cpp
LONG MCIWndPlay(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndPlay** macro sends a command to an MCI device to start playing from the current position in the content. You can use this macro or explicitly send the [MCI_PLAY](https://learn.microsoft.com/windows/desktop/Multimedia/mci-play) command.

## Parameters

### `hwnd`

Handle of the MCIWnd window.