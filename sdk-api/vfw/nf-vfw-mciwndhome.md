# MCIWndHome macro

## Syntax

```cpp
LONG MCIWndHome(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndHome** macro moves the current position to the beginning of the content. You can use this macro or explicitly send the [MCI_SEEK](https://learn.microsoft.com/windows/desktop/Multimedia/mci-seek) command.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCI_SEEK](https://learn.microsoft.com/windows/desktop/Multimedia/mci-seek)