# MCIWndGetLength macro

## Syntax

```cpp
UINT MCIWndGetLength(
     hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the length. The units for the length depend on the current time format.

## Description

The **MCIWndGetLength** macro retrieves the length of the content or file currently used by an MCI device. You can use this macro or explicitly send the [MCIWNDM_GETLENGTH](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getlength) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## Remarks

This value added to the value returned for the [MCIWndGetStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndgetstart) macro equals the end of the content.

## See also

[MCIWNDM_GETLENGTH](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getlength)

[MCIWndGetStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndgetstart)