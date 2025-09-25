# MCIWndGetStart macro

## Syntax

```cpp
LONG MCIWndGetStart(
     hwnd
);
```

## Return value

Type: **LONG**

Returns the location in the current time format. Typically, the return value is zero; but some devices use a nonzero starting location. Seeking to this location sets the device to the start of the media.

## Description

The **MCIWndGetStart** macro retrieves the location of the beginning of the content of an MCI device or file. You can use this macro or explicitly send the [MCIWNDM_GETSTART](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getstart) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETSTART](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getstart)