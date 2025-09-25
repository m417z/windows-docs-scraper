# MCIWndGetEnd macro

## Syntax

```cpp
LONG MCIWndGetEnd(
     hwnd
);
```

## Return value

Type: **LONG**

Returns the location in the current time format.

## Description

The **MCIWndGetEnd** macro retrieves the location of the end of the content of an MCI device or file. You can use this macro or explicitly send the [MCIWNDM_GETEND](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getend) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETEND](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getend)