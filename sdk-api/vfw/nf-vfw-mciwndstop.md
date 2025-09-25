# MCIWndStop macro

## Syntax

```cpp
LONG MCIWndStop(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndStop** macro stops playing or recording the content of the MCI device associated with the MCIWnd window. You can use this macro or explicitly send the [MCI_STOP](https://learn.microsoft.com/windows/desktop/Multimedia/mci-stop) command.

## Parameters

### `hwnd`

Handle of the MCIWnd window.