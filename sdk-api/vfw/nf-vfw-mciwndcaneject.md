# MCIWndCanEject macro

## Syntax

```cpp
BOOL MCIWndCanEject(
    HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the device can eject its media or **FALSE** otherwise.

## Description

The **MCIWndCanEject** macro determines if an MCI device can eject its media. You can use this macro or explicitly send the [MCIWNDM_CAN_EJECT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-eject) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_CAN_EJECT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-eject)