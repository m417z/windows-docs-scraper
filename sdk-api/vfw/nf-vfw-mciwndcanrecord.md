# MCIWndCanRecord macro

## Syntax

```cpp
BOOL MCIWndCanRecord(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the device supports recording or **FALSE** otherwise.

## Description

The **MCIWndCanRecord** macro determines if an MCI device supports recording. You can use this macro or explicitly send the [MCIWNDM_CAN_RECORD](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-record) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_CAN_RECORD](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-record)