# MCIWndSave macro

## Syntax

```cpp
LONG MCIWndSave(
     hwnd,
     szFile
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndSave** macro saves the content currently used by an MCI device. This macro can save the content to a specified data file or display the Save dialog box to let the user select a filename to store the content. You can use this macro or explicitly send the [MCI_SAVE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-save) command.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `szFile`

Null-terminated string containing the name and path of the destination file. Specify −1 for this parameter to display the Save dialog box.