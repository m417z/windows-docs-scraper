# MCIWndClose macro

## Syntax

```cpp
LONG MCIWndClose(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero.

## Description

The **MCIWndClose** macro closes an MCI device or file associated with an MCIWnd window. Although the MCI device closes, the MCIWnd window is still open and can be associated with another MCI device. You can use this macro or explicitly send the [MCI_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-close) command.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCI_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-close)