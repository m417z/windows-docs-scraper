# MCIWndCanConfig macro

## Syntax

```cpp
BOOL MCIWndCanConfig(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the device supports configuration or **FALSE** otherwise.

## Description

The **MCIWndCanConfig** macro determines if an MCI device can display a configuration dialog box. You can use this macro or explicitly send the [MCIWNDM_CAN_CONFIG](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-config) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_CAN_CONFIG](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-config)