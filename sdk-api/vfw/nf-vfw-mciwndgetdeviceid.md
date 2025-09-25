# MCIWndGetDeviceID macro

## Syntax

```cpp
UINT MCIWndGetDeviceID(
     hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the device identifier.

## Description

The **MCIWndGetDeviceID** macro retrieves the identifier of the current MCI device to use with the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function. You can use this macro or explicitly send the [MCIWNDM_GETDEVICEID](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getdeviceid) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETDEVICEID](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getdeviceid)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))