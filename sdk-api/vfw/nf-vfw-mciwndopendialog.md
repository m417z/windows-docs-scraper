# MCIWndOpenDialog macro

## Syntax

```cpp
LONG MCIWndOpenDialog(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndOpenDialog** macro opens a user-specified data file and corresponding type of MCI device, and associates them with an MCIWnd window. This macro displays the Open dialog box for the user to select the data file to associate with an MCI window. You can use this macro or explicitly send the [MCIWNDM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-open) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.