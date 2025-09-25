# MCIWndSaveDialog macro

## Syntax

```cpp
LONG MCIWndSaveDialog(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndSaveDialog** macro saves the content currently used by an MCI device. This macro displays the Save dialog box to let the user select a filename to store the content. You can use this macro or explicitly send the [MCI_SAVE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-save) command.

## Parameters

### `hwnd`

Handle of the MCIWnd window.