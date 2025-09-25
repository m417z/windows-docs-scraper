# MCIWndCanSave macro

## Syntax

```cpp
BOOL MCIWndCanSave(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the device supports saving data or **FALSE** otherwise.

## Description

The **MCIWndCanSave** macro determines if an MCI device can save data. You can use this macro or explicitly send the [MCIWNDM_CAN_SAVE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-save) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_CAN_SAVE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-save)