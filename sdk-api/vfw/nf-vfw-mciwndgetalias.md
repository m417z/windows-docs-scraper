# MCIWndGetAlias macro

## Syntax

```cpp
UINT MCIWndGetAlias(
     hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the device alias.

## Description

The **MCIWndGetAlias** macro retrieves the alias used to open an MCI device or file with the [mciSendString](https://learn.microsoft.com/previous-versions/dd757161(v=vs.85)) function. You can use this macro or explicitly send the [MCIWNDM_GETALIAS](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getalias) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETALIAS](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getalias)